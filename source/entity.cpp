#include <cmath>
#include <cstdlib>

#include <gccore.h>

#include "flashgeom.h"

#include "shared.h"
#include "help.h"
#include "entity.h"

void entityclass::removeblock(int t)
{
      blocks.erase(blocks.begin() + t);
}

bool entityclass::updateentities(int i, gameclass* game)
{
      if(entities[i].active)
      {
            if(entities[i].statedelay <= 0)
            {
                  switch(entities[i].type)
                  {
                        case 0:
                              // obsolete check was here
                              break;
                        case 1:
                              if(entities[i].state == 0)
                              {
                                    if(entities[i].xp > 320)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].xp < -10)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp < -10)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp > 250)
                                    {
                                          entities[i].active = false;
                                    }
                              }
                              break;
                        case 2:
                              if(entities[i].state == 0)
                              {
                                    if(entities[i].xp > 500)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].xp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp > 450)
                                    {
                                          entities[i].active = false;
                                    }
                              }
                              else if(entities[i].state == 1)
                              {
                                    game->score += 50;
                                    mus::playef(0,10);
                                    if(simpleentities.size() > 80)
                                    {
                                          for(j = 0; j < 4; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp,help::getcosine(j * 16 + 4) * 10,help::getsine(j * 16 + 4) * 10,0,1,10,0);
                                          }
                                    }
                                    else
                                    {
                                          for(j = 0; j < 16; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp,help::getcosine(j * 4) * 10,help::getsine(j * 4) * 10,0,1,10,0);
                                          }
                                    }
                                    entities[i].active = false;
                              }
                              break;
                        case 3:
                              if(entities[i].state == 0)
                              {
                                    if(entities[i].xp > 500)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].xp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp > 450)
                                    {
                                          entities[i].active = false;
                                    }
                              }
                              else if(entities[i].state == 1)
                              {
                                    mus::playef(1,10);
                                    game->score += 100;
                                    if(simpleentities.size() > 80)
                                    {
                                          for(j = 0; j < 4; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp,help::getcosine(j * 16 + 4) * 10,help::getsine(j * 16 + 4) * 10,0,1,10,0);
                                          }
                                    }
                                    else
                                    {
                                          for(j = 0; j < 16; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp,help::getcosine(j * 4) * 10,help::getsine(j * 4) * 10,0,1,10,0);
                                          }
                                    }
                                    entities[i].active = false;
                              }
                              break;
                        case 4:
                              if(entities[i].state == 0)
                              {
                                    if(entities[i].xp > 500)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].xp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp > 450)
                                    {
                                          entities[i].active = false;
                                    }
                              }
                              else if(entities[i].state == 1)
                              {
                                    mus::playef(2,10);
                                    game->score += 1000;
                                    if(simpleentities.size() > 80)
                                    {
                                          for(j = 0; j < 4; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp, help::getcosine(j * 16 + 4) * 10,help::getsine(j * 16 + 4) * 10,0,1,10,0);
                                          }
                                    }
                                    else
                                    {
                                          for(j = 0; j < 16; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp, help::getcosine(j * 4) * 10,help::getsine(j * 4) * 10,0,1,10,0);
                                          }
                                    }
                                    entities[i].active = false;
                              }
                              break;
                        case 5:
                              if(entities[i].state < 10)
                              {
                                    entities[i].state += 2;
                                    entities[i].statedelay = 10;
                                    createentity(entities[i].xp,entities[i].yp,29,20,20);
                              }
                              else if(entities[i].state == 10)
                              {
                                    createentity(entities[i].xp,entities[i].yp,29,20,20);
                                    createentity(entities[i].xp + 4,entities[i].yp + 4,29,12,12);
                                    createentity(entities[i].xp + 8,entities[i].yp + 8,29,4,4);
                                    createentity(entities[i].xp,entities[i].yp,6);
                                    entities[i].active = false;
                              }
                              break;
                        case 6:
                              if(entities[i].state == 0)
                              {
                                    j = getplayer();
                                    if(j > -1)
                                    {
                                          entities[i].vx = 0;
                                          if(entities[i].xp < entities[j].xp)
                                          {
                                                entities[i].vx = 1;
                                          }
                                          if(entities[i].xp > entities[j].xp)
                                          {
                                                entities[i].vx = -1;
                                          }
                                          entities[i].vy = 0;
                                          if(entities[i].yp < entities[j].yp)
                                          {
                                                entities[i].vy = 1;
                                          }
                                          if(entities[i].yp > entities[j].yp)
                                          {
                                                entities[i].vy = -1;
                                          }
                                    }
                                    if(entities[i].xp > 500)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].xp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp < -200)
                                    {
                                          entities[i].active = false;
                                    }
                                    if(entities[i].yp > 450)
                                    {
                                          entities[i].active = false;
                                    }
                              }
                              else if(entities[i].state == 1)
                              {
                                    mus::playef(0,10);
                                    game->score += 100;
                                    if(simpleentities.size() > 80)
                                    {
                                          for(j = 0; j < 4; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp,help::getcosine(j * 16 + 4) * 10,help::getsine(j * 16 + 4) * 10,0,1,10,0);
                                          }
                                    }
                                    else
                                    {
                                          for(j = 0; j < 16; ++j)
                                          {
                                                createsimpleentity(entities[i].xp,entities[i].yp,help::getcosine(j * 4) * 10,help::getsine(j * 4) * 10,0,1,10,0);
                                          }
                                    }
                                    entities[i].active = false;
                              }
                              break;
                              case 24:
                                    if(entities[i].state == 0)
                                    {
                                          entities[i].behave--;
                                          entities[i].xp -= 6;
                                          entities[i].yp -= 6;
                                          entities[i].w += 12;
                                          entities[i].h += 12;
                                          if(entities[i].w > 360)
                                          {
                                                entities[i].active = false;
                                          }
                                          if(entities[i].behave <= 0)
                                          {
                                                entities[i].active = false;
                                          }
                                    }
                  }
            }
            else
            {
                  entities[i].statedelay--;
                  if(entities[i].statedelay < 0)
                  {
                        entities[i].statedelay = 0;
                  }
            }
      }
      return true;
}

