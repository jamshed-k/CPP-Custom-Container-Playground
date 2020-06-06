
#include "List_Iterator.hpp"

#include <cassert>
#include <cstddef>


template <typename T>
T& List_Iterator<T>::operator*() const
{
    return pointee->elem;
}


template <typename T>
const List_Iterator<T>& List_Iterator<T>::operator++()
{
    assert(pointee != NULL);

    pointee = pointee->next_node;
    return *this;
}


template <typename T>
bool List_Iterator<T>::operator==(const List_Iterator<T>& rhs) const
{
    return pointee == rhs.pointee;
}


template <typename T>
bool List_Iterator<T>::operator!=(const List_Iterator<T>& rhs) const
{
    return pointee != rhs.pointee;
}
