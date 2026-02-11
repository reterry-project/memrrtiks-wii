#ifndef FLASHGEOM_H
#define FLASHGEOM_H

class Point {
public:
    double x, y;
};

class Rectangle {
public:
    double x, y, width, height;

    bool contains(double x, double y);
    bool containsPoint(Point point);
    bool intersects(Rectangle rect);
};

#endif
