#include "model.h"

FrameModel::FrameModel(const std::vector<Point> points, const std::vector<Edge> edges)
{
    this->points = points;
    this->edges = edges;
}

FrameModel::FrameModel(const FrameModel &model)
{
    this->points = model.getPoints();
    this->edges = model.getEdges();
}

FrameModel::FrameModel(FrameModel &&model)
{
    this->points = model.getPoints();
    this->edges = model.getEdges();
}

FrameModel::~FrameModel() {}

bool FrameModel::isViewer()
{
    return false;
}

size_t FrameModel::getSize()
{
    return points.size();
}

ObjIter FrameModel::begin() {}

ObjIter FrameModel::end() {}

void FrameModel::addObject(shared_ptr<BaseObject> obj) {}

void FrameModel::removeObject(ObjIter it) {}

std::vector<Point> FrameModel::getPoints() const
{
    return this->points;
}

std::vector<Edge> FrameModel::getEdges() const
{
    return this->edges;
}

void FrameModel::accept(ObjectVisitor *vis)
{
    for (size_t i = 0; i < points.size(); i++)
        points[i].accept(vis);
}
