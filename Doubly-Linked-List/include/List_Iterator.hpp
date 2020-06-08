
#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP


#include "List_Node.hpp"



template <typename T> class Doubly_Linked_List;


template <typename T>
class List_Iterator
{
    friend class Doubly_Linked_List<T>;

private:
    
    List_Node<T>* node;


    List_Iterator<T>(List_Node<T>* node): node(node)
    {}


public:

    T& operator*() const;

    const List_Iterator<T>& operator++();

    const List_Iterator<T>& operator--();

    bool operator==(const List_Iterator<T>& rhs) const;

    bool operator!=(const List_Iterator<T>& rhs) const;

    List_Iterator<T> operator+(const size_t offset) const;

    List_Iterator<T> operator-(const size_t offset) const;
};


#include "List_Iterator.cpp"


#endif