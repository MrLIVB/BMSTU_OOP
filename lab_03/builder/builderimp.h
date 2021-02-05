#ifndef BUILDERIMP_H
#define BUILDERIMP_H

#include <memory>
#include "object/baseobject.h"
#include "object/model.h"


using namespace std;
class BuilderImp
{
public:
    virtual ~BuilderImp() = default;

    virtual void loadNodes(std::ifstream &f) = 0;
    virtual void loadEdges(std::ifstream &f) = 0;

    virtual shared_ptr<BaseObject> returnProduct() = 0;
};

class TxtBuilderImp : public BuilderImp
{
public:
    TxtBuilderImp();

    void loadNodes(std::ifstream &f);
    void loadEdges(std::ifstream &f);

    shared_ptr<BaseObject> returnProduct();
protected:
    void buildNode(double x, double y, double z);
    void buildEdge(size_t s, size_t d);

private:
    vector<Point> points;
    vector<Edge> edges;
};

#endif // BUILDERIMP_H
