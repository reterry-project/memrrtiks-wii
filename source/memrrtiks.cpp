#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <chrono>

#include <gccore.h>
#include <wiiuse/wpad.h>

#include "memrrtiks.h"
#include "shared.h"
#include "help.h"
#include "font.h"
#include "gfx.h"
#include "gameclass.h"
#include "entity.h"
#include "map.h"

#include "nice_song_bin.h"
#include "title_song_bin.h"
#include "slow_song_bin.h"
#include "nasty_song_bin.h"
#include "between_song_bin.h"
#include "ef1_bin.h"
#include "ef2_bin.h"
#include "ef3_bin.h"
#include "ef4_bin.h"
#include "ef5_bin.h"
#include "ef6_bin.h"

memrrtiks::memrrtiks () {
      _skip = _rate * 10;
}

uint64_t memrrtiks::getTimer() {
      using namespace std::chrono;
      return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

void memrrtiks::gameinit()
{
      srand(time(NULL));

      gfx::init();
      mus::init();
      map->init();
      help::init();

      font::makebfont();
      gfx::makefunkybg();
      //key = new KeyPoll(stage);
      /*
      SoundMixer.soundTransform = new SoundTransform(1);
      mus::currentsong = -1;
      mus::musicfade = 0;
      mus::initefchannels();
      mus::currentefchan = 0;
      mus::numplays = 0;
      */
      mus::pushsong((void*)nice_song_bin,    nice_song_bin_size   );
      mus::pushsong((void*)title_song_bin,   title_song_bin_size  );
      mus::pushsong((void*)slow_song_bin,    slow_song_bin_size   );
      mus::pushsong((void*)nasty_song_bin,   nasty_song_bin_size  );
      mus::pushsong((void*)between_song_bin, between_song_bin_size);
      mus::pushef((void*)ef1_bin, ef1_bin_size);
      mus::pushef((void*)ef2_bin, ef2_bin_size);
      mus::pushef((void*)ef3_bin, ef3_bin_size);
      mus::pushef((void*)ef4_bin, ef4_bin_size);
      mus::pushef((void*)ef5_bin, ef5_bin_size);
      mus::pushef((void*)ef6_bin, ef6_bin_size);
      /*
      mus::efchan.push(new ef_0());
      mus::efchan.push(new ef_1());
      mus::efchan.push(new ef_2());
      mus::efchan.push(new ef_3());
      mus::efchan.push(new ef_4());
      mus::efchan.push(new ef_5());*/
      game->gamestate = TITLEMODE;

      mus::play(0);
      //gfx.init();
      /*
      tempbmp = new im_tiles();
      gfx.buffer = tempbmp.bitmapData;
      gfx.maketilearray();
      tempbmp = new im_sprites();
      gfx.buffer = tempbmp.bitmapData;
      gfx.makespritearray();
      tempbmp = new im_bfont();
      gfx.buffer = tempbmp.bitmapData;
      gfx.makebfont();
      tempbmp = new im_image0();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image1();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image2();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image3();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image4();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image5();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image6();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      tempbmp = new im_image7();
      gfx.buffer = tempbmp.bitmapData;
      gfx.addimage();
      gfx.buffer = new BitmapData(320,240,false,0);
      addChild(gfx);
      */
}


void memrrtiks::mainloop(Mtx GXmodelView2D)
{
      /*//while((_current = getTimer()) < _timer);
      _current = getTimer();
      if(_last < 0)
      {
            _last = _current;
      }
      _delta += (int64_t)_current - _last;
      _last = _current;
      if(_delta >= _rate)
      {
            for(_delta = _delta % _skip; _delta >= _rate; _delta -= _rate)
            {

            }
      }*/
      input();
      logic();
      render(GXmodelView2D);
}


void memrrtiks::gamerender(Mtx GXmodelView2D)
{
#ifdef GDEBUG
      char debugtext[63] = {0};
#endif
      gfx::render(game, GXmodelView2D);

      if(game->flashlight > 0) goto dogdebug;

      gfx::funkybackground(gfx::funkyroom);
      gfx::drawentities(game,obj);
      gfx::drawsimpleentities(obj);

      snprintf(highscorestr, 31, "%d", game->score);

      if(game->score == game->highscore)
      {
            if(math_random * 100 > 50)
            {
                  gfx::bigprint(-1,100, highscorestr,255,0,0,true,6);
            }
            else
            {
                  gfx::bigprint(-1,100,highscorestr,0,0,0,true,6);
            }
      }
      else
      {
            gfx::bigprint(-1,218,highscorestr,0,0,0,true,3);
      }
      if(game->warningwave <= 0)
      {
            if(math_random * 100 > 50)
            {
                  gfx::bigprint(5 + (int)(math_random * 5),10  + (int)(math_random * 5),"INCOMING",255,0,0,true,5);
                  gfx::bigprint(5 + (int)(math_random * 5),195 + (int)(math_random * 5),"INCOMING",255,0,0,true,5);
            }
            else
            {
                  gfx::bigprint(5 + (int)(math_random * 5),10  + (int)(math_random * 5),"INCOMING",0,0,0,true,5);
                  gfx::bigprint(5 + (int)(math_random * 5),195 + (int)(math_random * 5),"INCOMING",0,0,0,true,5);
            }
      }
dogdebug:

#ifdef GDEBUG
      snprintf(debugtext, 63, "ents: %d, sents: %d", (int)obj->entities.size(), (int)obj->simpleentities.size());
      font::printtext(debugtext, 1, 11, 8, 0, 0, 0);
      snprintf(debugtext, 63, "blocks: %d", (int)obj->blocks.size());
      font::printtext(debugtext, 1, 21, 8, 0, 0, 0);
      snprintf(debugtext, 63, "deathseq: %d", (int)game->deathseq);
      font::printtext(debugtext, 1, 31, 8, 0, 0, 0);
      font::printtext("ANYTHING BEYOND 1000 IS EXTREMELY DANGEROUS!", 1, 41, 8, 100, 0, 0);
      font::printtext("sound channels location:", 1, 61, 8, 0, 0, 100);

      for(i = 0; i < MUS_NOCHS; i++) {
            snprintf(debugtext, 63, "%p", mus::chans[i]);
            font::printtext(debugtext, 1, 61+i*10, 8, 0, 0, 0);
      }
#endif
      return; // goto is scary
}


void memrrtiks::gamelogic()
{
      game->updatestate(obj);
      if(game->warningsound > 0)
      {
            game->warningsounddelay--;
            if(game->warningsounddelay <= 0)
            {
                  mus::playef(5);
                  game->warningsound--;
                  game->warningsounddelay = 25;
            }
      }
      if(game->deathseq == 0)
      {
            game->score += 10;
      }
      if(game->score >= game->highscore)
      {
            game->highscore = game->score;
            game->newhighscore = true;
            --game->highscoretimer;
            if(game->highscoretimer <= 0)
            {
                  game->highscoretimer = 20;
                  mus::playef(4,10);
            }
      }
      if(!game->completestop)
      {
            for(i = 0; i < (int)obj->simpleentities.size(); i++)
            {
                  obj->updatesimpleentities(i);
            }
            for(i = 0; i < (int)obj->entities.size(); i++)
            {
                  obj->updateentities(i,game);
                  obj->updateentitylogic(i);
                  obj->entitymapcollision(map, i);
            }
            obj->entitycollisioncheck(game,map);
      }
      obj->cleanup();
      if(game->deathseq == 1)
      {
            game->warningsound = 0;
            game->warningsounddelay = 0;
            game->deathseq = 0;
            game->gamestate = 1;
            mus::play(0);
      }
      else if(game->deathseq > 1)
      {
            game->deathseq--;
      }
}

void memrrtiks::gameinput()
{
      u32 buttonsdown   = WPAD_ButtonsHeld(0);
      u32 buttonsdowngc =  PAD_ButtonsHeld(0);
      /*i = 0;
      while(i < gfx.ntextbox)
      {
            if(gfx.textbox[i].active)
            {
                  if(gfx.textbox[i].ismenu)
                  {
                        gfx.textbox[i].highlighted = -1;
                        if(help.inboxw(game->mx,game->my,gfx.textbox[i].textrect.x,gfx.textbox[i].textrect.y,gfx.textbox[i].textrect.width,gfx.textbox[i].textrect.height))
                        {
                              gfx.textbox[i].highlighted = game->my - (gfx.textbox[i].textrect.y + 8);
                              gfx.textbox[i].highlighted /= 8;
                        }
                        if(key.click)
                        {
                              if(gfx.textbox[i].highlighted == 2)
                              {
                                    game->test = true;
                              }
                        }
                  }
            }
            ++i;
      }*/
      for(i = 0; i < (int)obj->entities.size(); i++)
      {
            if(obj->entitycollidefloor(map,i))
            {
                  obj->entities[i].onground = 2;
            }
            else
            {
                  --obj->entities[i].onground;
            }
            if(obj->entities[i].rule == 0)
            {
                  if(game->hascontrol)
                  {
                        game->jumpheld = (buttonsdown   & WPAD_BUTTON_A) ||
                                         (buttonsdowngc &  PAD_BUTTON_A);

                        if(game->jumppressed > 0)
                        {
                              game->jumppressed--;
                        }


                        // movement

                        s8 stick[2] = { PAD_StickX(0), PAD_StickY(0) };

                        if((buttonsdown & WPAD_BUTTON_LEFT) || (buttonsdowngc & PAD_BUTTON_LEFT)        || (stick[0] < 0))
                        {
                              if(obj->entities[i].xp > 0)
                              {
                                    obj->entities[i].vx = -6;
                              }
                              else
                              {
                                    obj->entities[i].vx = 0;
                              }
                              if(!game->jumpheld)
                              {
                                    obj->entities[i].dir = 0;
                              }
                        }
                        else if((buttonsdown & WPAD_BUTTON_RIGHT) || (buttonsdowngc & PAD_BUTTON_RIGHT) || (stick[0] > 0))
                        {
                              if(obj->entities[i].xp < MWIDTH)
                              {
                                    obj->entities[i].vx = 6;
                              }
                              else
                              {
                                    obj->entities[i].vx = 0;
                              }
                              if(!game->jumpheld)
                              {
                                    obj->entities[i].dir = 1;
                              }
                        }
                        else
                        {
                              obj->entities[i].vx = 0;
                        }

                        if((buttonsdown & WPAD_BUTTON_UP) || (buttonsdowngc & PAD_BUTTON_UP)            || (stick[1] > 0))
                        {
                              if(obj->entities[i].yp > 0)
                              {
                                    obj->entities[i].vy = -6;
                              }
                              else
                              {
                                    obj->entities[i].vy = 0;
                              }
                              if(!game->jumpheld)
                              {
                                    obj->entities[i].dir = 2;
                              }
                        }
                        else if((buttonsdown & WPAD_BUTTON_DOWN) || (buttonsdowngc & PAD_BUTTON_DOWN)   || (stick[1] < 0))
                        {
                              if(obj->entities[i].yp < MHEIGHT)
                              {
                                    obj->entities[i].vy = 6;
                              }
                              else
                              {
                                    obj->entities[i].vy = 0;
                              }
                              if(!game->jumpheld)
                              {
                                    obj->entities[i].dir = 3;
                              }
                        }
                        else
                        {
                              obj->entities[i].vy = 0;
                        }

                        /*if(abs(stick[0]) > 64 || abs(stick[1]) > 64) { // only override if there is activity on the stick
                              obj->entities[i].vx = stick[0] < 0 ? (obj->entities[i].yp > 0 ? -6 : 0) : (obj->entities[i].yp < MWIDTH  ? 6 : 0);
                              obj->entities[i].vy = stick[1] < 0 ? (obj->entities[i].yp > 0 ? -6 : 0) : (obj->entities[i].yp < MHEIGHT ? 6 : 0);
                              if(!game->jumpheld) {
                                    obj->entities[i].dir = (stick[0] < 0 ? 0 : 1);
                                    obj->entities[i].dir = (stick[1] < 0 ? 2 : 3);
                              }
                        }*/

                        // others
                        if(!game->jumpheld)
                        {
                              gfx::funkyroom = obj->entities[i].dir;
                              mus::play(obj->entities[i].dir + 1);
                        }

                        if(game->shootdelay <= 0)
                        {
                              switch(obj->entities[i].dir)
                              {
                                    case 0:
                                          obj->createentity(obj->entities[i].xp,obj->entities[i].yp,1,-20);
                                          obj->createentity(obj->entities[i].xp,obj->entities[i].yp,1,-20,-4);
                                          obj->createentity(obj->entities[i].xp,obj->entities[i].yp,1,-20,4);
                                          break;
                                    case 1:
                                          obj->createentity(obj->entities[i].xp,obj->entities[i].yp,1,20);
                                          obj->createentity(obj->entities[i].xp,obj->entities[i].yp,1,20,-4);
                                          obj->createentity(obj->entities[i].xp,obj->entities[i].yp,1,20,4);
                                          break;
                                    case 2:
                                          obj->createentity(obj->entities[i].xp + 16,obj->entities[i].yp,1,0,-20);
                                          obj->createentity(obj->entities[i].xp + 16,obj->entities[i].yp,1,-4,-20);
                                          obj->createentity(obj->entities[i].xp + 16,obj->entities[i].yp,1,4,-20);
                                          break;
                                    case 3:
                                          obj->createentity(obj->entities[i].xp + 16,obj->entities[i].yp,1,0,20);
                                          obj->createentity(obj->entities[i].xp + 16,obj->entities[i].yp,1,-4,20);
                                          obj->createentity(obj->entities[i].xp + 16,obj->entities[i].yp,1,4,20);
                              }
                              game->shootdelay = 5;
                        }
                        else
                        {
                              game->shootdelay--;
                        }
                  }
            }
      }
}

void memrrtiks::titleinput()
{
      if(!(WPAD_ButtonsDown(0) & WPAD_BUTTON_A))
      {
            game->jumpheld = false;
      }
      if((((WPAD_ButtonsDown(0) & WPAD_BUTTON_A) || (WPAD_ButtonsDown(0) & WPAD_BUTTON_MINUS) || (WPAD_ButtonsDown(0) & WPAD_BUTTON_PLUS)) && !game->jumpheld) || 
          ((PAD_ButtonsUp(0) & PAD_BUTTON_START) || (PAD_ButtonsUp(0) & PAD_BUTTON_A))
      )
      {
            game->jumpheld = false;
            game->reset(obj);
            game->gamestate = GAMEMODE;
            game->start(obj);
            game->score = 0;
      }

}

void memrrtiks::konami() {
      u32 buttonsdowngc =  PAD_ButtonsUp(3);

      if(konamiNum < 11) {
            if(buttonsdowngc & konamis[konamiNum]) konamiNum++;
            else if(buttonsdowngc != 0) konamiNum = 0;
      } else {
            game->gamestate = CLICKTOSTART;
            konamiNum = 0;
      }
}

void memrrtiks::input()
{
      WPADData* data = WPAD_Data(0);

      game->mx = data->ir.x / 2;
      game->my = data->ir.y / 2;

      switch(game->gamestate)
      {
            case TITLEMODE:
                  konami();
                  titleinput();
                  break;
            case GAMEMODE:
                  gameinput();
                  break;
            case CLICKTOSTART:
                  if((WPAD_ButtonsDown(0) & WPAD_BUTTON_A) || (PAD_ButtonsDown(0) & PAD_BUTTON_A))
                        game->gamestate = TITLEMODE;
            break;
      }
}

void memrrtiks::titlelogic()
{
      if(game->newhighscore)
      {
            game->newhighscore = false;
      }
}

void memrrtiks::logic()
{
      switch(game->gamestate)
      {
            case TITLEMODE:
                  titlelogic();
                  break;
            case GAMEMODE:
                  gamelogic();
      }
      mus::processmusic();
      help::updateglow();
      /*
       *  if(key.isDown(77) && game->mutebutton <= 0)
       *  {
       *  game->mutebutton = 8;
       *  if(game->muted)
       *  {
       *        game->muted = false;
}
else
{
game->muted = true;
}
}
if(game->mutebutton > 0)
{
--game->mutebutton;
}
if(game->muted)
{
if(game->globalsound == 1)
{
game->globalsound = 0;
SoundMixer.soundTransform = new SoundTransform(0);
}
}
if(!game->muted && game->globalsound == 0)
{
game->globalsound = 1;
SoundMixer.soundTransform = new SoundTransform(1);
}
*/
}

void memrrtiks::titlerender()
{
#ifdef GDEBUG
      char msg[128] = {0};
#endif

      gfx::funkybackground(4);
      gfx::bigprint(5,80,"memrrtiks, suashem",0,0,0,true);
      gfx::bigprint(5,180,"highscore",0,0,0,true);
      snprintf(highscorestr, 31, "%d", game->highscore);
      gfx::bigprint(-1,200,highscorestr,0,0,0,true,5);

#ifdef GDEBUG
      snprintf(msg, 127, "konami nums: %d", konamiNum);
      font::printtext(msg, 1, 11, 8, 0, 0, 200);
#endif
}

void memrrtiks::render(Mtx GXmodelView2D)
{
      switch(game->gamestate)
      {
            case TITLEMODE:
                  titlerender();
                  break;
            case GAMEMODE:
                  gamerender(GXmodelView2D);
                  break;
            case CLICKTOSTART:
                  gfx::print(5,115,"[Click to start]",255 - help::glow / 2,255 - help::glow / 2,255 - help::glow / 2,true);
                  //gfx::normalrender();
                  break;
      }

#ifdef GDEBUG
      font::printtext("debug build! debug features are enabled", 1, 1, 8, 0, 0, 200);
#endif
}
