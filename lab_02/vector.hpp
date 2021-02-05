#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include <ctime>
#include <math.h>

#include "vector.h"

#define EPS 1e-7

using namespace std;


#pragma region Initializers
template <typename Type>
Vector<Type>::Vector(size_t N)
{
    time_t t = time(NULL);
    if (!(*count = N))
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), N);

    arr = shared_ptr<Type[]>(new Type[*count]);
    if (!arr)
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), N);

    for (size_t i = 0; i < N; i++)
        arr[i] = 0;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &vec)
{
    time_t t = time(NULL);
    if (!(*count = *(vec.count)))
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), *(vec.count));

    arr = shared_ptr<Type[]>(new Type[*count]);
    if (!arr)
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), *(vec.count));

    size_t i = 0;
    for (Type elem : vec)
        arr[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vec) noexcept
{
    count = vec.count;
    vec.count.reset();

    arr = vec.arr;
    vec.arr.reset();
}

template <typename Type>
Vector<Type>::Vector(initializer_list<Type> list)
{
    time_t t = time(NULL);
    if (!(*count = list.size()))
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), list.size());

    arr = shared_ptr<Type[]>(new Type[*count]);
    if (!arr)
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), list.size());

    size_t i = 0;
    for (Type elem : list)
        arr[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(Iterator<Type> first, Iterator<Type> last)
{
    time_t t = time(NULL);
    if (first.count.expired())
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), 0);

    shared_ptr<size_t> tmp_count = first.count.lock();
    if (!(*count = *tmp_count))
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), *tmp_count);

    arr = shared_ptr<Type[]>(new Type[*count]);
    if (!arr)
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), *tmp_count);

    size_t i = 0;
    for (;first != last; first++)
        arr[i++] = *first;
}

template <typename Type>
Vector<Type>::Vector(const Type* arr, size_t N)
{
    time_t t = time(NULL);
    if (!(*count = N))
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), N);

    arr = shared_ptr<Type[]>(new Type[N]);
    if (!arr)
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), N);

    size_t i = 0;
    for (Type elem: arr)
        arr[i++] = elem;
}

template<typename Type>
Vector<Type>::Vector(const Type &element, size_t N)
{
    time_t t = time(NULL);
    *count = N;
    if (!(*count = N))
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), N);

    arr = shared_ptr<Type[]>(new Type[N]);
    if (!arr)
        throw AllocationError("Initialization: ", __FILE__, __LINE__, ctime(&t), N);

    for (size_t i = 0; i < N; i++)
        arr[i] = element;
}

#pragma endregion

