// blockclass is the only class that retains the class prefix in the filename, as there might be something else called block.cpp (something something wii)
#include "blockclass.h"

void blockclass::clear()
{
   active = false;
   type = 0;
   trigger = 0;
   xp = 0;
   yp = 0;
   wp = 0;
   hp = 0;
   rectset(xp, yp, wp, hp);
}

void blockclass::rectset(int xi, int yi, int wi, int hi)
{
   rect.x      = xi;
   rect.y      = yi;
   rect.width  = wi;
   rect.height = hi;
}
