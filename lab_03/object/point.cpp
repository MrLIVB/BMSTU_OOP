#include "point.h"
#include "visitor/objectvisitor.h"

Point::Point() : x(0), y(0), z(0) {}

Point::Point(const double x, const double y, const double z) : x(x), y(y), z(z) {}

Point::Point(const Point &point)
{
    x = point.x;
    y = point.y;
    z = point.z;
}

Point::Point(Point &&point)
{
    x = point.x;
    y = point.y;
    z = point.z;
}

Point::~Point() {}

Point& Point::operator =(const Point &point)
{
    x = point.getX();
    y = point.getY();
    z = point.getZ();
    return *this;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

void Point::setX(const double x)
{
    this->x = x;
}

void Point::setY(const double y)
{
    this->y = y;
}

void Point::setZ(const double z)
{
    this->z = z;
}

void Point::accept(ObjectVisitor *vis)
{
    vis->visit(*this);
}
