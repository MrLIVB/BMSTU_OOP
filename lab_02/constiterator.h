#ifndef CONSTITERATOR
#define CONSTITERATOR

#include <memory>
#include <iterator>

using namespace std;

template <typename Type>
class Vector;

template <typename Type>
class ConstIterator : public iterator<output_iterator_tag, Type>
{
    friend class Vector<Type>;

private:
    ConstIterator(const shared_ptr<Type[]> &a, const shared_ptr<size_t> &c, size_t ind = 0) : arr(a), count(c), index(ind){};

public:
    ConstIterator(const Vector<Type> &v);
    ConstIterator(const ConstIterator<Type> &it) = default;
    ~ConstIterator();

    bool operator!=(ConstIterator const &other) const;
    bool operator==(ConstIterator const &other) const;
    operator bool() const;

    const Type *operator->() const;
    const Type &operator*() const;

    ConstIterator<Type> &operator++() noexcept;
    ConstIterator<Type> operator++(int) noexcept;

private:
    weak_ptr<Type[]> arr;
    shared_ptr<size_t> count; // заменить на просто size_t
    size_t index = 0;
};

#endif // !CONSTITERATOR