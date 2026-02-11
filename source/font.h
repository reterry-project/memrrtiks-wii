#ifndef FONT_H
#define FONT_H

#include <gccore.h>

// HARDCODED ALERT - change these if you change the font
// width not true, only relevant is shifted left FONTTEX_CW times
#define FONTTEX_W 16
#define FONTTEX_H 6
// char dimensions in charCount<<FONTTEX_CW terms, forced square
#define FONTTEX_CW 3
#define fontchs 32 // where it starts in the ascii table


namespace font {
    void makebfont();
    unsigned short bfont_ind(char c);

    double calccenterxfont(char* s, double size);
    void printtext(char* s, double x, double y, double size, double r, double g, double b);
}

#endif
