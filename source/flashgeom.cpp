// Some of this code is taken from the openfl project to ensure it correctly detects collision.
// OpenFL is licensed under MIT at the current time of this writing.
// You can view the license here: https://github.com/openfl/openfl/blob/develop/LICENSE.md
// As the license's terms' use dubious wording "substancial portions" I decided I'd be better safe then sorry.

#include "flashgeom.h"

bool Rectangle::contains(double x, double y)
{
    return x >= this->x && y >= this->y && x < (this->x+this->width) && y < (this->y+this->height);
}

bool Rectangle::containsPoint(Point point) {
    return this->contains(point.x, point.y);
}

bool Rectangle::intersects(Rectangle rect) {
    double x0 = this->x < rect.x ? rect.x : this->x;
    double x1 = (this->x+this->width) > (rect.x+rect.width) ? (rect.x+rect.width) : (this->x+this->width);

    if (x1 <= x0)
    {
        return false;
    }

    double y0 = this->y < rect.y ? rect.y : this->y;
    double y1 = (this->y+this->height) > (rect.y+rect.height) ? (rect.y+rect.height) : (this->y+this->height);

    return y1 > y0;
}
