#include <cstdio>
#include <vector>
#include <cmath>
#include <gccore.h>

#include "shared.h"
#include "flashgeom.h"
#include "gfx.h"
#include "gameclass.h"
#include "entity.h"
#include "font.h"
#include "images_tpl.h"
#include "images.h"
#include "sprites_tpl.h"
#include "sprites.h"

namespace gfx {

Rectangle madrect = {};
Point madpoint = {};

#if 0

int bfontpos;

vector backgrounds = {};

Rectangle sprites_rect = {};

int cur;

int fontheight;

//public var buffer:BitmapData;

Rectangle images_rect = {};


public var tempshape:Shape = new Shape();

public var sprites:Array = new Array();

public var bigbuffer:BitmapData;

public var ntextbox:int;

public var trect:Rectangle;

public var tiles_rect:Rectangle;

public var i:int;

public var j:int;

public var k:int;

public var l:int;

public var ct:ColorTransform;

public var z:int;

public var images:Array = new Array();

public var screen:Bitmap;

public var temptile:BitmapData;

public var textbox:Array = new Array();

public var alphamult:uint;

public var tiles:Array = new Array();

public var tl:Point;

public var tpoint:Point;

public var shapematrix:Matrix = new Matrix();

public var scaleMatrix:Matrix = new Matrix();

public var screenbuffer:BitmapData;

public var bfont:Array = new Array();

public var bfont_rect:Rectangle;

public var bigbufferscreen:Bitmap;

public var tbuffer:BitmapData;

public var bfontlen:Array = new Array();

public var bfontmask_rect:Rectangle;

public var stemp:String;

public var updatebackground:Boolean;

public var fontwidth:int;

public var temp:int;

public var temp3:int;

public var temp2:int;

public var backbuffer:BitmapData;


public function graphicsclass()
{
    super();
}

public function createtextbox(t:String, xp:int, yp:int, r:int = 255, g:int = 255, b:int = 255) : void
{
    if(ntextbox == 0)
    {
        z = 0;
        ++ntextbox;
    }
    else
    {
        i = 0;
        z = -1;
        while(i < ntextbox)
        {
            if(!textbox[i].active)
            {
                z = i;
                i = ntextbox;
            }
            ++i;
        }
        if(z == -1)
        {
            z = ntextbox;
            ++ntextbox;
        }
    }
    if(z < 20)
    {
        textbox[z].clear();
        textbox[z].line[0] = t;
        textbox[z].xp = xp;
        if(xp == -1)
        {
            textbox[z].xp = 160 - (t.length / 2 + 1) * 8;
        }
        textbox[z].yp = yp;
        textbox[z].initcol(r,g,b);
        textbox[z].resize();
    }
}

public function textboxactive() : void
{
    for(i = 0; i < ntextbox; ++i)
    {
        if(z != i)
        {
            textbox[i].remove();
        }
    }
}
#endif

void drawentities(gameclass* game, entityclass* obj)
{
    for(int i = 0; i < (int)obj->entities.size(); i++)
    {
        obj->animateentities(i);
        if(obj->entities[i].active)
        {
            if(obj->entities[i].size == 1)
            {
                if(!obj->entities[i].invis)
                {
                    bigdrawsprite(obj->entities[i].xp, obj->entities[i].yp, obj->entities[i].drawframe, 16);
                }
            }
            else if(obj->entities[i].size == 2)
            {
                if(!obj->entities[i].invis)
                {
                    bigdrawsprite(obj->entities[i].xp, obj->entities[i].yp, obj->entities[i].drawframe, 24);
                }
            }
            else if(obj->entities[i].size == 3)
            {
                if(obj->entities[i].active)
                {
                    drawrectparticle(game,obj,i);
                }
            }
            else if(obj->entities[i].size != 4)
            {
                if(!obj->entities[i].invis)
                {
                    bigdrawsprite(obj->entities[i].xp, obj->entities[i].yp, obj->entities[i].drawframe, 4 );
                }
            }
        }
    }
}

GXTexObj sprites;
TPLFile spritesTPL;

#define SS_WIDTH  20
#define SS_HEIGHT 15

#define SS_SIZE 32

void makespritearray()
{
    TPL_OpenTPLFromMemory(&spritesTPL, (void *)sprites_tpl, sprites_tpl_size);
    TPL_GetTexture(&spritesTPL, spritesimg, &sprites);

    GX_InitTexObjLOD(&sprites, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_DISABLE, GX_DISABLE, GX_ANISO_1);
}

void init() {
    makespritearray();
}


#if 0

public function drawbox(x1:int, y1:int, w1:int, h1:int, r:int, g:int, b:int) : void
{
    settrect(x1,y1,w1,1);
    backbuffer.fillRect(trect,RGB(r,g,b));
    settrect(x1,y1 + h1 - 1,w1,1);
    backbuffer.fillRect(trect,RGB(r,g,b));
    settrect(x1,y1,1,h1);
    backbuffer.fillRect(trect,RGB(r,g,b));
    settrect(x1 + w1 - 1,y1,1,h1);
    backbuffer.fillRect(trect,RGB(r,g,b));
}

#endif

void bigdrawsprite(int x, int y, int t, double sc, double r, double g, double b, double a)
{
#ifndef EGDEBUG
    x*=2;
    y*=2;
    sc*=2;

    GX_SetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


    GX_SetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);


