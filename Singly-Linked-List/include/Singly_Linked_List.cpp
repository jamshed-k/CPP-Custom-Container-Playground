
#include "Singly_Linked_List.hpp"

#include <cassert>
#include <iostream>


template <typename T>
void Singly_Linked_List<T>::delete_list(List_Node<T>* head)
{
    if(head == NULL)
        return;
    
    delete_list(head->next_node);
    delete head;
}


template <typename T>
Singly_Linked_List<T>::~Singly_Linked_List<T>()
{
    delete_list(head);
}


template <typename T>
const T& Singly_Linked_List<T>::front() const
{
    assert(head != NULL);

    return head->elem;
}


template <typename T>
const T& Singly_Linked_List<T>::back() const
{
    assert(tail != NULL);

    return tail->elem;
}


template <typename T>
bool Singly_Linked_List<T>::empty() const
{
    return head == NULL;
}


template <typename T>
size_t Singly_Linked_List<T>::size() const
{
    return length;
}


template <typename T>
void Singly_Linked_List<T>::clear()
{
    delete_list(head);

    head = NULL;
    length = 0;
}


template <typename T>
void Singly_Linked_List<T>::push_back(const T& elem)
{
    List_Node<T>* new_node = new List_Node<T>(elem, NULL);

    if(head == NULL)
        head = tail = new_node;
    else
    {
        tail->next_node = new_node;
        tail = new_node;
    }


    length++;
}


template <typename T>
void Singly_Linked_List<T>::push_front(const T& elem)
{
    List_Node<T>* new_node = new List_Node<T>(elem, head);

    head = new_node;

    length++;
}


template <typename T>
void Singly_Linked_List<T>::pop_front()
{
    assert(head != NULL);

    List_Node<T>* next_node = head->next_node;

    delete head;
    head = next_node;

    length--;
}


template <typename T>
typename Singly_Linked_List<T>::iterator Singly_Linked_List<T>::begin() const
{
    return iterator(head);
}


template <typename T>
typename Singly_Linked_List<T>::iterator Singly_Linked_List<T>::end() const
{
    return iterator(NULL);
}
