#ifndef GAMECLASS_H
#define GAMECLASS_H

class entityclass;

#include "mus.h"

#define BLOCK 0
#define TRIGGER 1
#define DAMAGE 2


class gameclass
{
public:
    bool infocus = true;
    bool paused = false, muted = false;

    int globalsound = 1;
    int gamestate = 0; // GAMESTATE

    bool completestop = false, hascontrol = true;
    
    bool jumpheld = false;
    int jumppressed = 0;

    int shootdelay = 0;

    int warningsound = 0, warningsounddelay = 0;

    bool newhighscore = false;
    int score = 0;
    int highscore = 3000, highscoretimer = 0;
    
    int deathseq = 0;

    bool test        = false;
    char* teststring = "TEST = True";

    int state = 0, statedelay = 0;
    
    int mutebutton;

    int warningwave;
    
    int screenshake;
    
    int flashlight;
    
    int mx, my;
    
    int easydelay;    

    int i, j;
    
    int repeatstate;
        
    /*public function gameclass(obj:entityclass, music:musicclass)
    {
        updatestate(obj,music);
    }*/
    
    
    void reset(entityclass* obj);
    
    void start(entityclass* obj);
    
    void updatestate(entityclass* obj);
};

#endif
