#include "builderimp.h"

#include <fstream>
#include "error.h"

TxtBuilderImp::TxtBuilderImp() {}

void TxtBuilderImp::buildNode(double x, double y, double z)
{
    Point point(x, y, z);
    points.push_back(point);
}

void TxtBuilderImp::loadNodes(std::ifstream &f)
{
    size_t countNodes;
    double x, y, z;

    f >> countNodes;
    if (!countNodes)
        throw LoadError("Load nodes", __FILE__, __LINE__);

    for (size_t i = 0; i < countNodes; i++)
    {
        f >> x >> y >> z;
        buildNode(x, y, z);
    }
}

void TxtBuilderImp::buildEdge(size_t s, size_t d)
{
    Edge edge{s, d};
    edges.push_back(edge);
}

void TxtBuilderImp::loadEdges(std::ifstream &f)
{
    size_t countEdges;
    size_t s, d;

    f >> countEdges;
    if (!countEdges)
        throw LoadError("Load edges", __FILE__, __LINE__);

    for (size_t i = 0; i < countEdges; i++)
    {
        f >> s >> d;
        buildEdge(s, d);
    }
}

shared_ptr<BaseObject> TxtBuilderImp::returnProduct()
{
    return shared_ptr<FrameModel>(new FrameModel(points, edges));
}
