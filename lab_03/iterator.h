#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <memory>
#include <vector>

class BaseObject;

typedef std::vector<std::shared_ptr<BaseObject>>::iterator ObjIter;

#endif // ITERATOR_H
