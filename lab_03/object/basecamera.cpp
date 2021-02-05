#include "basecamera.h"
#include "visitor/objectvisitor.h"

bool BaseCamera::isViewer()
{
    return true;
}

BaseCamera::BaseCamera() : x(0), y(0), z(0) {}

BaseCamera::BaseCamera(const double x, const double y, const double z) : x(x), y(y), z(z) {}

BaseCamera::BaseCamera(const BaseCamera &camera)
{
    x = camera.x;
    y = camera.y;
    z = camera.z;
}

BaseCamera::BaseCamera(BaseCamera &&camera)
{
    x = camera.x;
    y = camera.y;
    z = camera.z;
}

BaseCamera::~BaseCamera()
{
    x = 0;
    y = 0;
    z = 0;
}

double BaseCamera::getX() const
{
    return x;
}

double BaseCamera::getY() const
{
    return y;
}

double BaseCamera::getZ() const
{
    return z;
}

void BaseCamera::setX(const double x)
{
    this->x = x;
}

void BaseCamera::setY(const double y)
{
    this->y = y;
}

void BaseCamera::setZ(const double z)
{
    this->z = z;
}

size_t BaseCamera::getSize() {return 0;}
void BaseCamera::addObject(shared_ptr<BaseObject> obj) {}
void BaseCamera::removeObject(ObjIter it) {}
ObjIter BaseCamera::begin() {}
ObjIter BaseCamera::end() {}