    GX_LoadTexObj(&sprites, GX_TEXMAP0);

    int indx = t % SS_WIDTH, indy = t / SS_WIDTH;

    if (indy > SS_HEIGHT) return; // sanity

    double bfx = (double)indx / SS_WIDTH, bfy = (double)indy / SS_HEIGHT,
    otw = 1.0f/SS_WIDTH, oth = 1.0f/SS_HEIGHT;


    GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

        GX_Position2f32(x, y);
        GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
        GX_TexCoord2f32( bfx,  bfy);

        GX_Position2f32(x+(SS_SIZE*sc), y);
        GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
        GX_TexCoord2f32( bfx+otw,  bfy);

        GX_Position2f32(x+(SS_SIZE*sc), y+(SS_SIZE*sc));
        GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
        GX_TexCoord2f32( bfx+otw,  bfy+oth);

        GX_Position2f32(x, y+(SS_SIZE*sc));
        GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
        GX_TexCoord2f32( bfx,  bfy+oth);

    GX_End();


    /*scaleMatrix.scale(sc,sc);
    bigbuffer.fillRect(bigbuffer.rect,0);
    bigbuffer.copyPixels(sprites[t],sprites_rect,new Point(0,0));
    scaleMatrix.translate(x,y);
    backbuffer.draw(bigbufferscreen,scaleMatrix);
    scaleMatrix.identity();
    */

    GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


    GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);


#else
    char tmpdummy[32] = {0};

    snprintf(tmpdummy, 31, "%d", t);
    bigprint(x, y, tmpdummy, 0, 0, 0, 0, sc);

#endif
}
#if 0
public function init() : void
{
    var t:textboxclass = null;
    updatebackground = true;
    tiles_rect = new Rectangle(0,0,16,16);
    sprites_rect = new Rectangle(0,0,32,32);
    trect = new Rectangle();
    tpoint = new Point();
    tbuffer = new BitmapData(1,1,true);
    tl = new Point(0,0);
    ct = new ColorTransform(0,0,0,1,255,255,255,1);
    madpoint = new Point();
    madrect = new Rectangle();
    funkmeter = 0;
    funktimer = 0;
    funktimer2 = 0;
    funkyroom = 0;
    currentfont = "c64";
    fontwidth = 8;
    fontheight = 8;
    if(currentfont == "terminal")
    {
        fontheight = 12;
    }
    if(currentfont == "casual")
    {
        fontheight = 16;
    }
    if(currentfont == "2xcrypt")
    {
        fontwidth = 16;
        fontheight = 16;
    }
    bfont_rect = new Rectangle(0,0,fontwidth,fontheight);
    bigbuffer = new BitmapData(320,32,true,0);
    bigbufferscreen = new Bitmap(bigbuffer);
    bigbufferscreen.width = 640;
    bigbufferscreen.height = 64;
    scaleMatrix = new Matrix();
    for(i = 0; i < 20; ++i)
    {
        t = new textboxclass();
        textbox.push(t);
    }
    ntextbox = 0;
    backbuffer = new BitmapData(320,240,false,0);
    screenbuffer = new BitmapData(320,240,false,0);
    temptile = new BitmapData(16,16,false,0);
    screen = new Bitmap(screenbuffer);
    screen.width = 640;
    screen.height = 480;
    addChild(screen);
}

public function addline(t:String) : void
{
    textbox[z].addline(t);
}
#endif

int funkmeter = 0, funktimer = 0, funktimer2 = 0, funkyroom = 0;
std::vector<GXTexObj> images_tex;

