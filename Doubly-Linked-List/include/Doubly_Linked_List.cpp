
#include "Doubly_Linked_List.hpp"
#include "List_Iterator.hpp"

#include <cassert>
#include <iostream>


template <typename T>
Doubly_Linked_List<T>::Doubly_Linked_List():
    head(NULL), tail(NULL), length(0)
{}


template <typename T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{
    delete_list(head);
}


template <typename T>
void Doubly_Linked_List<T>::delete_list(List_Node<T>* head)
{
    if(head == NULL)
        return;

    delete_list(head->next);
    delete head;
}


template <typename T>
typename Doubly_Linked_List<T>::iterator Doubly_Linked_List<T>::begin() const
{
    return iterator(head);
}


template <typename T>
typename Doubly_Linked_List<T>::iterator Doubly_Linked_List<T>::end() const
{
    return iterator(NULL);
}

template <typename T>
bool Doubly_Linked_List<T>::empty() const
{
    return head == NULL;
}


template <typename T>
size_t Doubly_Linked_List<T>::size() const
{
    return length;
}


template <typename T>
T& Doubly_Linked_List<T>::front() const
{
    assert(head != NULL);

    return head->elem;
}


template <typename T>
T& Doubly_Linked_List<T>::back() const
{
    assert(tail != NULL);

    return tail->elem;
}


template <typename T>
void Doubly_Linked_List<T>::push_front(const T& elem)
{
    List_Node<T>* new_node = new List_Node<T>(elem, NULL, head);

    if(head == NULL)
        head = tail = new_node;
    else
    {
        head->prev = new_node;
        head = new_node;
    }

    length++;
}


template <typename T>
void Doubly_Linked_List<T>::pop_front()
{
    assert(head != NULL);


    List_Node<T>* deleted_node = head;

    if(head == tail)
        head = tail = NULL;
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete deleted_node;

    length--;
}


template <typename T>
void Doubly_Linked_List<T>::push_back(const T& elem)
{
    List_Node<T>* new_node = new List_Node<T>(elem, tail, NULL);

    if(tail == NULL)
        head = tail = new_node;
    else
    {
        tail->next = new_node;
        tail = new_node;
    }

    length++;
}


template <typename T>
void Doubly_Linked_List<T>::pop_back()
{
    assert(tail != NULL);


    List_Node<T>* deleted_node = tail;

    if(head == tail)
        head = tail = NULL;
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete deleted_node;

    length--;
}


template <typename T>
void Doubly_Linked_List<T>::clear()
{
    delete_list(head);

    length = 0;
}


template <typename T>
typename Doubly_Linked_List<T>::iterator Doubly_Linked_List<T>::insert(const iterator& pos, const T& elem)
{
    if(pos == begin())
    {
        push_front(elem);
        return iterator(head);
    }
    

    if(pos == end())
    {
        push_back(elem);
        return iterator(tail);
    }
    
    
    List_Node<T>* new_node = new List_Node<T>(elem, pos.node->prev, pos.node);
    pos.node->prev->next = new_node;
    pos.node->prev = new_node;

    length++;

    return iterator(new_node);
}


template <typename T>
typename Doubly_Linked_List<T>::iterator Doubly_Linked_List<T>::erase(const iterator& pos)
{
    if(pos == begin())
    {
        pop_front();
        return iterator(head);
    }


    if(pos.node == tail)
    {
        pop_back();
        return end();
    }


    List_Node<T>* next_node = pos.node->next;

    pos.node->prev->next = pos.node->next;
    pos.node->next->prev = pos.node->prev;
    delete pos.node;

    length--;

    return iterator(next_node);
}



template <typename T>
void Doubly_Linked_List<T>::print_forward() const
{
    std::cout << "List size: " << length << "\n";
    
    std::cout << "List (in forward): [ ";
    List_Iterator<T> it = begin();
    while(it != end())
    {
        std::cout << *it << " ";
        ++it;
    }


    std::cout << "]\n";
}


template <typename T>
void Doubly_Linked_List<T>::print_backward() const
{
    std::cout << "List size: " << length << "\n";
    
    std::cout << "List (in backward): [ ";
    List_Iterator<T> it = iterator(tail);
    while(it.node != NULL)
    {
        std::cout << *it << " ";
        --it;
    }


    std::cout << "]\n";
}
