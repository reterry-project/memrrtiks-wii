#include "ent.h"

void entclass::clear()
{
    active = false;
    invis = false;
    type = 0;
    size = 0;
    //tile = 0;
    rule = 0;
    state = 0;
    statedelay = 0;
    life = 0;
    colour = 0;
    para = 0;
    behave = 0;
    animate = 0;
    xp = 0;
    yp = 0;
    ax = 0;
    ay = 0;
    vx = 0;
    vy = 0;
    w = 32;
    h = 32;
    cx = 0;
    cy = 0;
    newxp = 0;
    newyp = 0;
    x1 = 0;
    y1 = 0;
    x2 = 320;
    y2 = 240;
    jumping = false;
    gravity = false;
    onground = 0;
    onroof = 0;
    jumpframe = 0;
    onentity = 0;
    harmful = false;
    onwall = 0;
    onxwall = 0;
    onywall = 0;
    isplatform = false;
    framedelay = 0;
    drawframe = 0;
    walkingframe = 0;
    dir = 0;
    actionframe = 0;
}

