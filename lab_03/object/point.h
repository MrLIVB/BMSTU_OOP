#ifndef POINT_H
#define POINT_H

#include <math.h>
#include "baseobject.h"

class Point
{
public:
    Point();
    Point(const double x, const double y, const double z);
    Point(const Point &point);
    Point(Point &&point);
    ~Point();

    Point& operator=(const Point &point);
    Point& operator=(Point &&point);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

    void accept(ObjectVisitor *vis);

private:
    double x;
    double y;
    double z;
};

#endif // POINT_H
