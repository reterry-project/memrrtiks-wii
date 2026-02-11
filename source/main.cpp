#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <malloc.h>
#include <cstring>
#include <cmath>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>

#include "memrrtiks.h"
#include "help.h"
#include "mus.h"
#include "gfx.h"
#include "font.h"
#include "map.h"


#define DEFAULT_FIFO_SIZE	(256*1024)

static void *frameBuffer[2] = { NULL, NULL};

memrrtiks* gmain = new memrrtiks();

GXRModeObj* gfx::rmode;

int main( int argc, char **argv ){
	u32	fb; 	// initial framebuffer index
	u32 first_frame;
	double yscale;
	u32 xfbHeight;
	Mtx44 perspective;
	Mtx GXmodelView2D;
	void *gp_fifo = NULL;

	GXColor background = {0xff, 0xff, 0xff, 0xff};

	VIDEO_Init();

	gfx::rmode = VIDEO_GetPreferredMode(NULL);

	fb = 0;
	first_frame = 1;
	// allocate 2 framebuffers for double buffering
	frameBuffer[0] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(gfx::rmode));
	frameBuffer[1] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(gfx::rmode));

	VIDEO_Configure(gfx::rmode);
	VIDEO_SetNextFramebuffer(frameBuffer[fb]);
	VIDEO_SetBlack(false);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(gfx::rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

	fb ^= 1;

	// setup the fifo and then init the flipper
	gp_fifo = memalign(32,DEFAULT_FIFO_SIZE);
	memset(gp_fifo,0,DEFAULT_FIFO_SIZE);

	GX_Init(gp_fifo,DEFAULT_FIFO_SIZE);

	// clears the bg to color and clears the z buffer
	GX_SetCopyClear(background, 0x00ffffff);

	// other gx setup
	GX_SetViewport(0,0,gfx::rmode->fbWidth,gfx::rmode->efbHeight,0,1);
	yscale = GX_GetYScaleFactor(gfx::rmode->efbHeight,gfx::rmode->xfbHeight);
	xfbHeight = GX_SetDispCopyYScale(yscale);
	GX_SetScissor(0,0,gfx::rmode->fbWidth,gfx::rmode->efbHeight);
	GX_SetDispCopySrc(0,0,gfx::rmode->fbWidth,gfx::rmode->efbHeight);
	GX_SetDispCopyDst(gfx::rmode->fbWidth,xfbHeight);
	GX_SetCopyFilter(gfx::rmode->aa,gfx::rmode->sample_pattern,GX_TRUE,gfx::rmode->vfilter);
	GX_SetFieldMode(gfx::rmode->field_rendering,((gfx::rmode->viHeight==2*gfx::rmode->xfbHeight)?GX_ENABLE:GX_DISABLE));

	if (gfx::rmode->aa)
		GX_SetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
	else
		GX_SetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
	GX_SetDither(GX_FALSE); // please!!

	GX_SetCullMode(GX_CULL_NONE);
	GX_CopyDisp(frameBuffer[fb],GX_TRUE);
	GX_SetDispCopyGamma(GX_GM_1_0);

	// setup the vertex descriptor
	// tells the flipper to expect direct data
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);


	GX_SetNumChans(1);
	GX_SetNumTexGens(1);
	GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
	GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GX_SetTexCoordGen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);


	GX_InvalidateTexAll();

	gmain->gameinit();

	guOrtho(perspective,0,479,0,639,0,300);
	GX_LoadProjectionMtx(perspective, GX_ORTHOGRAPHIC);

	WPAD_Init();


	while(SYS_MainLoop()) {

		WPAD_ScanPads();

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) exit(0);

		GX_SetViewport(0,0,gfx::rmode->fbWidth,gfx::rmode->efbHeight,0,1);
		GX_InvVtxCache();
		GX_InvalidateTexAll();

		GX_ClearVtxDesc();
		GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
		GX_SetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);

		guMtxIdentity(GXmodelView2D);
		guMtxTransApply (GXmodelView2D, GXmodelView2D, 0.0F, 0.0F, -5.0F);
		GX_LoadPosMtxImm(GXmodelView2D,GX_PNMTX0);

		gmain->mainloop(GXmodelView2D);

		GX_DrawDone();

		GX_SetZMode(GX_FALSE, GX_NEVER, GX_FALSE);
		GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GX_SetAlphaUpdate(GX_TRUE);
		GX_SetColorUpdate(GX_TRUE);
		GX_CopyDisp(frameBuffer[fb],GX_TRUE);

		VIDEO_SetNextFramebuffer(frameBuffer[fb]);
		if(first_frame) {
			VIDEO_SetBlack(false);
			first_frame = 0;
		}
		VIDEO_Flush();
		VIDEO_WaitVSync();
		fb ^= 1;		// flip framebuffer
	}
	return 0;
}
