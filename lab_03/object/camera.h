#ifndef CAMERA_H
#define CAMERA_H

#include "basecamera.h"

class Camera : public BaseCamera
{
public:
    Camera();
    Camera(const double x, const double y, const double z);
    Camera(const Camera &camera);
    Camera(Camera &&camera);
    ~Camera();

    void accept(ObjectVisitor *vis);
};

#endif // CAMERA_H
