#ifndef BASESCENEMANAGER_H
#define BASESCENEMANAGER_H

#include <memory>
#include "scene/scene.h"

using namespace std;

class BaseSceneManager
{
public:
    BaseSceneManager(weak_ptr<BaseScene> _scene);

protected:
    weak_ptr<BaseScene> scene;
};

#endif // BASESCENEMANAGER_H
