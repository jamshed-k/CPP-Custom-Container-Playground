
#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP


#include "List_Node.hpp"

#include <cstddef>
#include <iostream>


template <typename T> class List_Iterator;


template <typename T>
class Singly_Linked_List
{
private:

    List_Node<T>* head;
    List_Node<T>* tail;
    size_t length;


    static void delete_list(List_Node<T>* head);


public:
    
    typedef List_Iterator<T> iterator;

    Singly_Linked_List<T>():
        head(NULL), tail(NULL), length(0)
    {}

    ~Singly_Linked_List<T>();

    const T& front() const;

    const T& back() const;

    bool empty() const;

    size_t size() const;

    void clear();

    void push_back(const T& elem);

    void push_front(const T& elem);

    void pop_front();

    iterator begin() const;
    
    iterator end() const;
};



#include "Singly_Linked_List.cpp"


#endif
