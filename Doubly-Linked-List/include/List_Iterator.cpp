
#include "List_Iterator.hpp"

#include <cassert>



template <typename T>
T& List_Iterator<T>::operator*() const
{
    assert(node != NULL);

    return node->elem;
}


template <typename T>
const List_Iterator<T>& List_Iterator<T>::operator++()
{
    assert(node != NULL);

    node = node->next;
    return *this;
}


template <typename T>
const List_Iterator<T>& List_Iterator<T>::operator--()
{
    assert(node != NULL);

    node = node->prev;
    return *this;
}


template<typename T>
bool List_Iterator<T>::operator==(const List_Iterator<T>& rhs) const
{
    return node == rhs.node;
}


template<typename T>
bool List_Iterator<T>::operator!=(const List_Iterator<T>& rhs) const
{
    return node != rhs.node;
}


template <typename T>
List_Iterator<T> List_Iterator<T>::operator+(const size_t offset) const
{
    size_t off = offset;
    List_Node<T>* node(this->node);

    while(off > 0)
    {
        if(node == NULL)
            return List_Iterator<T>(NULL);

        node = node->next;
        off--;
    }

    return List_Iterator<T>(node);
}


template <typename T>
List_Iterator<T> List_Iterator<T>::operator-(const size_t offset) const
{
    size_t off = offset;
    List_Node<T>* node(this->node);

    while(off > 0)
    {
        if(node == NULL)
            return List_Iterator<T>(NULL);

        node = node->prev;
        off--;
    }

    return List_Iterator<T>(node);
}
