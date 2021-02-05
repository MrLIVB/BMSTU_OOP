#ifndef BASESCENE_H
#define BASESCENE_H

#include <iostream>
#include <memory>
#include <vector>

#include "iterator.h"
#include "object/basecamera.h"
#include "object/baseobject.h"

class BaseScene
{
public:
    BaseScene() = default;

    virtual ObjIter begin() = 0;
    virtual ObjIter end() = 0;

    virtual std::shared_ptr<BaseCamera> getCamera() = 0;
    virtual void setCamera(ObjIter it) = 0;

    virtual void addObject(const std::shared_ptr<BaseObject>& obj) = 0;
    virtual void removeObject(ObjIter it) = 0;

protected:
    std::vector<std::shared_ptr<BaseObject>> objects;
    int currentCameraIndex = 0;
};

#endif // BASESCENE_H
