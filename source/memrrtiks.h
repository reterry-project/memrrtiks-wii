#ifndef MEMRRTIKS_H
#define MEMRRTIKS_H

#include <cstdint>
#include <gccore.h>

#include "gameclass.h"
#include "entity.h"
#include "map.h"

#define BLOCK        0
#define TRIGGER      1
#define DAMAGE       2

#define GAMEMODE     0
#define TITLEMODE    1
#define CLICKTOSTART 2
#define FOCUSMODE    3

#define MWIDTH       285
#define MHEIGHT      220

// useless??
//#define TARGET_FPS 60

class memrrtiks
{
private:
    uint64_t _current = 0;

    int64_t _skip, _last = -1, _delta = 0, _rate = 16;

    uint64_t _timer = 4;

    char highscorestr[32] = {'\0'};

    uint64_t getTimer();


public:
    int konamiNum = 0;
    u32 konamis[11] = {
        PAD_BUTTON_UP,
        PAD_BUTTON_UP,
        PAD_BUTTON_DOWN,
        PAD_BUTTON_DOWN,
        PAD_BUTTON_LEFT,
        PAD_BUTTON_RIGHT,
        PAD_BUTTON_LEFT,
        PAD_BUTTON_RIGHT,
        PAD_BUTTON_B,
        PAD_BUTTON_A,
        PAD_BUTTON_START
    };

    int i, j, k;
    unsigned int pi, pj;

    unsigned int pixel, pixel2;

    int temp;

    gameclass*  game = new gameclass();
    entityclass* obj = new entityclass();
    mapclass*    map = new mapclass();

    memrrtiks();

    void gameinit();

    void mainloop(Mtx GXmodelView2D);


    void titlelogic();
    void gamelogic();
    void logic();

    void gameinput();
    void titleinput();
    void konami();
    void input();

    void gamerender(Mtx GXmodelView2D);
    void titlerender();
    void render(Mtx GXmodelView2D);
};

#endif
