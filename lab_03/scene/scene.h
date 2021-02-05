#ifndef SCENE_H
#define SCENE_H

#include "basescene.h"
#include "object/camera.h"

class Scene : public BaseScene
{
public:
    Scene();

    size_t getSize();

    ObjIter begin() override;
    ObjIter end() override;

    std::shared_ptr<BaseCamera> getCamera();
    void setCamera(ObjIter it);

    void addObject(const std::shared_ptr<BaseObject>& obj);
    void removeObject(ObjIter it);
};

#endif // SCENE_H
