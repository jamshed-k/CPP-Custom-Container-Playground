
#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP


#include "List_Node.hpp"


template <typename T> class Singly_Linked_List;


template <typename T>
class List_Iterator
{
    friend class Singly_Linked_List<T>;

private:
 
    List_Node<T>* pointee;

    List_Iterator<T>(List_Node<T>* pointee): pointee(pointee)
    {}



public:
    
    T& operator*() const;

    const List_Iterator<T>& operator++();

    bool operator==(const List_Iterator<T>& rhs) const;

    bool operator!=(const List_Iterator<T>& rhs) const;
};



#include "List_Iterator.cpp"


#endif