void entityclass::removeblockat(int x, int y)
{
      for(i = 0; i < (int)blocks.size(); i++)
      {
            if(blocks[i].xp == x && blocks[i].yp == y)
            {
                  removeblock(i);
            }
      }
}

bool entityclass::checkblocks()
{
      for(i = 0; i < (int)blocks.size(); i++)
      {
            if(blocks[i].active && blocks[i].type == BLOCK)
            {
                  if(blocks[i].rect.intersects(temprect))
                  {
                  return true;
                  }
            }
      }
      return false;
}

void entityclass::createblock(int t, int xp, int yp, int w, int h, int trig)
{
      blocks.push_back({});
      z = blocks.size()-1;

      blocks[z].clear();
      blocks[z].active = true;
      switch(t)
      {
            case BLOCK:
                  blocks[z].type = BLOCK;
                  blocks[z].xp = xp;
                  blocks[z].yp = yp;
                  blocks[z].wp = w;
                  blocks[z].hp = h;
                  blocks[z].rectset(xp,yp,w,h);
                  break;
            case TRIGGER:
                  blocks[z].type = TRIGGER;
                  blocks[z].xp = xp;
                  blocks[z].yp = yp;
                  blocks[z].wp = w;
                  blocks[z].hp = h;
                  blocks[z].rectset(xp,yp,w,h);
                  blocks[z].trigger = trig;
                  break;
            case DAMAGE:
                  blocks[z].type = DAMAGE;
                  blocks[z].xp = xp;
                  blocks[z].yp = yp;
                  blocks[z].wp = w;
                  blocks[z].hp = h;
                  blocks[z].rectset(xp,yp,w,h);
                  break;
      }
}

bool entityclass::gettype(int t)
{
      for(int myi = 0; myi < (int)entities.size(); myi++)
      {
            if(entities[myi].type == t)
            {
                  return true;
            }
      }
      return false;
}

void entityclass::createsimpleentity(double xp, double yp, double vx, double vy, int t, int size, int life, int c)
{
      simpleentities.push_back({});
      z = simpleentities.size()-1;

      simpleentities[z].clear();
      simpleentities[z].active = true;
      simpleentities[z].tile = t;
      simpleentities[z].size = size;
      simpleentities[z].colour = c;
      simpleentities[z].life = life;
      simpleentities[z].xp = xp;
      simpleentities[z].yp = yp;
      simpleentities[z].vx = vx;
      simpleentities[z].vy = vy;
}

