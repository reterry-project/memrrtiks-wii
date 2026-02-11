#include <vector>
#include <cmath>

#include <aesndlib.h>
#include "mus.h"

namespace mus {

    int musicfade = 0, musicfadein = 0, currentsong = -1;


    std::vector<void*> musicchan = {};
    std::vector<int>   musicchan_size = {};
    std::vector<void*> efchan = {};
    std::vector<int>   efchan_size = {};

    AESNDPB* chans[MUS_NOCHS] = {0};
    int numplays = 0;

    u32 curvol = 255;

    static void __aesndvoicecallback(AESNDPB *pb, u32 state)
    {
        /*switch(state) {
            case VOICE_STATE_STOPPED:
                break;
            case VOICE_STATE_RUNNING:
                break;
            case VOICE_STATE_STREAM:
                break;
        }*/
    }
    void init()
    {
        // wii stuff
        AESND_Init();
        for(int i = 0; i < MUS_NOCHS; i++) {
            chans[i] = AESND_AllocateVoice(__aesndvoicecallback);
        }
        mus::stop(); // stop and init do the same type of shit
    }

    void musicvol(u32 volume) {
        curvol = volume;
        AESND_SetVoiceVolume(chans[MUS_VOICE], volume, volume);
    }

    void pushsong(void* data, u32 size) {
        musicchan.push_back(data);
        musicchan_size.push_back(size);
    }
    void pushef(void* data, u32 size) {
        efchan.push_back(data);
        efchan_size.push_back(size);
    }

    void stop()
    {
        AESND_Pause(false);
        currentsong = -1;
    }

    void processmusicfade()
    {
        musicfade--;
        if(musicfade > 0)
        {
            mus::musicvol((u32)((double)musicfade/30*255));
        }
        else
        {
            mus::stop();
        }
    }

    void processmusicfadein()
    {
        musicfadein--;
        if(musicfadein > 0)
        {
            mus::musicvol((u32)((double)(60 - musicfadein)/60*255));
        }
        else
        {
            mus::musicvol(255);
        }
    }

    void processmusic()
    {
        if(musicfade > 0)
        {
            mus::processmusicfade();
        }
        if(musicfadein > 0)
        {
            mus::processmusicfadein();
        }
    }

    void fadeout()
    {
        if(musicfade == 0)
        {
            musicfade = 31;
        }
    }

    void stopmusic()
    {
        mus::stop();
    }

    void play(int t)
    {
        if(currentsong != t)
        {
            if(currentsong != -1)
            {
                mus::stop();
            }
            if(t != -1 && t < (int)musicchan.size())
            {
                currentsong = t;
                AESND_PlayVoice(chans[MUS_VOICE], VOICE_STEREO16,
                                (void *) musicchan[currentsong], musicchan_size[currentsong],
                                48000, 0,
                                true
                                );
                musicvol(255);
            }
            else
            {
                currentsong = -1;
            }
        }
    }

    void playef(int t, int offset)
    {
        if(t == -1 || t >= (int)efchan.size() || MUS_VOICE+1+t >= MUS_NOCHS) return;

        AESND_PlayVoice(chans[MUS_VOICE+1+t], VOICE_STEREO16,
                        (void *) efchan[t], efchan_size[t],
                        48000, (u32)((double)offset/10),
                        false
        );

        AESND_SetVoiceVolume(chans[MUS_VOICE+1+t], 255, 255);
    }
}

