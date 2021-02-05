#include "basescenemanager.h"

BaseSceneManager::BaseSceneManager(weak_ptr<BaseScene> _scene)
{
    scene = _scene;
}