GXTexObj pixtex;

void makefunkybg() {
    TPLFile imagesTPL;

    TPL_OpenTPLFromMemory(&imagesTPL, (void *)images_tpl, images_tpl_size);
    images_tex.reserve(BG_COUNT);
    for(int i = 0; i < BG_COUNT; i++) {
        images_tex.push_back({});
        TPL_GetTexture(&imagesTPL, i, &images_tex[i]);
        GX_InitTexObjLOD(&images_tex[i], GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_DISABLE, GX_DISABLE, GX_ANISO_1);
    }

    TPL_GetTexture(&imagesTPL, pix, &pixtex);
    GX_InitTexObjLOD(&pixtex, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_DISABLE, GX_DISABLE, GX_ANISO_1);

}

void funkybackground(int t)
{
    GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


    GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

    switch(t)
    {

        case 0:
        {
            --funktimer;
            if(funktimer <= 0)
            {
                funktimer = 4;
                funkmeter = (funkmeter + 1) % 6;
            }
            GX_LoadTexObj(&images_tex[funkmeter < 0 ? 0 : (funkmeter > 7 ? 7 : funkmeter)], GX_TEXMAP0); // will always be in bounds thanks to check.

            GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

            GX_Position2f32(0.0f, 0.0f);
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 0.0f, 0.0f);

            GX_Position2f32((BG_WIDTH<<1), 0.0f);
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 1.0f, 0.0f);

            GX_Position2f32((BG_WIDTH<<1), (BG_HEIGHT<<1));
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 1.0f, 1.0f);

            GX_Position2f32(0.0f, (BG_HEIGHT<<1));
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 0.0f, 1.0f);

            GX_End();
            break;
        }
        case 1:
        {
            --funktimer;
            if(funktimer <= 0)
            {
                funktimer = 1;
                funkmeter = (funkmeter + 3) % 32;
            }
            int points[2][2] = {
                {funkmeter, 0},
                {funkmeter - 320, 0},
            };

            GX_LoadTexObj(&images_tex[6], GX_TEXMAP0);

            for(int i = 0; i < 2; i++) {
                //points[i][0]*=2;
                //points[i][1]*=2; // the wii is DOUBLE the resolution memrrtiks displays at

                GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

                GX_Position2f32(points[i][0], points[i][1]);
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 0.0f, 0.0f);

                GX_Position2f32((BG_WIDTH<<1) + points[i][0], points[i][1]);
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 1.0f, 0.0f);

                GX_Position2f32((BG_WIDTH<<1) + points[i][0], points[i][1] + (BG_HEIGHT<<1));
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 1.0f, 1.0f);

                GX_Position2f32(points[i][0], points[i][1] + (BG_HEIGHT<<1));
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 0.0f, 1.0f);

                GX_End();
            }
            break;
        }
        case 2:
        {
            GX_LoadTexObj(&images_tex[0], GX_TEXMAP0);

            --funktimer;
            if(funktimer <= 0)
            {
                funktimer = 1;
                funkmeter = (funkmeter + 9) % 74;
            }
            int points[2][2] = {
                {0, funkmeter},
                {0, funkmeter - 240},
            };

            for(int i = 0; i < 2; i++) {
                points[i][0]*=2;
                points[i][1]*=2; // the wii is DOUBLE the resolution memrrtiks displays at

                GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

                GX_Position2f32(points[i][0], points[i][1]);
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 0.0f, 0.0f);

                GX_Position2f32((BG_WIDTH<<1) + points[i][0], points[i][1]);
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 1.0f, 0.0f);

                GX_Position2f32((BG_WIDTH<<1) + points[i][0], points[i][1] + (BG_HEIGHT<<1));
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 1.0f, 1.0f);

                GX_Position2f32(points[i][0], points[i][1] + (BG_HEIGHT<<1));
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 0.0f, 1.0f);

                GX_End();
            }
            //backbuffer.copyPixels(images[0],new Rectangle(0,0,images[0].width,images[0].height),new Point(0,funkmeter));
            //backbuffer.copyPixels(images[0],new Rectangle(0,0,images[0].width,images[0].height),new Point(0,funkmeter - 240));
            break;
        }
        case 3:
        {
            --funktimer;
            if(funktimer <= 0)
            {
                funktimer = 2;
                funkmeter = (funkmeter + 1) % 2;
            }
            GX_LoadTexObj(&images_tex[(funkmeter < 0 ? 0 : (funkmeter > 5 ? 5 : funkmeter)) + 2], GX_TEXMAP0); // will always be in bounds thanks to check.

            GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

            GX_Position2f32(0.0f, 0.0f);
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 0.0f, 0.0f);

            GX_Position2f32((BG_WIDTH<<1), 0.0f);
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 1.0f, 0.0f);

            GX_Position2f32((BG_WIDTH<<1), (BG_HEIGHT<<1));
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 1.0f, 1.0f);

            GX_Position2f32(0.0f, (BG_HEIGHT<<1));
            GX_Color4u8(0,0,0,255);
            GX_TexCoord2f32( 0.0f, 1.0f);

            GX_End();
            break;
        }
        case 4:
        {
            GX_LoadTexObj(&images_tex[7], GX_TEXMAP0);

            --funktimer;
            if(funktimer <= 0)
            {
                funktimer = 1;
                funkmeter = (funkmeter + 3) % 80;
            }
            int points[4][2] = {
                {funkmeter, funkmeter * 2},
                {funkmeter - 320, 0},
                {funkmeter - 320,funkmeter * 2 - 240},
                {funkmeter,-60}
            };

            for(int i = 0; i < 4; i++) {
                points[i][0]*=2;
                points[i][1]*=2; // the wii is DOUBLE the resolution memrrtiks displays at

                GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

                GX_Position2f32(points[i][0], points[i][1]);
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 0.0f, 0.0f);

                GX_Position2f32((BG_WIDTH<<1) + points[i][0], points[i][1]);
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 1.0f, 0.0f);

                GX_Position2f32((BG_WIDTH<<1) + points[i][0], points[i][1] + (BG_HEIGHT<<1));
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 1.0f, 1.0f);

                GX_Position2f32(points[i][0], points[i][1] + (BG_HEIGHT<<1));
                GX_Color4u8(0,0,0,255);
                GX_TexCoord2f32( 0.0f, 1.0f);

                GX_End();
            }
            break;
        }

        default:
            break;
    }
}
#if 0
public function len(t:String) : int
{
    bfontpos = 0;
    for(var i:int = 0; i < t.length; i++)
    {
        cur = t.charCodeAt(i);
        bfontpos += bfontlen[cur];
    }
    return bfontpos;
}