void entityclass::animateentities(int i)
{
      if(i < 0 || i >= (int)entities.size()) return; // sanity

      if(entities[i].active)
      {
            if(entities[i].statedelay <= 0)
            {
                  entities[i].drawframe = entities[i].tile;
                  entities[i].drawframe += entities[i].dir;
            }
            else
            {
                  --entities[i].statedelay;
                  if(entities[i].statedelay < 0)
                  {
                        entities[i].statedelay = 0;
                  }
            }
      }
}

void entityclass::cleanup()
{
      for(i = entities.size() - 1; i >= 0; i--)
      {
            if(!entities[i].active) {
                  entities.erase(entities.begin() + i);
            }
      }
      for(i = simpleentities.size() - 1; i >= 0; i--)
      {
            if(!simpleentities[i].active) {
                  simpleentities.erase(simpleentities.begin() + i);
            }
      }
}

int entityclass::checktrigger()
{
      for(i = 0; i < (int)entities.size(); i++)
      {
            if(entities[i].rule == 0)
            {
                  tempx = entities[i].xp + entities[i].cx;
                  tempy = entities[i].yp + entities[i].cy;
                  tempw = entities[i].w;
                  temph = entities[i].h;
                  rectset(tempx,tempy,tempw,temph);
                  for(j = 0; j < (int)blocks.size(); ++j)
                  {
                        if(blocks[j].type == TRIGGER && blocks[j].active)
                        {
                              if(blocks[j].rect.intersects(temprect))
                              {
                                    activetrigger = blocks[j].trigger;
                                    return blocks[j].trigger;
                              }
                        }
                  }
            }
      }
      return -1;
}
void entityclass::removetrigger(int t)
{
      for(i = 0; i < (int)blocks.size(); i++)
      {
            if(blocks[i].type == TRIGGER && blocks[i].trigger == t)
            {
                  removeblock(i);
            }
      }
}

int entityclass::getplayer()
{
      // ew... i can imagine this function taking up a lot of CPU time.
      for(int myi = 0; myi < (int)entities.size(); myi++)
      {
            if(entities[myi].type == 0)
            {
                  return myi;
            }
      }
      return -1;
}

void entityclass::entitymapcollision(mapclass* map, int t)
{
      if(t < 0 || t >= (int)entities.size()) return; // sanity

      if(testwallsx(map,t,entities[t].newxp,entities[t].yp))
      {
            entities[t].xp = entities[t].newxp;
      }
      else
      {
            if(entities[t].onwall > 0)
            {
                  entities[t].state = entities[t].onwall;
            }
            if(entities[t].onxwall > 0)
            {
                  entities[t].state = entities[t].onxwall;
            }
      }
      if(testwallsy(map,t,entities[t].xp,entities[t].newyp))
      {
            entities[t].yp = entities[t].newyp;
      }
      else
      {
            if(entities[t].onwall > 0)
            {
                  entities[t].state = entities[t].onwall;
            }
            if(entities[t].onywall > 0)
            {
                  entities[t].state = entities[t].onywall;
            }
            entities[t].jumpframe = 0;
      }
}

void entityclass::entitycollisioncheck(gameclass* game, mapclass* map)
{
      for(i = 0; i < (int)entities.size(); ++i)
      {
            if(entities[i].active)
            {
                  for(j = 0; j < (int)entities.size(); ++j)
                  {
                        if(entities[j].active && entities[j].rule != 4 && entities[j].harmful)
                        {
                              if(entities[i].rule == 1 && entities[j].rule == 2)
                              {
                                    if(entitycollide(i,j))
                                    {
                                          entities[j].state = entities[j].onentity;
                                          entities[j].statedelay = 0;
                                          entities[i].active = false;
                                    }
                              }
                              if(entities[i].rule == 0 && (entities[j].rule == 2 || entities[j].rule == 3))
                              {
                                    if(entitycollide(i,j))
                                    {
                                          entities[j].state = entities[j].onentity;
                                          entities[j].statedelay = 0;
                                          entities[i].active = false;
                                          mus::playef(3,10);
                                          game->deathseq = 60;
                                          mus::fadeout();
                                    }
                              }
                        }
                  }
            }
      }
      j = getplayer();
      if(j > -1)
      {
            if(!testwallsx(map,j,entities[j].xp,entities[j].yp))
            {
                  entities[j].yp -= 3;
            }
      }
      activetrigger = -1;
      if(checktrigger() > -1)
      {
            game->state = activetrigger;
            game->statedelay = 0;
      }
}

