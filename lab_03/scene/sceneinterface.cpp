#include "sceneinterface.h"

SceneInterface::SceneInterface()
{
    scene = shared_ptr<BaseScene>(new Scene());
}

void SceneInterface::execute(BaseCommand &command)
{
    command.execute(this->scene);
}
