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
    ~BaseVector(){};

    virtual size_t size() = 0;
    virtual operator bool() = 0;
    virtual bool isEmpty() = 0;

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
    Vector(const Type *arr, size_t n);
    Vector(const Type &element, size_t n);
    Vector(Vector<Type> &&vec) noexcept; // изм. реализ.

    // Деструктор
    virtual ~Vector();

    // Операторы
    Vector<Type> &operator+(const Vector<Type> &other); // изм. реализ.
    Vector<Type> &operator+(const Type a);

    Vector<Type> &operator=(const Vector<Type> &vec);
    Vector<Type> &operator=(Vector<Type> &&vec);
    // initializer_list

    Vector<Type> &operator+=(const Vector<Type> &vec);
    Vector<Type> &operator+=(const Type element);

    template <typename T>
    friend bool operator==(const Vector<T> &v1, const Vector<T> &v2);
    template <typename T>
    friend bool operator!=(const Vector<T> &v1, const Vector<T> &v2);

    Type &operator[](int ind);
    const Type &operator[](int ind) const { return arr[ind]; };

    // Методы
    virtual size_t size();
    virtual operator bool();
    virtual bool isEmpty();

    Vector<Type> &resize(size_t N);
    int length() const;

    Vector<Type> &set(const Type &element, size_t ind);

    Type &get(size_t ind);

    Vector<Type> &append(const Vector<Type> &vec);
    Vector<Type> &append(const Type &element);

    Vector<Type> &insert(const Vector<Type> &vec, size_t pos);
    Vector<Type> &insert(const Type &element, size_t pos);

    Vector<Type> &pushBack(const Vector<Type> &vec);
    Vector<Type> &pushBack(const Type &element);

    Vector<Type> &pushFront(const Vector<Type> &vec);
    Vector<Type> &pushFront(const Type &element);

    Type pop(size_t N);
    Type popBack();
    Type popFront();
    Vector<Type> &clear();
    Type first() { return arr[0]; }
    Type last() { return arr[*count - 1]; }

    Iterator<Type> begin() const { return Iterator<Type>(arr, count); }
    Iterator<Type> end() const { return Iterator<Type>(arr, count, *count); }

    ConstIterator<Type> c_begin() const { return ConstIterator<Type>(arr, count); }
    ConstIterator<Type> c_end() const { return ConstIterator<Type>(arr, count, *count); }

protected:
    Vector<Type> &addLast(const Vector<Type> &vec);
    Vector<Type> &addLast(const Type &element);

private:
    shared_ptr<Type[]> arr{nullptr};
};

#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include <ctime>

#include "vector.h"

using namespace std;