template<typename Type>
Vector<Type>::~Vector()
{
    if (arr)
        arr.reset();
    if (count)
        count.reset();
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vec)
{
    if (length() != vec.length())
        resize(vec.length());
    size_t i = 0;

    for (auto elem: vec)
        arr[i++] = elem;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::setValue(const Vector<Type> &vec)
{
    if (length() != vec.length())
        resize(vec.length());
    size_t i = 0;

    for (auto elem : vec)
        arr[i++] = elem;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vec)
{
    arr = vec.arr;
    vec.arr.reset();
    count = vec.count;
    vec.count.reset();
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::setValue(Vector<Type> && vec)
{
    arr = vec.arr;
    vec.arr.reset();
    count = vec.count;
    vec.count.reset();
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(initializer_list<Type> list)
{
    *count = list.size;
    resize(*count);

    size_t i = 0;
    for (auto elem : list)
        arr[i] = elem;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::setValue(initializer_list<Type> list)
{
    *count = list.size;
    resize(*count);

    size_t i = 0;
    for (auto elem : list)
        arr[i] = elem;

    return *this;
}

template <typename Type>
Type &Vector<Type>::operator[](int ind) 
{ 
    return arr[ind]; 
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vec) const
{
    size_t maxLen = max(*count, *vec.count);
    Vector<Type> res(maxLen);

    vectorsSum(res, *this, vec);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::addVector(const Vector<Type> &vec) const
{
    size_t maxLen = max(*count, *vec.count);
    Vector<Type> res(maxLen);

    vectorsSum(res, *this, vec);

    return res;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vec)
{
    if (*count < *vec.count)
        resize(*vec.count);
    
    vectorsSum(*this, *this, vec);

    return *this;
}
template <typename Type>
Vector<Type> &Vector<Type>::addVectorAssign(const Vector<Type> &vec)
{
    if (*count < *vec.count)
        resize(*vec.count);

    vectorsSum(*this, *this, vec);

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vec) const
{
    size_t maxLen = max(*count, *vec.count);
    Vector<Type> res(maxLen);

    vectorsDiff(res, *this, vec);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::substractVector(const Vector<Type> &vec) const
{
    size_t maxLen = max(*count, *vec.count);
    Vector<Type> res(maxLen);

    vectorsDiff(res, *this, vec);

    return res;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vec)
{
    if (*count < *vec.count)
        resize(*vec.count);

    vectorsDiff(*this, *this, vec);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::substractVectorAssign(const Vector<Type> &vec)
{
    if (*count < *vec.count)
        resize(*vec.count);

    vectorsDiff(*this, *this, vec);

    return *this;
}

template <typename Type>
Type Vector<Type>::operator*(const Vector<Type> &vec) const
{
    Type res = 0;

    size_t minLen = min(*count , *vec.count);
    for (size_t i = 0; i < minLen; i++)
        res += (*this)[i] * vec[i];

    return res;
}


template <typename Type>
Type Vector<Type>::dotProduct(const Vector<Type> &vec) const
{
    Type res = 0;

    size_t minLen = min(*count, *vec.count);
    for (size_t i = 0; i < minLen; i++)
        res += (*this)[i] * vec[i];

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(const Type &mult) const
{
    Vector<Type> res(*count);
    vectorMultNumber(res, mult);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::multiplyBy(const Type &mult) const
{
    Vector<Type> res(*count);
    vectorMultNumber(res, mult);

    return res;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &mult)
{
    vectorMultNumber(*this, mult);
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::multiplyByAssign(const Type &mult)
{
    vectorMultNumber(*this, mult);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator/(const Type &divider) const
{
    time_t t = time(NULL);
    if (divider == 0)
        throw ZeroDivisionError("In operator /", __FILE__, __LINE__, ctime(&t));

    return *this * (1 / divider);
}

template <typename Type>
Vector<Type> Vector<Type>::divideBy(const Type &divider) const
{
    time_t t = time(NULL);
    if (divider == 0)
        throw ZeroDivisionError("In Function divideBy()", __FILE__, __LINE__, ctime(&t));

    return *this * (1 / divider);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &divider)
{
    time_t t = time(NULL);
    if (divider == 0)
        throw ZeroDivisionError("In operator /=", __FILE__, __LINE__, ctime(&t));

    *this *= (1 / divider);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::divideByAssign(const Type &divider)
{
    time_t t = time(NULL);
    if (divider == 0)
        throw ZeroDivisionError("In Function divideByAssign()", __FILE__, __LINE__, ctime(&t));

    *this *= (1 / divider);

    return *this;
}

template <typename Type>
double Vector<Type>::angleBetween(const Vector<Type> &vec) const
{
    time_t t = time(NULL);
    if (length() < EPS || vec.length() < EPS)
        throw ZeroDivisionError("In Function angleBetween()", __FILE__, __LINE__, ctime(&t));

    return acos((*this * vec) / (length() * vec.length()));
}

template <typename Type>
bool Vector<Type>::isCollinear(const Vector<Type> &vec) const
{
    if (angleBetween(vec) < EPS)
        return true;
    else
        return false;
}

template <typename Type>
bool Vector<Type>::isOrthogonal(const Vector<Type> &vec) const
{
    if (dotProduct(vec) < EPS)
        return true;
    else
        return false;
}

template <typename Type>
bool Vector<Type>::isUnit() const
{
    return bool(length - 1 < EPS);
}

template <typename Type>
bool Vector<Type>::isZero() const
{
    Iterator<Type> iter(*this);
    bool res = true;
    for (; iter && res; iter++)
        res = bool(*iter == 0);
    
    return res;
}

template <typename Type>
Vector<Type> &Vector<Type>::normalize()
{
    time_t t = time(NULL);
    double len = length();
    if (len < EPS)
        throw ZeroDivisionError("In Function normalize()", __FILE__, __LINE__, ctime(&t));

    *this /= len;
    return *this;
}

template <typename Type>
size_t Vector<Type>::size() const
{
    return *count;
}

template <typename Type>
Vector<Type>::operator bool() const
{
    return bool(*count);
}

template <typename Type>
bool Vector<Type>::isEmpty() const
{
    return !bool(*count);
}

template <typename Type>
double Vector<Type>::length() const
{
    Type res = 0;

    Iterator<Type> iter(*this);
     for (; iter; iter++)
        res += *iter * *iter;

    return sqrt(res);
}

template <typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vec) const
{
    return compare(vec);
}

template <typename Type>
bool Vector<Type>::isEqual(const Vector<Type> &vec) const
{
    return compare(vec);
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &vec) const
{
    return !compare(vec);
}

template <typename Type>
bool Vector<Type>::isNotEqual(const Vector<Type> &vec) const
{
    return !compare(vec);
}

template <typename Type>
Vector<Type> &Vector<Type>::clear()
{
    arr.reset();
    *count = 0;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::set(const Type &element, size_t ind)
{
    if (ind < 0 || ind > *count)
    {
        time_t t = time(NULL);
        throw IndexError("In set: ", __FILE__, __LINE__, ctime(&t), ind);
    }

    arr[ind] = element;
    return *this;
}

template <typename Type>
Type &Vector<Type>::get(size_t ind)
{
    if (ind < 0 || ind > *count)
    {
        time_t t = time(NULL);
        throw IndexError("In set: ", __FILE__, __LINE__, ctime(&t), ind);
    }

    return arr[ind];
}

template <typename Type>
const Type &Vector<Type>::get(size_t ind) const
{
    if (ind < 0 || ind > *count)
    {
        time_t t = time(NULL);
        throw IndexError("In set: ", __FILE__, __LINE__, ctime(&t), ind);
    }

    return arr[ind];
}

template <typename Type>
Vector<Type> &Vector<Type>::resize(size_t N)
{
    time_t t = time(NULL);
    size_t tmp_count = min(*count, N);
    
    if (!(*count = N))
        throw AllocationError("Resize: ", __FILE__, __LINE__, ctime(&t), N);

    shared_ptr<Type[]> tmp(arr);
    arr = shared_ptr<Type[]>(new Type[*count]);
    if (!arr)
        throw AllocationError("Resize: ", __FILE__, __LINE__, ctime(&t), N);

    for (size_t i = 0; i < tmp_count; i++)
        arr[i] = tmp[i];

    tmp = nullptr;
    return *this;
}

template <typename Type>
void Vector<Type>::vectorsSum(Vector<Type> &result, const Vector<Type> &vec1, const Vector<Type> &vec2) const
{
    Iterator<Type> iter1(vec1);
    Iterator<Type> iter2(vec2);
    Iterator<Type> iterRes(result);

    for (size_t i = 0; iterRes; i++, iter1++, iter2++, iterRes++)
    {
        if (i >= *iter1.count)
            *iterRes = *iter2;
        else if (i >= *iter2.count)
            *iterRes = *iter1;
        else
            *iterRes = *iter1 + *iter2;
    }
}

template <typename Type>
void Vector<Type>::vectorsDiff(Vector<Type> &result, const Vector<Type> &vec1, const Vector<Type> &vec2) const
{
    Iterator<Type> iter1(vec1);
    Iterator<Type> iter2(vec2);
    Iterator<Type> iterRes(result);

    for (size_t i = 0; iterRes; i++, iter1++, iter2++, iterRes++)
    {
        if (i >= *iter1.count)
            *iterRes = -*iter2;
        else if (i >= *iter2.count)
            *iterRes = *iter1;
        else
            *iterRes = *iter1 - *iter2;
    }
}

template <typename Type>
void Vector<Type>::vectorMultNumber(Vector<Type> &result, const Type &number) const
{ 
    Iterator<Type> iter(*this);
    Iterator<Type> iterRes(result);

    for (;iter; iter++, iterRes++)
        *iterRes = *iter * number;
}

template <typename Type>
bool Vector<Type>::compare(const Vector<Type> &vec2) const
{
    if (*count != *vec2.count)
        return false;

    bool result = true;

    Iterator<Type> iterThis(*this);
    Iterator<Type> iterOther(vec2);
    for (; iterThis && result; iterThis++, iterOther++)
        result = *iterThis == *iterOther;
    
    return result;
}

template <typename Type>
ostream& operator<<(ostream& os, Vector<Type> &vec)
{
    for (auto el : vec)
        os << el << " ";
    return os;
}

#endif // !VECTOR_HPP