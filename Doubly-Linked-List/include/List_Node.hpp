
#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP


template <typename T> class Doubly_Linked_List;
template <typename T> class List_Iterator;


template <typename T>
class List_Node
{
    friend class Doubly_Linked_List<T>;
    friend class List_Iterator<T>;

private:

    T elem;
    List_Node<T>* prev;
    List_Node<T>* next;


    List_Node<T>(const T& elem, List_Node<T>* prev, List_Node<T>* next):
        elem(elem), prev(prev), next(next)
    {}
};


#endif