template <typename Type>
Vector<Type>::Vector(size_t N)
{
    time_t t = time(NULL);
    if (!(*count = N))
        throw AllocationError("Initialization: ", ctime(&t));

    arr = shared_ptr<Type[]>(new Type[*count]);

    for (size_t i = 0; i < N; i++)
        arr[i] = 0;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &vec)
{
    time_t t = time(NULL);
    if (!(*count = *(vec.count)))
        throw AllocationError("Initialization: ", ctime(&t));

    arr = shared_ptr<Type[]>(new Type[*count]);
    size_t i = 0;
    for (Type elem : vec)
        arr[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vec) noexcept
{
    time_t t = time(NULL);
    if (!(*count = *(vec.count)))
        throw AllocationError("Initialization: ", ctime(&t));

    arr = shared_ptr<Type[]>(new Type[*count]);

    size_t i = 0;
    for (Type elem : vec)
        arr[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(initializer_list<Type> list)
{
    time_t t = time(NULL);
    if (!(*count = list.size()))
        throw AllocationError("Initialization: ", ctime(&t));

    arr = shared_ptr<Type[]>(new Type[*count]);

    size_t i = 0;
    for (Type elem : list)
        arr[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(Iterator<Type> first, Iterator<Type> last)
{
    time_t t = time(NULL);
    if (!(*count = first.count))
        throw AllocationError("Initialization: ", ctime(&t));

    arr = shared_ptr<Type[]>(new Type[*count]);

    size_t i = 0;
    for (; first != last; first++)
        arr[i++] = *first;
}

template <typename Type>
Vector<Type>::Vector(const Type *arr, size_t N)
{
    time_t t = time(NULL);
    if (!(*count = N))
        throw AllocationError("Initialization: ", ctime(&t));

    arr = shared_ptr<Type[]>(new Type[N]);

    size_t i = 0;
    for (Type elem : arr)
        arr[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(const Type &element, size_t N)
{
    time_t t = time(NULL);
    *count = N;
    if (!(*count = N))
        throw AllocationError("Initialization: ", ctime(&t));
    arr = shared_ptr<Type[]>(new Type[N]);

    for (size_t i = 0; i < N; i++)
        arr[i] = element;
}

template <typename Type>
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
    for (auto elem : vec)
        arr[i++] = elem;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vec)
{
    arr = vec.arr;
    count = vec.count;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vec)
{
    return addLast(vec);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type element)
{
    return addLast(element);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+(const Vector<Type> &other)
{

    return addLast(other);
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+(const Type element)
{
    return addLast(element);
}

template <typename Type>
bool operator==(const Vector<Type> &v1, const Vector<Type> &v2)
{
    if (v1.length() != v2.length())
        return false;

    bool res = true;
    for (size_t i = 0; i < v1.length(); i++)
        if (v1[i] != v2[i])
            res = false;

    return res;
}

template <typename Type>
bool operator!=(const Vector<Type> &v1, const Vector<Type> &v2)
{
    if (v1.length() != v2.length())
        return false;

    bool res = true;
    for (size_t i = 0; i < v1.length(); i++)
        if (v1[i] == v2[i])
            res = false;

    return res;
}

template <typename Type>
Type &Vector<Type>::operator[](int ind)
{
    return arr[ind];
}

template <typename Type>
size_t Vector<Type>::size()
{
    return *count;
}

template <typename Type>
Vector<Type>::operator bool()
{
    return bool(*count);
}

template <typename Type>
bool Vector<Type>::isEmpty()
{
    return !bool(*count);
}

template <typename Type>
int Vector<Type>::length() const
{
    return *count;
}

template <typename Type>
Vector<Type> &Vector<Type>::clear()
{
    arr.reset();
    *count = 0;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::resize(size_t N)
{
    time_t t = time(NULL);
    size_t tmp_count = min(*count, N);
    if (!(*count = N))
        throw AllocationError("Resize: ", ctime(&t));

    shared_ptr<Type[]> tmp(arr);
    arr = shared_ptr<Type[]>(new Type[*count]);

    for (size_t i = 0; i < tmp_count; i++)
        arr[i] = tmp[i];

    tmp = nullptr;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::addLast(const Vector<Type> &vec)
{
    size_t tmp = length();
    resize(length() + vec.length());

    for (size_t i = tmp; i < length(); i++)
        arr[i] = vec[i - tmp];

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::addLast(const Type &element)
{
    resize(length() + 1);
    arr[length() - 1] = element;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::append(const Vector<Type> &vec)
{
    return addLast(vec);
}

template <typename Type>
Vector<Type> &Vector<Type>::append(const Type &element)
{
    return addLast(element);
}

template <typename Type>
Vector<Type> &Vector<Type>::set(const Type &element, size_t ind)
{
    arr[ind] = element;
    return *this;
}

template <typename Type>
Type &Vector<Type>::get(size_t ind)
{
    return arr[ind];
}

template <typename Type>
Vector<Type> &Vector<Type>::insert(const Vector<Type> &vec, size_t pos)
{
    time_t t = time(NULL);
    if (pos > length() || pos < 0)
        throw IndexError("Insert: ", ctime(&t), pos);

    resize(length() + vec.length());
    for (size_t i = length() - 1; i >= pos + vec.length(); i--)
        arr[i] = arr[i - vec.length()];
    for (size_t i = pos; i < pos + vec.length(); i++)
        arr[i] = vec[i - pos];
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::insert(const Type &element, size_t pos)
{
    time_t t = time(NULL);
    if (pos > length() || pos < 0)
        throw IndexError("Insert: ", ctime(&t), pos);

    resize(length() + 1);
    for (size_t i = length() - 1; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = element;
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::pushBack(const Vector<Type> &vec)
{
    return addLast(vec);
}

template <typename Type>
Vector<Type> &Vector<Type>::pushBack(const Type &element)
{
    return addLast(element);
}

template <typename Type>
Vector<Type> &Vector<Type>::pushFront(const Vector<Type> &vec)
{
    return insert(vec, 0);
}

template <typename Type>
Vector<Type> &Vector<Type>::pushFront(const Type &element)
{
    return insert(element, 0);
}

template <typename Type>
Type Vector<Type>::pop(size_t N)
{
    time_t t = time(NULL);
    if (isEmpty())
        throw EmptyVectorError("Pop: ", ctime(&t));
    if (N > *count)
        throw IndexError("Pop: ", ctime(&t), N);

    Type temp = arr[N];

    for (size_t i = N; i < *count - 1; i++)
        arr[i] = arr[i + 1];

    resize(*count - 1);
    return temp;
}

template <typename Type>
Type Vector<Type>::popBack()
{
    time_t t = time(NULL);
    if (isEmpty())
        throw EmptyVectorError("PopBack", ctime(&t));
    Type temp = arr[*count - 1];
    resize(*count - 1);
    return temp;
}

template <typename Type>
Type Vector<Type>::popFront()
{
    time_t t = time(NULL);
    if (isEmpty())
        throw EmptyVectorError("PopFront", ctime(&t));
    return pop(0);
}

template <typename Type>
ostream &operator<<(ostream &os, Vector<Type> vec)
{
    for (auto el : vec)
        os << el;
    return os;
}

#endif // !VECTOR_HPP