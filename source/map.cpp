#include "map.h"
#include <iterator>

void mapclass::init()
{
      for(i = 0; i < MAP_WIDTH; i++)
      {
            vmult[i] = i * MAP_HEIGHT; // smart trick!
      }
}

void mapclass::loadlevel(int r)
{
      switch(r)
      {
            case 0:
                  int mytmap[MAP_WIDTH * MAP_HEIGHT] = {
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,
                  1,1,1,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,1,1,
                  1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,
                  1,1,1,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,2,
                  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
                  };
                  std::copy(std::begin(mytmap), std::end(mytmap), std::begin(tmap));
                  fillcontent(tmap, MAP_WIDTH * MAP_HEIGHT);
                  break;
      }
}

void mapclass::fillcontent(int* tmaptoload, unsigned long tmapSize)
{
      for(i = 0; (unsigned long)i < tmapSize; i++)
            contents[i] = tmaptoload[i];
}

int mapclass::at(int xp, int yp)
{
      if(xp >= 0 && yp >= 0 && xp < 20 && yp < 15)
      {
            return contents[xp + vmult[yp]];
      }
      return 0;
}

bool mapclass::collide(int x, int y)
{
      if(!(x < 0 || y < 0 || x >= 20 || y >= 14) && contents[x + vmult[y]] == 2)
      {
            return true;
      }
      return false;
}

