#ifndef OBJECTVISITOR_H
#define OBJECTVISITOR_H

#include <memory>

#include "object/CompositeObject.h"
#include "object/point.h"
#include "object/model.h"
#include "object/basecamera.h"
#include "object/camera.h"

using namespace std;

class ObjectVisitor
{
public:
    virtual ~ObjectVisitor() = default;

    virtual void visit(shared_ptr<CompositeObject> obj) = 0;
    virtual void visit(shared_ptr<FrameModel> model) = 0;
    virtual void visit(shared_ptr<Camera> camera) = 0;
    virtual void visit(Point& point) = 0;
};

#endif // OBJECTVISITOR_H
