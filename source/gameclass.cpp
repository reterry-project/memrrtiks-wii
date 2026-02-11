#include <cstdlib>

#include "shared.h"
#include "entity.h"
#include "gameclass.h"


void gameclass::reset(entityclass* obj)
{
    state = 0;
    statedelay = 20;
    obj->entities.clear();
    obj->simpleentities.clear();
    warningwave = 4;
    newhighscore = false;
}

void gameclass::start(entityclass* obj)
{
    obj->createentity(140,110,0);
}

void gameclass::updatestate(entityclass* obj)
{
    statedelay--;
    if(statedelay <= 0)
    {
        statedelay = 0;
    }
    if(statedelay <= 0)
    {
        switch(state)
        {
            case 0:
                if(warningwave <= 0)
                {
                    state = 9 + math_random * 11;
                    if(state > 18) state = 18;

                    repeatstate = -1;
                    statedelay = 24 + 10;
                    warningwave = 4;
                }
                else
                {
                    state = 50 + math_random * 12;
                    --warningwave;
                    if(warningwave == 0)
                    {
                        warningsound = 4;
                        warningsounddelay = 0;
                    }
                }
                break;
            case 1:
                state = 0;
                statedelay = 15;
                break;
            case 9:
                for(i = 0; i < 7; ++i)
                {
                    obj->createentity(325,20 + i * 30,2,-5,0);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 10;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 9;
                }
                break;
            case 10:
                for(i = 0; i < 7; ++i)
                {
                    obj->createentity(-10,20 + i * 30,2,5,0);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 10;
                }

                repeatstate--;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 10;
                }
                break;
            case 11:
                for(i = 0; i < 12; ++i)
                {
                    obj->createentity(12 + i * 25,-20,2,0,4);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 10;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 11;
                }
                break;
            case 12:
                for(i = 0; i < 12; ++i)
                {
                    obj->createentity(12 + i * 25,242,2,0,-4);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 10;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 12;
                }
                break;
            case 13:
                for(i = 0; i < 3; ++i)
                {
                    obj->createentity(325,20 + i * 30,2,-5,0);
                }
                for(i = 4; i < 7; ++i)
                {
                    obj->createentity(-10,20 + i * 30,2,5,0);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 10;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 13;
                }
                break;
            case 14:
                for(i = 4; i < 7; ++i)
                {
                    obj->createentity(325,20 + i * 30,2,-5,0);
                }
                for(i = 0; i < 3; ++i)
                {
                    obj->createentity(-10,20 + i * 30,2,5,0);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 10;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 14;
                }
                break;
            case 15:
                for(i = 0; i < 7; ++i)
                {
                    obj->createentity(325 + i * 20,20 + i * 30,2,-5,0);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 4;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 15;
                }
                break;
            case 16:
                for(i = 0; i < 12; ++i)
                {
                    obj->createentity(12 + i * 25,242 + i * 15,2,0,-4);
                }
                statedelay = 10;
                if(repeatstate == -1)
                {
                    repeatstate = 4;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 16;
                }
                break;
            case 17:
                for(i = 0; i < 2; ++i)
                {
                    obj->createentity(-60,15 + i * 120,3,5,0);
                }
                statedelay = 20;
                if(repeatstate == -1)
                {
                    repeatstate = 2;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 17;
                }
                break;
            case 18:
                obj->createentity(325,45,4,-5,0);
                statedelay = 25;
                if(repeatstate == -1)
                {
                    repeatstate = 0;
                }
                --repeatstate;
                state = 1;
                if(repeatstate > 0)
                {
                    state = 18;
                }
                break;
            case 50:
                obj->createentity(160 - 10 - 100,120 - 10 - 90,5,0,0);
                obj->createentity(160 - 10 - 100,120 - 10 + 90,5,0,0);
                obj->createentity(160 - 10 + 100,120 - 10 - 90,5,0,0);
                obj->createentity(160 - 10 + 100,120 - 10 + 90,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 51:
                obj->createentity(30,30 + 30,5,0,0);
                obj->createentity(154,30,5,0,0);
                obj->createentity(320 - 30 - 10,30 + 30,5,0,0);
                obj->createentity(30,240 - 30 - 10 - 30,5,0,0);
                obj->createentity(154,240 - 30 - 10,5,0,0);
                obj->createentity(320 - 30 - 10,240 - 30 - 10 - 30,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 52:
                obj->createentity(160 - 10 - 20,120 - 10 - 20,5,0,0);
                obj->createentity(160 - 10 - 20,120 - 10 + 20,5,0,0);
                obj->createentity(160 - 10 + 20,120 - 10 - 20,5,0,0);
                obj->createentity(160 - 10 + 20,120 - 10 + 20,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 53:
                obj->createentity(160 - 10 - 80,120 - 10,5,0,0);
                obj->createentity(160 - 10 + 80,120 - 10,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 54:
                obj->createentity(160 - 10,120 - 10 - 40,5,0,0);
                obj->createentity(160 - 10,120 - 10 + 40,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 55:
                obj->createentity(160 - 10 - 80,120 - 10,5,0,0);
                obj->createentity(160 - 10 + 80,120 - 10,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 56:
                for(i = 0; i < 8; ++i)
                {
                    obj->createentity(160 - 10 + i * 30 - 110,120 - 10,5,0,0);
                }
                statedelay = 80;
                state = 0;
                break;
            case 57:
                for(i = 0; i < 6; ++i)
                {
                    obj->createentity(160 - 10,120 - 10 + i * 40 - 100,5,0,0);
                }
                statedelay = 80;
                state = 0;
                break;
            case 58:
                obj->createentity(160 - 10 + 80,120 - 10 - 40,5,0,0);
                obj->createentity(160 - 10 + 110,120 - 10 - 40,5,0,0);
                obj->createentity(160 - 10 + 80,120 - 10 - 70,5,0,0);
                obj->createentity(160 - 10 + 110,120 - 10 - 70,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 59:
                obj->createentity(160 - 10 - 80,120 - 10 - 40,5,0,0);
                obj->createentity(160 - 10 - 110,120 - 10 - 40,5,0,0);
                obj->createentity(160 - 10 - 80,120 - 10 - 70,5,0,0);
                obj->createentity(160 - 10 - 110,120 - 10 - 70,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 60:
                obj->createentity(160 - 10 - 80,120 - 10 + 40,5,0,0);
                obj->createentity(160 - 10 - 110,120 - 10 + 40,5,0,0);
                obj->createentity(160 - 10 - 80,120 - 10 + 70,5,0,0);
                obj->createentity(160 - 10 - 110,120 - 10 + 70,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 61:
                obj->createentity(160 - 10 + 80,120 - 10 + 40,5,0,0);
                obj->createentity(160 - 10 + 110,120 - 10 + 40,5,0,0);
                obj->createentity(160 - 10 + 80,120 - 10 + 70,5,0,0);
                obj->createentity(160 - 10 + 110,120 - 10 + 70,5,0,0);
                statedelay = 80;
                state = 0;
                break;
            case 62:
            case 63:
            case 64:
            case 65:
                obj->createentity(160 - 10,120 - 10 - 40,5,0,0);
                obj->createentity(160 - 10,120 - 10 + 40,5,0,0);
                obj->createentity(160 - 10 - 60,120 - 10 - 40 - 30,5,0,0);
                obj->createentity(160 - 10 - 60,120 - 10 + 40 + 30,5,0,0);
                obj->createentity(160 - 10 + 60,120 - 10 - 40 - 30,5,0,0);
                obj->createentity(160 - 10 + 60,120 - 10 + 40 + 30,5,0,0);
                statedelay = 80;
                state = 0;
                break;
        }
    }
}