// ALERT: these two functions are recursive and may lock up the console
bool entityclass::testwallsx(mapclass* map, int t, int tx, int ty)
{
      if(t < 0 || t >= (int)entities.size()) return false; // sanity

      tempx = tx + entities[t].cx;
      tempy = ty + entities[t].cy;
      tempw = entities[t].w;
      temph = entities[t].h;
      rectset(tempx,tempy,tempw,temph);
      if(checkwall(map))
      {
            if(entities[t].vx > 1)
            {
                  --entities[t].vx;
                  entities[t].newxp = int(entities[t].xp + entities[t].vx);
                  return testwallsx(map,t,entities[t].newxp,entities[t].yp);
            }
            if(entities[t].vx < -1)
            {
                  ++entities[t].vx;
                  entities[t].newxp = int(entities[t].xp + entities[t].vx);
                  return testwallsx(map,t,entities[t].newxp,entities[t].yp);
            }
            entities[t].vx = 0;
            return false;
      }
      return true;
}

bool entityclass::testwallsy(mapclass* map, int t, int tx, int ty)
{
      if(t < 0 || t >= (int)entities.size()) return false; // sanity

      tempx = tx + entities[t].cx;
      tempy = ty + entities[t].cy;
      tempw = entities[t].w;
      temph = entities[t].h;
      rectset(tempx,tempy,tempw,temph);
      if(checkwall(map))
      {
            if(entities[t].vy > 1)
            {
                  entities[t].vy--;
                  entities[t].newyp = int(entities[t].yp + entities[t].vy);
                  return testwallsy(map,t,entities[t].xp,entities[t].newyp);
            }
            if(entities[t].vy < -1)
            {
                  entities[t].vy++;
                  entities[t].newyp = int(entities[t].yp + entities[t].vy);
                  return testwallsy(map,t,entities[t].xp,entities[t].newyp);
            }
            entities[t].vy = 0;
            return false;
      }
      return true;
}

bool entityclass::checkwall(mapclass* map)
{
      if(checkblocks())
      {
            return true;
      }
      tempx = getgridpoint(temprect.x);
      tempy = getgridpoint(temprect.y);
      tempw = getgridpoint(temprect.x + temprect.width - 1);
      temph = getgridpoint(temprect.y + temprect.height - 1);

      if(map->collide(tempw,tempy) || map->collide(tempx,tempy) ||
         map->collide(tempx,temph) || map->collide(tempw,temph))
            return true;

      if(temprect.height >= 12)
      {
            tpy1 = getgridpoint(temprect.y + 6);
            if(map->collide(tempx,tpy1) || map->collide(tempw,tpy1)) return true;
            
            if(temprect.height >= 18)
            {
                  tpy1 = getgridpoint(temprect.y + 12);
                  if(map->collide(tempx,tpy1) || map->collide(tempw,tpy1)) return true;
                  if(temprect.height >= 24)
                  {
                        tpy1 = getgridpoint(temprect.y + 18);
                        if(map->collide(tempx,tpy1) || map->collide(tempw,tpy1)) return true;
                  }
            }
      }
      if(temprect.width >= 12)
      {
            tpx1 = getgridpoint(temprect.x + 6);
            if(map->collide(tpx1,tempy) || map->collide(tpx1,temph)) return true;
      }
      return false;
}