public function rbigprint(x:int, y:int, t:String, r:int, g:int, b:int, cen:Boolean = false, sc:Number = 2) : void
{
    x -= len(t) * sc;
    bigprint(x,y,t,r,g,b,cen,sc);
}


public function drawbuffertile(x:int, y:int, t:int) : void
{
    buffer.copyPixels(tiles[t],tiles_rect,new Point(x,y));
}

public function settrect(x:int, y:int, w:int, h:int) : void
{
    trect.x = x;
    trect.y = y;
    trect.width = w;
    trect.height = h;
}

public function drawline(x1:int, y1:int, x2:int, y2:int, r:int, g:int, b:int) : void
{
    if(x1 > x2)
    {
        drawline(x2,y1,x1,y2,r,g,b);
    }
    else if(y1 > y2)
    {
        drawline(x1,y2,x2,y1,r,g,b);
    }
    else
    {
        tempshape.graphics.clear();
        tempshape.graphics.lineStyle(1,RGB(r,g,b));
        tempshape.graphics.lineTo(x2 - x1,y2 - y1);
        shapematrix.translate(x1,y1);
        backbuffer.draw(tempshape,shapematrix);
        shapematrix.translate(-x1,-y1);
    }
}

public function normalrender() : void
{
    screenbuffer.lock();
    screenbuffer.copyPixels(backbuffer,backbuffer.rect,tl,null,null,false);
    screenbuffer.unlock();
    backbuffer.lock();
    backbuffer.fillRect(backbuffer.rect,0);
    backbuffer.unlock();
}

public function maketilearray() : void
{
    var i:Number = NaN;
    var t:BitmapData = null;
    var temprect:Rectangle = null;
    for(var j:Number = 0; j < 15; j++)
    {
        for(i = 0; i < 20; i++)
        {
            t = new BitmapData(16,16,true,0);
            temprect = new Rectangle(i * 16,j * 16,16,16);
            t.copyPixels(buffer,temprect,tl);
            tiles.push(t);
        }
    }
}

public function textboxcenter() : void
{
    textbox[z].centerx();
    textbox[z].centery();
}

