#ifndef SCENEINTERFACE_H
#define SCENEINTERFACE_H

#include "scene.h"
#include "command/basecommand.h"
#include "command/transformcommand.h"

class SceneInterface
{
public:
    SceneInterface();

    void execute(BaseCommand &command);
private:
    shared_ptr<BaseScene> scene;
};

#endif // SCENEINTERFACE_H
