#ifndef SIMPLEENT_H
#define SIMPLEENT_H

#include <gccore.h>

class simpleentclass
{
public:
   // variables have been reordered as in the clear function. The stupid chud compiler scrambled it
   bool active;               // am I working?
   int size;                  // ???
   int life;                  // health measure(?)
   int colour;                // colour(?) (p.s. TERRY! It's programming, don't use British spelling!!)

   // positions, sizes, and the lot
   double xp, yp;
   double ax, ay;
   double vx, vy;

   double oldxp, oldyp;

   int tile;

   void clear();
};

#endif
