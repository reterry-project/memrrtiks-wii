#ifndef HELP_H
#define HELP_H

#include <gccore.h>

namespace help
{
      extern int slowsine;

      extern int glow,  glowdir;

      double getsine(int i);
      double getcosine(int i);

      bool inbox(int xc, int yc, int x1, int y1, int x2, int y2);

      char* number(int t);

      void init();

      void updateglow();

      /*
      char* threedigits(int t);
      char* thousand(int t);
      */

      int opa(int t);
      bool inboxw(int xc, int yc, int x1, int y1, int x2, int y2);
}

#endif
