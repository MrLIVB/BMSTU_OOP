#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>

#include "errors.h"
#include "iteratorvector.hpp"
#include "constiterator.hpp"

using namespace std;
class BaseVector
{
public:
    BaseVector(size_t size = 0) { count = shared_ptr<size_t>(new size_t(size)); }
    ~BaseVector() {};

    virtual size_t size() const = 0;
    virtual operator bool() const = 0;
    virtual bool isEmpty() const = 0;

protected:
    shared_ptr<size_t> count;
};


template <typename Type>
class Vector : public BaseVector
{
public:
    // Конструкторы:
    Vector() = default;
    explicit Vector(size_t N);
    explicit Vector(Vector<Type> &vec);
    Vector(initializer_list<Type> list);
    Vector(Iterator<Type> first, Iterator<Type> last);
    Vector(const Type* arr, size_t n);
    Vector(const Type &element, size_t n);
    Vector(Vector<Type> &&vec) noexcept;

    // Деструктор
    virtual ~Vector();

    Vector<Type> &operator=(const Vector<Type> &vec);
    Vector<Type> &setValue(const Vector<Type> &vec);

    Vector<Type> &operator=(Vector<Type> &&vec);
    Vector<Type> &setValue(Vector<Type> &&vec);

    Vector<Type> &operator=(initializer_list<Type> list);
    Vector<Type> &setValue(initializer_list<Type> list);

    Vector<Type> operator+(const Vector<Type> &vec) const;
    Vector<Type> addVector(const Vector<Type> &vec) const;

    Vector<Type> &operator+=(const Vector<Type> &vec);
    Vector<Type> &addVectorAssign(const Vector<Type> &vec);

    Vector<Type> operator-(const Vector<Type> &vec) const;
    Vector<Type> substractVector(const Vector<Type> &vec) const;

    Vector<Type> &operator-=(const Vector<Type> &vec);
    Vector<Type> &substractVectorAssign(const Vector<Type> &vec);

    Type operator*(const Vector<Type> &vec) const;
    Type dotProduct(const Vector<Type> &vec) const;

    Vector<Type> operator*(const Type &mult) const;
    Vector<Type> multiplyBy(const Type &mult) const;

    Vector<Type> &operator*=(const Type &mult);
    Vector<Type> &multiplyByAssign(const Type &mult);

    Vector<Type> operator/(const Type &divider) const;
    Vector<Type> divideBy(const Type &divider) const;

    Vector<Type> &operator/=(const Type &divider);
    Vector<Type> &divideByAssign(const Type &divider);

    double angleBetween(const Vector<Type> &vec) const;
    bool isCollinear(const Vector<Type> &vec) const;
    bool isOrthogonal(const Vector<Type> &vec) const;

    bool isUnit() const;
    bool isZero() const;

    Vector<Type> &normalize();
    double length() const;

    bool operator==(const Vector<Type> &vec) const;
    bool isEqual(const Vector<Type> &vec) const;

    bool operator!=(const Vector<Type> &vec) const;
    bool isNotEqual(const Vector<Type> &vec) const;

    virtual size_t size() const;
    virtual operator bool() const;
    virtual bool isEmpty() const;

    Type &operator[](int ind);
    const Type &operator[](int ind) const { return arr[ind]; };

    Type &get(size_t ind);
    const Type &get(size_t ind) const;

    Vector<Type> &set(const Type &element, size_t ind);

    Vector<Type>& clear();

    Iterator<Type> begin() { return Iterator<Type>(arr, count); }
    ConstIterator<Type> begin() const { return ConstIterator<Type>(arr, count); }
    Iterator<Type> end() { return Iterator<Type>(arr, count, *count); }
    ConstIterator<Type> end() const { return ConstIterator<Type>(arr, count, *count); }

    ConstIterator<Type> c_begin() const { return ConstIterator<Type>(arr, count); }
    ConstIterator<Type> c_end() const { return ConstIterator<Type>(arr, count, *count); }

    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

protected:
    void vectorsSum(Vector<Type> &result, const Vector<Type> &vec1, const Vector<Type> &vec2) const;
    void vectorsDiff(Vector<Type> &result, const Vector<Type> &vec1, const Vector<Type> &vec2) const;
    void vectorMultNumber(Vector<Type> &result, const Type &number) const;
    bool compare(const Vector<Type> &vec2) const;

    Vector<Type> &resize(size_t N); // по поводу этого он сказал, что ненужно, но не знаю, как присваивать без него

private:
    shared_ptr<Type[]> arr{nullptr};
};

#endif // !VECTOR_H