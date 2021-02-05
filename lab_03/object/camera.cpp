#include "camera.h"
#include "visitor/objectvisitor.h"

Camera::Camera(const double x, const double y, const double z) : BaseCamera(x, y, z) {}

Camera::Camera(const Camera &camera) : BaseCamera(camera) {}

Camera::~Camera() {}

void Camera::accept(ObjectVisitor *vis)
{
    vis->visit(shared_ptr<Camera>(this));
}
