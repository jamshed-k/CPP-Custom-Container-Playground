
#include "Ring_Queue.hpp"

#include <cassert>


template <typename T, size_t N>
T& Ring_Queue<T, N>::front() const
{
    assert(length > 0);

    return buffer[begin_idx];
}


template <typename T, size_t N>
T& Ring_Queue<T, N>::back() const
{
    assert(length > 0);

    return buffer[(begin_idx + length) % N];
}


template <typename T, size_t N>
T& Ring_Queue<T, N>::operator[](const size_t idx)
{
    assert(idx < length);

    return buffer[(begin_idx + idx) % N];
}


template <typename T, size_t N>
void Ring_Queue<T, N>::pop_front()
{
    assert(length > 0);

    begin_idx = (begin_idx + 1) % N;
    length--;
}


template <typename T, size_t N>
void Ring_Queue<T, N>::push_back(const T& elem)
{
    size_t end_idx = (begin_idx + length) % N;

    buffer[end_idx] = elem;
    
    if(length < N)
        length++;
    else
        begin_idx = (begin_idx + 1) % N;
}


template <typename T, size_t N>
typename Ring_Queue<T, N>::iterator Ring_Queue<T, N>::begin()
{
    // return &buffer[begin_idx];
    return iterator(*this, 0);
}


template <typename T, size_t N>
typename Ring_Queue<T, N>::iterator Ring_Queue<T, N>::end()
{
    // return &buffer[(begin_idx + length) % N];
    return iterator(*this, length);
}


template <typename T, size_t N>
bool Ring_Queue<T, N>::empty() const
{
    return length == 0;
}


template <typename T, size_t N>
size_t Ring_Queue<T, N>::size() const
{
    return length;
}