public function addimage() : void
{
    var t:BitmapData = new BitmapData(buffer.width,buffer.height,true,0);
    t.copyPixels(buffer,new Rectangle(0,0,buffer.width,buffer.height),tl);
    images.push(t);
}

public function textboxcleanup() : void
{
    i = ntextbox - 1;
    while(i >= 0 && !textbox[i].active)
    {
        --ntextbox;
        --i;
    }
}

public function drawbackground(t:int) : void
{
    backbuffer.copyPixels(backgrounds[t],backbuffer.rect,tl);
}

public function adjustletter(t1:int, d:int = 1) : void
{
    bfontlen[t1] += d;
    bfontlen[t1 + 32] += d;
}

public function drawgui() : void
{
    textboxcleanup();
    for(i = 0; i < ntextbox; ++i)
    {
        textbox[i].update();
        if(textbox[i].active)
        {
            if(textbox[i].ismenu)
            {
                backbuffer.fillRect(textbox[i].textrect,RGB(textbox[i].r / 6,textbox[i].g / 6,textbox[i].b / 6));
                for(j = 0; j < textbox[i].numlines; ++j)
                {
                    if(textbox[i].highlighted == j)
                    {
                        print(textbox[i].xp + 2,textbox[i].yp + fontheight + j * fontheight,">",255 - help.glow,255 - help.glow,255 - help.glow);
                        print(textbox[i].xp + 8,textbox[i].yp + fontheight + j * fontheight,textbox[i].line[j],255 - help.glow,255 - help.glow,255 - help.glow);
                    }
                    else
                    {
                        print(textbox[i].xp + 8,textbox[i].yp + fontheight + j * fontheight,textbox[i].line[j],textbox[i].r * 0.5,textbox[i].g * 0.5,textbox[i].b * 0.5);
                    }
                }
            }
            else
            {
                backbuffer.fillRect(textbox[i].textrect,RGB(textbox[i].r / 6,textbox[i].g / 6,textbox[i].b / 6));
                for(j = 0; j < textbox[i].numlines; ++j)
                {
                    print(textbox[i].xp + 8,textbox[i].yp + fontheight + j * fontheight,textbox[i].line[j],textbox[i].r,textbox[i].g,textbox[i].b);
                }
            }
        }
    }
}

public function rprint(x:int, y:int, t:String, r:int, g:int, b:int) : void
{
    x -= len(t);
    print(x,y,t,r,g,b,false);
}

public function settpoint(x:int, y:int) : void
{
    tpoint.x = x;
    tpoint.y = y;
}

public function adjustcharacter(t1:int, d:int = 1) : void
{
    bfontlen[t1] += d;
}

public function textboxremove() : void
{
    for(i = 0; i < ntextbox; ++i)
    {
        textbox[i].remove();
    }
}

public function textboxsetmenu() : void
{
    textbox[z].ismenu = true;
}

public function textboxcenterx() : void
{
    textbox[z].centerx();
}

public function textboxcentery() : void
{
    textbox[z].centery();
}

public function textboxtimer(t:int) : void
{
    textbox[z].timer = t;
}

