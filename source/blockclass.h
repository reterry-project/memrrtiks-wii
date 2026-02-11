#ifndef BLOCKCLASS_H
#define BLOCKCLASS_H

#include "flashgeom.h"

class blockclass
{
public:
   bool active;
   int type;
   int trigger;

   int xp, yp,
   wp, hp;

   Rectangle rect;

   void clear();
   void rectset(int xi, int yi, int wi, int hi);
};

#endif
