#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "map.h"
#include "gameclass.h"

#include "ent.h"
#include "simpleent.h"
#include "blockclass.h"
#include "flashgeom.h"


#define BLOCK 0
#define TRIGGER 1
#define DAMAGE 2

class entityclass
{
public:
    int z;

    int activetrigger;

    // stupid temporaries
    int temp, temp2;
    int tpx1, tpx2;
    int tpy1, tpy2;
    int i, j, k;
    int tempx, tempy;
    int tempw, temph;

    Point colpoint1 = {0}, colpoint2 = {0};
    Rectangle temprect = {0}, temprect2 = {0};

    std::vector<entclass> entities = {};
    //int nentity; // obsolete??? vector::size()?

    std::vector<simpleentclass> simpleentities = {};
    //int nsimpleentity; // obsolete??? vector::size()?

    std::vector<blockclass> blocks = {};
    //int nblocks; // obsolete??? vector::size()?
    //#if 0
    void removeblock(int t);

    bool updateentities(int i, gameclass* game);

    void removeblockat(int x, int y);

    bool checkblocks();

    void createblock(int t, int xp = 0, int yp = 0, int w = 0, int h = 0, int trig = 0);

    bool gettype(int t);

    void animateentities(int i);

    void cleanup();

    int checktrigger();
    void removetrigger(int t);

    int getplayer();

    void entitymapcollision(mapclass* map, int t);


    void entitycollisioncheck(gameclass* game, mapclass* map);

    bool testwallsx(mapclass* map, int t, int tx, int ty);
    bool testwallsy(mapclass* map, int t, int tx, int ty);

    bool checkwall(mapclass* map);

    void createentity(double xp, double yp, int t, double vx = 0, double vy = 0, int para = 0);
    void createsimpleentity(double xp, double yp, double vx = 0, double vy = 0, int t = 0, int size = 0, int life = 0, int c = 0);

    void removeallblocks();

    void applyfriction(int t, double xrate, double yrate);

    bool entitycollidefloor(mapclass* map, int t);

    int getgridpoint(int t);

    void updateentitylogic(int t);
    bool checkdamage();
    bool entitycollide(int a, int b);

    bool updatesimpleentities(int t);
    void rectset (int xi, int yi, int wi, int hi);
    void rect2set(int xi, int yi, int wi, int hi);
    //#endif
};

#endif
