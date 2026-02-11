#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH  15
#define MAP_HEIGHT 20


class mapclass
{
public:
      int contents[MAP_WIDTH * MAP_HEIGHT] = {0};

      int vmult[MAP_WIDTH] = {0};

      int tmap[MAP_WIDTH * MAP_HEIGHT];

      int i, j, k;

      int temp, temp2;

      int background; // obsoleted by funky background

      void init();
      void loadlevel(int r);
      void fillcontent(int* tmaptoload, unsigned long tmapSize);
      int at(int xp, int yp);
      bool collide(int x, int y);
};

#endif
