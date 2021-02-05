#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "simpleobjects.h"

class BaseCamera : public InvisibleObject
{
public:
    BaseCamera();
    BaseCamera(const double x, const double y, const double z);
    BaseCamera(const BaseCamera &camera);
    BaseCamera(BaseCamera &&camera);
    ~BaseCamera();

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

    bool isViewer() override;

    size_t getSize();
    void addObject(shared_ptr<BaseObject> obj);
    void removeObject(ObjIter it);
    ObjIter begin();
    ObjIter end();

protected:
    double x;
    double y;
    double z;
};

#endif // BASECAMERA_H
