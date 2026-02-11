#include <cstring>
#include <gccore.h>

#include "fonttex_tpl.h"
#include "fonttex.h"
#include "font.h"


namespace font {
    GXTexObj bfont_tex;
    TPLFile bfont;

    void makebfont() {
        TPL_OpenTPLFromMemory(&bfont, (void *)fonttex_tpl,fonttex_tpl_size);
        TPL_GetTexture(&bfont, fonttex, &bfont_tex);

        GX_InitTexObjLOD(&bfont_tex, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_DISABLE, GX_DISABLE, GX_ANISO_1);
    }

    unsigned short bfont_ind(char c) {
        char newc = c - fontchs;
        return
            ((unsigned char)(newc % FONTTEX_W) << 8) |
            (unsigned char)(newc / FONTTEX_W);
    }
    double calccenterxfont(char* s, double size) {
        return -((double)strlen(s) * size / 2);
    }

    void printtext(char* s, double x, double y, double size, double r, double g, double b) {
        GX_LoadTexObj(&bfont_tex, GX_TEXMAP0);
        GX_SetTevOp(GX_TEVSTAGE0, GX_MODULATE);
        GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);

        GX_SetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

        char* current = s;

        while(*current != 0) {
            unsigned short ind = bfont_ind(*current);
            unsigned char indx = ind >> 8, indy = ind & 0xff;

            double bfx = (double)indx / FONTTEX_W, bfy = (double)indy / FONTTEX_H,
            otw = 1.0f/FONTTEX_W, oth = 1.0f/FONTTEX_H;

            long diff = (current-s) * size;
            GX_Begin(GX_QUADS, GX_VTXFMT0, 4);			// Draw a Plane

                GX_Position2f32(x+diff, y);
                GX_Color4u8((int)r*255,(int)g*255,(int)b*255, 255);
                GX_TexCoord2f32( bfx,  bfy);

                GX_Position2f32(x+diff+size, y);
                GX_Color4u8((int)r*255,(int)g*255,(int)b*255, 255);
                GX_TexCoord2f32( bfx+otw,  bfy);

                GX_Position2f32(x+diff+size,  size+y);
                GX_Color4u8((int)r*255,(int)g*255,(int)b*255, 255);
                GX_TexCoord2f32( bfx+otw,  bfy+oth);

                GX_Position2f32(x+diff,  size+y);
                GX_Color4u8((int)r*255,(int)g*255,(int)b*255, 255);
                GX_TexCoord2f32( bfx,  bfy+oth);

            GX_End();									// Done Drawing The Quad

            current++;
        }
        GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
        GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);

        GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    }
}