public function makebfont() : void
{
    var maprow:Array = null;
    var tstring:String = null;
    var k:int = 0;
    for(j = 0; j < 16; ++j)
    {
        for(i = 0; i < 16; ++i)
        {
            tbuffer = new BitmapData(fontwidth,fontheight,true,0);
            settrect(i * fontwidth,j * fontheight,fontwidth,fontheight);
            tbuffer.copyPixels(buffer,trect,tl);
            bfont.push(tbuffer);
        }
    }
    if(currentfont == "small")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(6);
            ++i;
        }
        tstring = "4,3,5,7,6,7,6,3,4,4,7,7,3,5,2,5,6,5,6,6,6,6,6,6,6,6,2,3,5,5,5,6,7,6,6,6,6,5,5,6,6,3,6,6,5,7,7,6,6,6,6,6,5,6,7,7,7,7,5,4,5,4,5,6,4,6,6,6,6,5,5,6,6,3,6,6,5,7,7,6,6,6,6,6,5,6,7,7,7,7,5,5,3,5,6,4";
        maprow = new Array();
        maprow = tstring.split(",");
        for(k = 0; k < 96; k++)
        {
            bfontlen[k + 32] = int(maprow[k]);
        }
    }
    else if(currentfont == "tiny")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(4);
            ++i;
        }
        adjustletter("I".charCodeAt(0),-2);
        adjustletter("M".charCodeAt(0),2);
        adjustletter("N".charCodeAt(0));
        adjustletter("W".charCodeAt(0),2);
        adjustcharacter(" ".charCodeAt(0),-1);
        adjustcharacter(".".charCodeAt(0),-1);
        adjustcharacter(",".charCodeAt(0),-1);
        adjustcharacter(";".charCodeAt(0),-1);
        adjustcharacter(":".charCodeAt(0),-1);
        adjustcharacter("\'".charCodeAt(0),-2);
        adjustcharacter("&".charCodeAt(0));
        adjustcharacter("*".charCodeAt(0),2);
        adjustcharacter("4".charCodeAt(0));
    }
    else if(currentfont == "flixel")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(6);
            ++i;
        }
        adjustletter("I".charCodeAt(0),-3);
        adjustletter("J".charCodeAt(0),-1);
        adjustletter("K".charCodeAt(0));
        adjustletter("L".charCodeAt(0),-1);
        adjustletter("M".charCodeAt(0),2);
        adjustletter("N".charCodeAt(0));
        adjustletter("O".charCodeAt(0));
        adjustletter("Q".charCodeAt(0));
        adjustletter("S".charCodeAt(0),-1);
        adjustletter("T".charCodeAt(0));
        adjustletter("V".charCodeAt(0));
        adjustletter("W".charCodeAt(0),2);
        adjustletter("X".charCodeAt(0));
        adjustletter("Y".charCodeAt(0));
        adjustcharacter("c".charCodeAt(0),-1);
        adjustcharacter("f".charCodeAt(0),-2);
        adjustcharacter("k".charCodeAt(0),-1);
        adjustcharacter("l".charCodeAt(0),-2);
        adjustcharacter("m".charCodeAt(0));
        adjustcharacter("n".charCodeAt(0),-1);
        adjustcharacter("o".charCodeAt(0),-1);
        adjustcharacter("q".charCodeAt(0),-1);
        adjustcharacter("r".charCodeAt(0),-1);
        adjustcharacter("t".charCodeAt(0),-3);
        adjustcharacter("v".charCodeAt(0),-1);
        adjustcharacter("x".charCodeAt(0),-1);
        adjustcharacter("y".charCodeAt(0),-1);
        adjustcharacter("\'".charCodeAt(0),-4);
        adjustcharacter(".".charCodeAt(0),-2);
        adjustcharacter(",".charCodeAt(0),-2);
        adjustcharacter("&".charCodeAt(0));
        adjustcharacter(" ".charCodeAt(0),-1);
    }
    else if(currentfont == "04b11")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(7);
            ++i;
        }
        adjustcharacter(" ".charCodeAt(0),-2);
        adjustcharacter("i".charCodeAt(0),-4);
        adjustcharacter("l".charCodeAt(0),-4);
        adjustcharacter("j".charCodeAt(0),-2);
        adjustcharacter("m".charCodeAt(0),2);
        adjustcharacter("w".charCodeAt(0),2);
        adjustcharacter(",".charCodeAt(0),-4);
        adjustcharacter(".".charCodeAt(0),-4);
        adjustcharacter("\'".charCodeAt(0),-4);
        adjustcharacter("1".charCodeAt(0),-3);
        adjustcharacter("!".charCodeAt(0),-4);
        adjustcharacter("$".charCodeAt(0),1);
        adjustcharacter("^".charCodeAt(0),-2);
        adjustcharacter("[".charCodeAt(0),-3);
        adjustcharacter("]".charCodeAt(0),-3);
        adjustcharacter("(".charCodeAt(0),-3);
        adjustcharacter(")".charCodeAt(0),-3);
        adjustcharacter("I".charCodeAt(0),-2);
        adjustcharacter("M".charCodeAt(0),1);
        adjustcharacter("W".charCodeAt(0),2);
    }
    else if(currentfont == "crypt")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(5);
            ++i;
        }
    }
    else if(currentfont == "2xcrypt")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(10);
            ++i;
        }
    }
    else if(currentfont == "starperv")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(6);
            ++i;
        }
    }
    else if(currentfont == "casual")
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(8);
            ++i;
        }
        adjustcharacter("i".charCodeAt(0),-4);
        adjustcharacter("j".charCodeAt(0),-2);
        adjustcharacter("l".charCodeAt(0),-3);
        adjustcharacter("f".charCodeAt(0),-1);
        adjustcharacter("m".charCodeAt(0),2);
        adjustcharacter("w".charCodeAt(0));
        adjustcharacter("\'".charCodeAt(0),-4);
        adjustcharacter(".".charCodeAt(0),-2);
        adjustcharacter(",".charCodeAt(0),-2);
    }
    else
    {
        i = 0;
        while(i < 256)
        {
            bfontlen.push(8);
            ++i;
        }
    }
}

