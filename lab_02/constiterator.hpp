#include "constiterator.h"

template <typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &v)
{
    arr = v.arr;
    count = v.count;
    index = 0;
}

template <typename Type>
ConstIterator<Type>::~ConstIterator()
{
    index = 0;
    count.reset();
}

template <typename Type>
bool ConstIterator<Type>::operator!=(ConstIterator const &other) const
{
    return index != other.index;
}

template <typename Type>
bool ConstIterator<Type>::operator==(ConstIterator const &other) const
{
    return index == other.index;
}

template <typename Type>
const Type &ConstIterator<Type>::operator*() const
{
    time_t t = time(NULL);
    if (arr.expired())
        throw ExpiredPointerError("In operator *", __FILE__, __LINE__, ctime(&t));

    // Здесь добавить проверку index < count || index >= 0, или тип того, кинуть exception
    shared_ptr<Type[arr]> a(arr);
    return a[index];
}

template <typename Type>
const Type *ConstIterator<Type>::operator->() const
{
    time_t t = time(NULL);
    if (arr.expired())
        throw ExpiredPointerError("In operator ->", __FILE__, __LINE__, ctime(&t));

    // Здесь добавить проверку index < count || index >= 0, или тип того, кинуть exception
    shared_ptr<Type[arr]> a(arr);
    return &a[index];
}

template <typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator++() noexcept
{
    index++;

    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int) noexcept
{
    ConstIterator<Type> it(*this);

    ++(*this);

    return it;
}