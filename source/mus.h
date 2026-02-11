#ifndef MUS_H
#define MUS_H

#include <vector>

#include <gccore.h>
#include <aesndlib.h>

#define MUS_VOICE 0
#define MUS_NOCHS 16

namespace mus {
    extern AESNDPB* chans[MUS_NOCHS];

    void init();
    void musicvol(u32 volume);

    void stop();
    void processmusicfade();
    void processmusicfadein();
    void processmusic();
    void fadeout();
    void stopmusic();
    void play(int);
    void playef(int t, int offset = 0);

    void pushsong(void*, u32);
    void pushef(void*, u32);
}

#endif
