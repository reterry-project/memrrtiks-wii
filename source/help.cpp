#include <cmath>
#include <iterator>

#include "help.h"
namespace help {
      double sine  [64] = {};
      double cosine[64] = {};

      int slowsine;

      int glow,  glowdir;

      int globaltemp, globaltemp2, globaltemp3;


      double getsine(int i) {
            if(i < 0 || i >= 64) return 0;
            return sine[i];
      }
      double getcosine(int i) {
            if(i < 0 || i >= 64) return 0;
            return cosine[i];
      }

      bool inbox(int xc, int yc, int x1, int y1, int x2, int y2)
      {
            if(xc >= x1 && xc <= x2)
            {
                  if(yc >= y1 && yc <= y2)
                  {
                        return true;
                  }
            }
            return false;
      }

      char* number(int t)
      {
            switch(t)
            {
                  case 0:
                        return "Zero";
                  case 1:
                        return "One";
                  case 2:
                        return "Two";
                  case 3:
                        return "Three";
                  case 4:
                        return "Four";
                  case 5:
                        return "Five";
                  case 6:
                        return "Six";
                  case 7:
                        return "Seven";
                  case 8:
                        return "Eight";
                  case 9:
                        return "Nine";
                  case 10:
                        return "Ten";
                  case 11:
                        return "Eleven";
                  case 12:
                        return "Twelve";
                  case 13:
                        return "Thirteen";
                  case 14:
                        return "Fourteen";
                  case 15:
                        return "Fifteen";
                  case 16:
                        return "Sixteen";
                  case 17:
                        return "Seventeen";
                  case 18:
                        return "Eighteen";
                  case 19:
                        return "Nineteen";
                  case 20:
                        return "Twenty";
                  case 21:
                        return "Twenty One";
                  default:
                        return "Some";
            }
      }

      void init()
      {
            std::fill(std::begin(sine), std::end(sine), 0);
            std::fill(std::begin(cosine), std::end(cosine), 0);
            for(int i = 0; i < 64; i++)
            {
                  sine  [i] = sin((double)i * 6.283f / 64.0f);
                  cosine[i] = cos((double)i * 6.283f / 64.0f);
            }
            glow     = 0;
            glowdir  = 0;
            slowsine = 0;
      }

      void updateglow()
      {
            slowsine++;
            if(slowsine >= 64)
            {
                  slowsine = 0;
            }
            if(glowdir == 0)
            {
                  glow += 2;
                  if(glow >= 62)
                  {
                        glowdir = 1;
                  }
            }
            else
            {
                  glow -= 2;
                  if(glow < 2)
                  {
                        glowdir = 0;
                  }
            }
      }

      /*
      char* threedigits(int t)
      {
      if(t < 10)
      {
      return "00" + String(t);
      }
      if(t < 100)
      {
      return "0" + String(t);
      }
      return String(t);
      }

      char* thousand(int t)
      {
      int temp = 0;
      if(t < 1000)
      {
      return "$" + String(t);
      }
      if(t < 1000000)
      {
      return "$" + String((t - t % 1000) / 1000) + "," + threedigits(t % 1000);
      }
      temp = (t - t % 1000) / 1000;
      return "$" + String((temp - temp % 1000) / 1000) + "," + threedigits(temp % 1000) + "," + threedigits(t % 1000);
      }*/

      int opa(int t)
      {
            return (t + 32) % 64;
      }


      bool inboxw(int xc, int yc, int x1, int y1, int x2, int y2)
      {
            return
            (xc >= x1 && xc <= x1 + x2) &&
            (yc >= y1 && yc <= y1 + y2);
      }
}
