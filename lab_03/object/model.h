#ifndef MODEL_H
#define MODEL_H

#include "simpleobjects.h"
#include "point.h"

typedef struct
{
    size_t src;
    size_t dst;
} Edge;

class FrameModel : public VisibleObject
{
public:
    FrameModel() = default;
    FrameModel(const std::vector<Point> points, const std::vector<Edge> edges);
    FrameModel(const FrameModel &model);
    FrameModel(FrameModel &&model);
    ~FrameModel();

    bool isViewer();
    size_t getSize();

    std::vector<Point> getPoints() const;
    std::vector<Edge> getEdges() const;

    void addObject(shared_ptr<BaseObject> obj);
    void removeObject(ObjIter it);

    ObjIter begin();
    ObjIter end();

    void accept(ObjectVisitor *vis);

private:
    std::vector<Point> points;
    std::vector<Edge> edges;
};

#endif // MODEL_H
