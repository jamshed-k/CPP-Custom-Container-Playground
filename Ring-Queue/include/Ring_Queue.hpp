
#ifndef RING_QUEUE_HPP
#define RING_QUEUE_HPP


#include <cstddef>
// #include <iterator>


template <typename T, size_t N> class RQ_Iterator;


template <typename T, size_t N>
class Ring_Queue
{
    friend class RQ_Iterator<T, N>;

    // typedef T* iterator;
    typedef RQ_Iterator<T, N> iterator;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;


private:

    T buffer[N];
    size_t begin_idx;
    size_t length;



    // Private accessor.

    T& operator[](const size_t idx);


public:

    // Constructors

    Ring_Queue(): begin_idx(0), length(0)
    {}


    // Accessors

    T& front() const;

    T& back() const;


    // Modifiers

    void pop_front();

    void push_back(const T& elem);


    // Iterators

    iterator begin();

    iterator end();


    // Capacity

    bool empty() const;

    size_t size() const;
};



#include "Ring_Queue.cpp"


#endif
