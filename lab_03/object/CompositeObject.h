#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include "baseobject.h"

using namespace std;

class CompositeObject : public BaseObject
{
public:
    CompositeObject();
    bool isComposite() override;
    size_t getSize() override;
    void addObject(shared_ptr<BaseObject> obj) override;
    void removeObject(ObjIter it) override;

    ObjIter begin() override;
    ObjIter end() override;

    void accept(ObjectVisitor *vis) override;
private:
    vector<shared_ptr<BaseObject>> objects;
};

#endif // COMPOSITEOBJECT_H
