#ifndef ITERATORVECTOR_H
#define ITERATORVECTOR_H

#include <memory>
#include <iterator>

using namespace std;

template <typename Type> class Vector;

template <typename Type>
class Iterator : public iterator<input_iterator_tag, Type>
{
    friend class Vector<Type>;

private:
    Iterator(const shared_ptr<Type[]> &a, const shared_ptr<size_t> &c, size_t ind = 0) : arr(a), count(c), index(ind){};

public:
    Iterator(const Vector<Type> &v);
    Iterator(const Iterator<Type> &it) = default;
    ~Iterator();

    bool operator!=(Iterator const &other) const;
    bool operator==(Iterator const &other) const;
    operator bool() const;

    Type &operator*();    
    Type *operator->();

    const Type &operator*() const;
    const Type *operator->() const;

    Iterator<Type> &operator++() noexcept;
    Iterator<Type> operator++(int) noexcept;

private:
    weak_ptr<Type[]> arr;
    shared_ptr<size_t> count; // можно заменить просто на size_t
    size_t index = 0;
};

#endif // !ITERATORVECTOR_H