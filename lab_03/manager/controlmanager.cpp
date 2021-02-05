#include "controlmanager.h"
#include "object/camera.h"
#include "error.h"

LoadManager::LoadManager(weak_ptr<BaseScene> _scene, weak_ptr<BuildDirector> _dir) : BaseSceneManager(_scene),
    dir(_dir) {}

LoadManager::~LoadManager() {}

void LoadManager::execute()
{
    if (scene.expired())
        throw SceneExpiredError("DrawManager", __FILE__, __LINE__);
    scene.lock()->addObject(dir.lock()->create());
}

DrawManager::DrawManager(weak_ptr<BaseScene> scene, weak_ptr<BaseDrawerFactory> factory) :
    BaseSceneManager(scene), drawer(factory) {}

DrawManager::~DrawManager() {}

void DrawManager::execute()
{
    if (scene.expired())
        throw SceneExpiredError("DrawManager", __FILE__, __LINE__);
    if (drawer.expired())
        throw ElementExpiredError("DrawManager", __FILE__, __LINE__);
    shared_ptr<Visualizer> vis(new Visualizer());
    vis->setDrawer(*drawer.lock());
    shared_ptr<BaseCamera> can = scene.lock()->getCamera();
    vis->setCamera(scene.lock()->getCamera());

    vis->clear();
    for (auto obj: *(scene.lock()))
    {
        if (obj->isVisible())
        {
            shared_ptr<FrameModel> model = static_pointer_cast<FrameModel>(obj);
            vector<Edge> edges = model->getEdges();
            if (edges.empty())
                throw NodrawError("DrawManager", __FILE__, __LINE__);

            vector<Point> points = model->getPoints();
            for (size_t i = 0; i < edges.size(); i++)
            {
                const Point src = points[edges[i].src];
                const Point dst = points[edges[i].dst];
                vis->drawLine(src.getX(), src.getY(), src.getZ(), \
                              dst.getX(), dst.getY(), dst.getZ());
            }
        }
    }
}
