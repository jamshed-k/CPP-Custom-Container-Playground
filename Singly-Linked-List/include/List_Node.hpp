
#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP


template <typename T> class Singly_Linked_List;
template <typename T> class List_Iterator;


template <typename T>
class List_Node
{
    friend class Singly_Linked_List<T>;
    friend class List_Iterator<T>;

private:
    T elem;
    List_Node<T>* next_node;

    List_Node<T>()
    {}

    List_Node<T> (const T& elem, List_Node<T>* next_node):
        elem(elem), next_node(next_node)
    {}
};


#endif