public function addbackground() : void
{
    var t:BitmapData = new BitmapData(160,144,true,0);
    t.copyPixels(buffer,backbuffer.rect,tl);
    backgrounds.push(t);
}
#endif

void flashlight()
{
    GXColor background = {0xff, 0xff, 0xff, 0xff};

    GX_SetCopyClear(background, 0x00ffffff);
}

void screenshake(Mtx GXmodelView2D)
{
    GX_SetViewport((math_random * 5 - 3), (math_random * 5 - 3), rmode->fbWidth,rmode->efbHeight,0,1);
}

void render(gameclass* game, Mtx GXmodelView2D)
{
    if(game->test)
        print(5,5,game->teststring,196,196,196,false);

    if(game->flashlight > 0)
    {
        game->flashlight--;
        flashlight();
        return;
    }

    if(game->screenshake > 0) {
        game->screenshake--;
        screenshake(GXmodelView2D);
    }
}

#if 0
public function drawimage(t:int, xp:int, yp:int, cent:Boolean = false) : void
{
    if(cent)
    {
        backbuffer.copyPixels(images[t],new Rectangle(0,0,images[t].width,images[t].height),new Point(80 - int(images[t].width / 2),yp));
    }
    else
    {
        backbuffer.copyPixels(images[t],new Rectangle(0,0,images[t].width,images[t].height),new Point(xp,yp));
    }
}

public function drawmap(map:mapclass) : void
{
    for(j = 0; j < 15; ++j)
    {
        for(i = 0; i < 20; ++i)
        {
            drawtile(i * 16,j * 16,map.at(i,j));
        }
    }
}

public function RGB(red:Number, green:Number, blue:Number) : Number
{
    return blue | green << 8 | red << 16;
}
#endif
void drawrectparticle(gameclass* game, entityclass* obj, int i)
{
    if(i < 0 || i >= (int)obj->entities.size()) return; // sanity

    GX_SetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


    GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

    GX_LoadTexObj(&pixtex, GX_TEXMAP0);


    madrect.x      = obj->entities[i].xp;
    madrect.y      = obj->entities[i].yp;
    madrect.width  = obj->entities[i].w;
    madrect.height = 3;
    fillrect(madrect.x*2, madrect.y*2,
             madrect.width*2, madrect.height*2,
             (double)((obj->entities[i].life & 0x00ff0000) >> 16)/255,
             (double)((obj->entities[i].life & 0x0000ff00) >> 8 )/255,
             (double)((obj->entities[i].life & 0x000000ff)      )/255,
             (double)((obj->entities[i].life & 0xff000000) >> 24)/255
    );
    madrect.x      = obj->entities[i].xp;
    madrect.y      = obj->entities[i].yp;
    madrect.width  = 3;
    madrect.height = obj->entities[i].h;
    fillrect(madrect.x*2, madrect.y*2,
             madrect.width*2, madrect.height*2,
             (double)((obj->entities[i].life & 0x00ff0000) >> 16)/255,
             (double)((obj->entities[i].life & 0x0000ff00) >> 8 )/255,
             (double)((obj->entities[i].life & 0x000000ff)      )/255,
             (double)((obj->entities[i].life & 0xff000000) >> 24)/255
    );
    madrect.x      = obj->entities[i].xp + obj->entities[i].w - 3;
    madrect.y      = obj->entities[i].yp;
    madrect.width  = 3;
    madrect.height = obj->entities[i].h;
    fillrect(madrect.x*2, madrect.y*2,
             madrect.width*2, madrect.height*2,
             (double)((obj->entities[i].life & 0x00ff0000) >> 16)/255,
             (double)((obj->entities[i].life & 0x0000ff00) >> 8 )/255,
             (double)((obj->entities[i].life & 0x000000ff)      )/255,
             (double)((obj->entities[i].life & 0xff000000) >> 24)/255
    );
    madrect.x      = obj->entities[i].xp;
    madrect.y      = obj->entities[i].yp + obj->entities[i].h - 3;
    madrect.width  = obj->entities[i].w;
    madrect.height = 3;
    fillrect(madrect.x*2, madrect.y*2,
             madrect.width*2, madrect.height*2,
             (double)((obj->entities[i].life & 0x00ff0000) >> 16)/255,
             (double)((obj->entities[i].life & 0x0000ff00) >> 8 )/255,
             (double)((obj->entities[i].life & 0x000000ff)      )/255,
             (double)((obj->entities[i].life & 0xff000000) >> 24)/255
    );

    GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


    GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
}

