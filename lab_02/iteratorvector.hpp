#include "iteratorvector.h"

template <typename Type>
Iterator<Type>::Iterator(const Vector<Type> &v)
{
    arr = v.arr;
    count = v.count;
    index = 0;
}

template <typename Type>
Iterator<Type>::~Iterator()
{    
    index = 0;
    count.reset();
}

template <typename Type>
bool Iterator<Type>::operator!=(Iterator const &other) const
{
    return index != other.index;
}

template <typename Type>
bool Iterator<Type>::operator==(Iterator const &other) const
{
    return index == other.index;
}

template <typename Type>
Iterator<Type>::operator bool() const
{
    if ((index >= *count) || (index < 0) || (*count == 0))
        return false;
    else
        return true;    
}

template <typename Type>
Type &Iterator<Type>::operator*()
{
    time_t t = time(NULL);
    if (arr.expired())
        throw ExpiredPointerError("In operator *", __FILE__, __LINE__, ctime(&t));

    // Здесь добавить проверку index < count || index >= 0, или тип того, кинуть exception
    shared_ptr<Type[]> a = arr.lock();
    return a[index];
}

template <typename Type>
const Type &Iterator<Type>::operator*() const
{
    time_t t = time(NULL);
    if (arr.expired())
        throw ExpiredPointerError("In operator *", __FILE__, __LINE__, ctime(&t));

    // Здесь добавить проверку index < count || index >= 0, или тип того, кинуть exception
    shared_ptr<Type[]> a = arr.lock();
    return a[index];
}

template <typename Type>
Type *Iterator<Type>::operator->()
{
    time_t t = time(NULL);
    if (arr.expired())
        throw ExpiredPointerError("In operator ->", __FILE__, __LINE__, ctime(&t));

    // Здесь добавить проверку index < count || index >= 0, или тип того, кинуть exception
    shared_ptr<Type[]> a = arr.lock();
    return &(a[index]);
}

template <typename Type>
const Type *Iterator<Type>::operator->() const
{
    time_t t = time(NULL);
    if (arr.expired())
        throw ExpiredPointerError("In operator ->", __FILE__, __LINE__, ctime(&t));

    // Здесь добавить проверку index < count || index >= 0, или тип того, кинуть exception
    shared_ptr<Type[]> a = arr.lock();
    return &(a[index]);
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator++() noexcept
{
    index++;

    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int) noexcept
{
    Iterator<Type> it(*this);

    ++(*this);

    return it;
}