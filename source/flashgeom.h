#ifndef FLASHGEOM_H
#define FLASHGEOM_H

class Point {
public:
    double x, y;
    Point(double x, double y);
};

class Rectangle {
public:
    double x, y, width, height;
    Rectangle(double x, double y, double width, double height);

    bool contains(double x, double y);
    bool containsPoint(Point point);
    bool intersects(Rectangle rect);
};

#endif