void entityclass::createentity(double xp, double yp, int t, double vx, double vy, int para)
{
      entities.push_back({});
      z = entities.size()-1;
      entities[z].clear();
      entities[z].active = true;
      entities[z].type = t;
      switch(t)
      {
            // Disclaimer: i have no clue what any of these are lmfao
            case 0:
                  entities[z].rule = 0;
                  entities[z].tile = 0;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].cx = 6;
                  entities[z].cy = 4;
                  entities[z].w = 16;
                  entities[z].h = 10;
                  break;
            case 1:
                  entities[z].rule = 1;
                  entities[z].tile = 4;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].vx = vx;
                  entities[z].vy = vy;
                  entities[z].cx = 0;
                  entities[z].cy = 0;
                  entities[z].w = 20;
                  entities[z].h = 20;
                  break;
            case 2:
                  entities[z].rule = 2;
                  entities[z].tile = 5;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].vx = vx;
                  entities[z].vy = vy;
                  entities[z].cx = 0;
                  entities[z].cy = 0;
                  entities[z].w = 5 * 4;
                  entities[z].h = 5 * 4;
                  entities[z].onentity = 1;
                  entities[z].harmful = true;
                  break;
            case 3:
                  entities[z].rule = 2;
                  entities[z].tile = 5;
                  entities[z].size = 1;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].vx = vx;
                  entities[z].vy = vy;
                  entities[z].cx = 0;
                  entities[z].cy = 0;
                  entities[z].w = 16 * 5;
                  entities[z].h = 16 * 5;
                  entities[z].onentity = 1;
                  entities[z].harmful = true;
                  break;
            case 4:
                  entities[z].rule = 2;
                  entities[z].tile = 5;
                  entities[z].size = 2;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].vx = vx;
                  entities[z].vy = vy;
                  entities[z].cx = 0;
                  entities[z].cy = 0;
                  entities[z].w = 24 * 5;
                  entities[z].h = 24 * 5;
                  entities[z].onentity = 1;
                  entities[z].harmful = true;
                  break;
            case 5:
                  entities[z].rule = 3;
                  entities[z].tile = 0;
                  entities[z].size = 4;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].vx = vx;
                  entities[z].vy = vy;
                  entities[z].cx = 0;
                  entities[z].cy = 0;
                  entities[z].w = 5 * 4;
                  entities[z].h = 5 * 4;
                  entities[z].onentity = 1;
                  entities[z].harmful = false;
                  break;
            case 6:
                  entities[z].rule = 2;
                  entities[z].tile = 5;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].vx = vx;
                  entities[z].vy = vy;
                  entities[z].cx = 0;
                  entities[z].cy = 0;
                  entities[z].w = 5 * 4;
                  entities[z].h = 5 * 4;
                  entities[z].onentity = 1;
                  entities[z].harmful = true;
                  break;
            case 28:
                  entities[z].type = 24;
                  entities[z].rule = 4;
                  entities[z].size = 3;
                  entities[z].tile = 0;
                  entities[z].xp = xp;
                  entities[z].yp = yp;
                  entities[z].w = vx;
                  entities[z].h = vy;
                  entities[z].behave = 30;
                  switch((int)(math_random * 6))
                  {
                        case 0:
                              entities[z].life = 16711680;
                              break;
                        case 1:
                              entities[z].life = 65280;
                              break;
                        case 2:
                              entities[z].life = 16711935;
                              break;
                        case 3:
                              entities[z].life = 16776960;
                              break;
                        case 4:
                              entities[z].life = 255;
                              break;
                        case 5:
                              entities[z].life = 65535;
                              break;
                        default:
                              entities[z].life = 16777215;
                  }
                  break;
            case 29:
                  entities[z].type = 24;
                  entities[z].rule = 4;
                  entities[z].size = 3;
                  entities[z].tile = 0;
                  entities[z].xp = xp + 2;
                  entities[z].yp = yp + 2;
                  entities[z].w = vx - 4;
                  entities[z].h = vy - 4;
                  entities[z].behave = 30;
                  break;
      }
}

void entityclass::removeallblocks()
{
      blocks = {};
}

void entityclass::applyfriction(int t, double xrate, double yrate)
{
      if(t < 0 || t >= (int)entities.size()) return; // sanity

      entities[t].vx -= (entities[t].vx > 0 ? 1 : -1) * xrate;
      entities[t].vy -= (entities[t].vy > 0 ? 1 : -1) * yrate;

      entities[t].vx = entities[t].vx > 4 ? 4 : (entities[t].vx < -4 ? -4 : entities[t].vx);
      entities[t].vy = entities[t].vy > 4 ? 4 : (entities[t].vy < -4 ? -4 : entities[t].vy);

      if(abs(entities[t].vx) <= xrate)
      {
            entities[t].vx = 0;
      }
      if(abs(entities[t].vy) <= yrate)
      {
            entities[t].vy = 0;
      }
}

