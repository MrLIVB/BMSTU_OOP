#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <memory>
#include "object/baseobject.h"
#include "object/model.h"
#include "builderimp.h"


using namespace std;
class BuilderAbstraction
{
public:
    BuilderAbstraction(shared_ptr<BuilderImp> _imp) : imp(_imp) {}
    virtual ~BuilderAbstraction() = default;

    virtual shared_ptr<BaseObject> getProduct() = 0;

protected:
    shared_ptr<BuilderImp> imp;
};

class BaseModelBuilder : public BuilderAbstraction
{
public:
    BaseModelBuilder(shared_ptr<BuilderImp> _imp) : BuilderAbstraction(_imp) {}

    virtual void loadNodes(std::ifstream &f) = 0;
    virtual void loadEdges(std::ifstream &f) = 0;

protected:
    shared_ptr<FrameModel> model;
};

class TxtModelBuilder : public BaseModelBuilder
{
public:
    TxtModelBuilder(shared_ptr<BuilderImp> _imp);

    void loadNodes(std::ifstream &f) override;
    void loadEdges(std::ifstream &f) override;
    shared_ptr<BaseObject> getProduct() override;
};

#endif // BASEBUILDER_H
