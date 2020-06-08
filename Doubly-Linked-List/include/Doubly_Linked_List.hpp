
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP


#include "List_Node.hpp"
#include <cstddef>


template <typename T> class List_Iterator;


template <typename T>
class Doubly_Linked_List
{
private:

    List_Node<T>* head;
    List_Node<T>* tail;
    size_t length;

    
    void delete_list(List_Node<T>* head);


public:

    typedef List_Iterator<T> iterator;


    Doubly_Linked_List();

    ~Doubly_Linked_List();


    // Iterators

    iterator begin() const;

    iterator end() const;


    // Capacity

    bool empty() const;

    size_t size() const;


    // Element access

    T& front() const;

    T& back() const;


    // Modifiers

    void push_front(const T& elem);

    void pop_front();

    void push_back(const T& elem);

    void pop_back();

    iterator insert(const iterator& pos, const T& elem);

    iterator erase(const iterator& pos);

    void clear();

    
    // For debugging

    void print_forward() const;

    void print_backward() const;
};


#include "Doubly_Linked_List.cpp"


#endif