void entityclass::updateentitylogic(int t)
{
      if(t < 0 || t >= (int)entities.size()) return; // sanity

      entities[t].oldxp = entities[t].xp;
      entities[t].oldyp = entities[t].yp;
      entities[t].vx += entities[t].ax;
      entities[t].vy += entities[t].ay;
      entities[t].ax = 0;
      if(entities[t].jumping)
      {
            if(entities[t].ay < 0)
            {
                  ++entities[t].ay;
            }
            if(entities[t].ay > -1)
            {
                  entities[t].ay = 0;
            }
            --entities[t].jumpframe;
            if(entities[t].jumpframe <= 0)
            {
                  entities[t].jumping = false;
            }
      }
      else if(entities[t].gravity)
      {
            entities[t].ay = 3;
      }
      if(entities[t].gravity)
      {
            applyfriction(t,0,0.5);
      }
      entities[t].newxp = entities[t].xp + entities[t].vx;
      entities[t].newyp = entities[t].yp + entities[t].vy;
}

int entityclass::getgridpoint(int t)
{
      return (int)((double)(t - t % 16) / 16);
}

bool entityclass::entitycollidefloor(mapclass* map, int t)
{
      if(t < 0 || t >= (int)entities.size()) return false; // sanity

      tempx = entities[t].xp + entities[t].cx;
      tempy = entities[t].yp + entities[t].cy + 1;
      tempw = entities[t].w;
      temph = entities[t].h;
      rectset(tempx,tempy,tempw,temph);
      if(checkwall(map))
      {
            return true;
      }
      return false;
}

bool entityclass::checkdamage()
{
      for(i = 0; i < (int)entities.size(); i++)
      {
            if(entities[i].rule == 0)
            {
                  tempx = entities[i].xp + entities[i].cx;
                  tempy = entities[i].yp + entities[i].cy;
                  tempw = entities[i].w;
                  temph = entities[i].h;
                  rectset(tempx,tempy,tempw,temph);
                  for(j = 0; j < (int)blocks.size(); ++j)
                  {
                        if(blocks[j].type == DAMAGE && blocks[j].active)
                        {
                              if(blocks[j].rect.intersects(temprect))
                              {
                                    return true;
                              }
                        }
                  }
            }
      }
      return false;
}

bool entityclass::entitycollide(int a, int b)
{
      if((a < 0 || a >= (int)entities.size()) || (b < 0 || b >= (int)entities.size())) return false; // sanity check - what is the engine even thinking passing these values in the first place

      tempx = entities[a].xp + entities[a].cx;
      tempy = entities[a].yp + entities[a].cy;
      tempw = entities[a].w;
      temph = entities[a].h;
      rectset(tempx,tempy,tempw,temph);
      tempx = entities[b].xp + entities[b].cx;
      tempy = entities[b].yp + entities[b].cy;
      tempw = entities[b].w;
      temph = entities[b].h;
      rect2set(tempx,tempy,tempw,temph);
      if(temprect.intersects(temprect2))
      {
            return true;
      }
      return false;
}

bool entityclass::updatesimpleentities(int t)
{
      if(t < 0 || t >= (int)simpleentities.size()) return false; // sanity

      if(simpleentities[t].active)
      {
            simpleentities[t].vx += simpleentities[t].ax;
            simpleentities[t].vy += simpleentities[t].ay;
            simpleentities[t].ax = 0;
            simpleentities[t].xp += simpleentities[t].vx;
            simpleentities[t].yp += simpleentities[t].vy;
            --simpleentities[t].life;
            if(simpleentities[t].life <= 0)
            {
                  simpleentities[t].active = false;
            }
      }
      return true;
}

void entityclass::rect2set(int xi, int yi, int wi, int hi) // I hate this codebase.
{
      temprect2.x = xi;
      temprect2.y = yi;
      temprect2.width = wi;
      temprect2.height = hi;
}

void entityclass::rectset(int xi, int yi, int wi, int hi)
{
      temprect.x = xi;
      temprect.y = yi;
      temprect.width = wi;
      temprect.height = hi;
}


