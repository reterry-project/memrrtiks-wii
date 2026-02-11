#ifndef ENT_H
#define ENT_H

#include <gccore.h>

class entclass
{
public:
   // variables have been reordered as in the clear function. The stupid chud compiler scrambled it
   bool active;               // am I working?
   bool invis;                // can you see me?

   int type;                  // entity type
   int size;                  // ???
   int tile;                  // obsolete drawing thing, here to decide which image to draw
   int rule;
   int state, statedelay;     // what am I doing and when am I going to do it

   int life;                  // health measure(?)
   int colour;                // colour(?) (p.s. TERRY! It's programming, don't use British spelling!!)
   int para;                  // ???
   int behave;                // ???
   int animate;               // should I be animated?

   // positions, sizes, and the lot
   double xp, yp;
   double ax, ay;
   double vx, vy;
   int w, h;
   int cx, cy;
   double oldxp, oldyp,
       newxp, newyp;
   int x1, y1,
       x2, y2;

   bool jumping;              // am I jumping?
   bool gravity;              // gravity

   int onground;              // am I on the ground?
   int onroof;                // am I on the roof?
   int onentity;              // am I on another entity?

   bool harmful;              // am I harmful? (???)

   int onwall;                // am I on a wall?
   int onxwall, onywall;      // ok, but is that wall x or y

   bool isplatform;           // DON'T BE RACIST!! AM I A BUILDING!


   // other schlop
   int jumpframe, actionframe, walkingframe;

   int framedelay;

   int drawframe;
   int dir;


   void clear();
};

#endif
