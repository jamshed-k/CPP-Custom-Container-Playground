
#include "RQ_Iterator.hpp"


template <typename T, size_t N>
bool RQ_Iterator<T, N>::operator==(const RQ_Iterator& rhs) const
{
    return (&rq == &rhs.rq) && (offset == rhs.offset);
}


template <typename T, size_t N>
bool RQ_Iterator<T, N>::operator!=(const RQ_Iterator& rhs) const
{
    return !(*this == rhs);
}


template <typename T, size_t N>
T& RQ_Iterator<T, N>::operator*()
{
    return rq[offset];
}


template <typename T, size_t N>
RQ_Iterator<T, N>& RQ_Iterator<T, N>::operator++()
{
    offset++;
    return *this;
}


template <typename T, size_t N>
RQ_Iterator<T, N>& RQ_Iterator<T, N>::operator++(int)
{
    RQ_Iterator<T, N> clone(*this);
    offset++;

    return clone;
}
