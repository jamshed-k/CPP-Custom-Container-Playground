
#ifndef RQ_ITERATOR_HPP
#define RQ_ITERATOR_HPP


#include "Ring_Queue.hpp"

#include <cstddef>
#include <iterator>


template <typename T, size_t N>
class RQ_Iterator: public std::iterator<std::forward_iterator_tag, T>
{
    typedef RQ_Iterator<T, N> iterator;

private:

    Ring_Queue<T, N>& rq;
    size_t offset;


public:

    RQ_Iterator(Ring_Queue<T, N>& rq, const size_t offset):
        rq(rq), offset(offset)
    {}

    
    bool operator==(const RQ_Iterator& rhs) const;

    bool operator!=(const RQ_Iterator& rhs) const;

    T& operator*();

    iterator& operator++();

    RQ_Iterator& operator++(int);
};


#include "RQ_Iterator.cpp"


#endif
