#ifndef GFX_H
#define GFX_H

#include <gccore.h>

#include "gameclass.h"


#define BG_COUNT 8
#define BG_WIDTH 320
#define BG_HEIGHT 240

#define MULTIFONTFACTOR 16


//typedef long[4] Rectangle;
//typedef long[2] Point;
namespace gfx {
    extern GXRModeObj *rmode;

    extern int funkmeter, funktimer, funktimer2, funkyroom;

    void init();

    void makefunkybg();
    void funkybackground(int t);
    void print(double x, double y, char* t, double r, double g, double b, int cen = 0);
    void bigprint(double x, double y, char* t, double r, double g, double b, int cen = 0, int sc = 2);

    void drawentities(gameclass* game, entityclass* obj);
    void drawsimpleentities(entityclass* obj);
    void drawrectparticle(gameclass* game, entityclass* obj, int i);
    void bigdrawsprite(int x, int y, int t, double sc = 2, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0);


    void fillrect(int x1, int y1, int w1, int h1, double r, double g, double b, double a = 1.0);

    void render(gameclass* game, Mtx GXmodelView2D);
}

#endif
