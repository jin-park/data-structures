#include "list.h"

template <class T>
void List<T>::print() { _print(head); }

template <class T>
void List<T>::_print(Nptr Ptr) 
{
    // Recursive
    // if (Ptr)
    // {
    //     cout << Ptr->data << endl;
    //     _print(Ptr->next);
    // }
    // Iterative
    if (Ptr) { cout << Ptr->data << endl; }
    while (Ptr->next)
    {
        Ptr = Ptr->next;
        cout << Ptr->data << endl;
    }
}

template <class T>
void List<T>::append(T data) { _makeNode(data); length++; }

template <class T>
void List<T>::_makeNode(T data)
{
    Nptr node = new Node();
    node->next = NULL;
    node->data = data;
    _append(head, node);
}

template <class T>
void List<T>::_append(Nptr& Ptr, Nptr node)
{
    if (!head)
    {
        Ptr = node;
        return;
    }
    else if (Ptr->next == NULL)
    {
        Ptr->next = node;
        return;
    }
    _append(Ptr->next, node);
}

template <class T>
void List<T>::insert(T data, int index) { _makeNode(data, index); }

template <class T>
void List<T>::_makeNode(T data, int index)
{
    Nptr node = new Node();
    node->next = NULL;
    node->data = data;
    _insert(head, node, index);
}

template <class T>
void List<T>::_insert(Nptr& Ptr, Nptr node, int count) 
{
    if (count == 0 && Ptr == head) { node->next = Ptr; Ptr = node; return; }
    else if (count == 0) 
    {
        node->next = Ptr->next;
        Ptr->next = node;
        return;
    }
    else { 
        _insert(Ptr->next, node, count - 1);
    }
}