void drawsimpleentities(entityclass* obj)
{
    for(int i = 0; i < (int)obj->simpleentities.size(); ++i)
    {
        if(obj->simpleentities[i].active)
        {
            if(obj->simpleentities[i].size == 1)
            {
                GX_SetTevOp(GX_TEVSTAGE0, GX_MODULATE);
                GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


                GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

                GX_LoadTexObj(&pixtex, GX_TEXMAP0);

                fillrect(obj->simpleentities[i].xp*2, obj->simpleentities[i].yp*2,
                         20*2, 20*2, 0,0,0,0
                        //(double)((obj->simpleentities[i].colour & 0x00ff0000) >> 16)/255,
                        //(double)((obj->simpleentities[i].colour & 0x0000ff00) >> 8 )/255,
                        //(double)((obj->simpleentities[i].colour & 0x000000ff)      )/255,
                        //(double)((obj->simpleentities[i].colour & 0xff000000) >> 24)/255
                );
                //settrect(obj.simpleentities[i].xp,obj.simpleentities[i].yp,20,20);
                //setcol(obj.simpleentities[i].colour);
                //backbuffer.fillRect(trect,ct.color);
                GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
                GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);


                GX_SetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
            }
            else if(obj->simpleentities[i].size != 2)
            {
                bigdrawsprite(obj->simpleentities[i].xp,obj->simpleentities[i].yp,
                              obj->simpleentities[i].tile,
                              SS_SIZE
                              //(double)((obj->simpleentities[i].colour & 0x00ff0000) >> 16)/255,
                              //(double)((obj->simpleentities[i].colour & 0x0000ff00) >> 8 )/255,
                              //(double)((obj->simpleentities[i].colour & 0x000000ff)      )/255,
                              //(double)((obj->simpleentities[i].colour & 0xff000000) >> 24)/255
                );

                //settpoint(obj.simpleentities[i].xp,obj.simpleentities[i].yp);
                //setcol(obj.simpleentities[i].colour);
                //sprites[obj.simpleentities[i].tile].colorTransform(sprites_rect,ct);
                //backbuffer.copyPixels(sprites[obj.simpleentities[i].tile],sprites_rect,tpoint);
            }
        }
    }
}

void print(double x, double y, char* s, double r, double g, double b, int cen) {
    bigprint(x, y, s, r, g, b, cen, 1);
}

void bigprint(double x, double y, char* s, double r, double g, double b, int cen, int sc)
{
    r = (r < 0.0f) ? 0.0f : ((r > 1.0f) ? 1.0f : r);
    g = (g < 0.0f) ? 0.0f : ((g > 1.0f) ? 1.0f : g);
    b = (b < 0.0f) ? 0.0f : ((b > 1.0f) ? 1.0f : b);

    if(cen)
    {
        x = 160 + font::calccenterxfont(s, sc * MULTIFONTFACTOR) / 2;
    }
    font::printtext(s, x * 2, y * 2, sc * MULTIFONTFACTOR, r, g, b);
}

void fillrect(int x1, int y1, int w1, int h1, double r, double g, double b, double a)
{
    // ALERT: MAKE SURE you have the proper environment before running!!
    GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

    GX_Position2f32(x1, y1);
    GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
    GX_TexCoord2f32( 0.0f, 0.0f);

    GX_Position2f32(x1+w1, y1);
    GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
    GX_TexCoord2f32( 1.0f, 0.0f);

    GX_Position2f32(x1+w1, y1+h1);
    GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
    GX_TexCoord2f32( 1.0f, 1.0f);

    GX_Position2f32(x1, y1+h1);
    GX_Color4u8((int)r*255,(int)g*255,(int)b*255, (int)a*255);
    GX_TexCoord2f32( 0.0f, 1.0f);

    GX_End();
}

#if 0
public function setcol(t:int) : void
{
    ct.color = 0;
}

public function drawtile(x:int, y:int, t:int) : void
{
    backbuffer.copyPixels(tiles[t],tiles_rect,new Point(x,y));
}

#endif
}
