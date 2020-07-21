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
void List<T>::append(T data) { _makeNode(data); }

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
    if (!head) { Ptr = node; ++length; return; }
    else if (Ptr->next == NULL)
    {
        Ptr->next = node;
        ++length;
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
    _insert(head, node, index - 1);
}

template <class T>
void List<T>::_insert(Nptr& Ptr, Nptr node, int count) 
{
    if (count == -1 && Ptr == head) { node->next = Ptr; Ptr = node; ++length; return; }
    else if (count == 0) 
    {
        node->next = Ptr->next;
        Ptr->next = node;
        ++length;
        return;
    }
    _insert(Ptr->next, node, count - 1);
}

template <class T>
void List<T>::clear() { _clear(head); }

template <class T>
void List<T>::_clear(Nptr& Ptr)
{
    while (Ptr)
    {
        Nptr temp = Ptr;
        Ptr = Ptr->next;
        delete temp;
    }
}

template <class T>
bool List<T>::remove(T data) { return _remove(data, head); };

template <class T>
bool List<T>::_remove(T data, Nptr& Ptr)
{
    if (Ptr)
    {
        if (Ptr->data == data && Ptr == head) 
        { 
            Nptr temp = Ptr; 
            Ptr = Ptr->next;
            delete temp; 
            --length; 
            return true;
        }
        else if (Ptr->next->data == data)
        {
            _delNode(Ptr);
            --length;
            return true;
        }
        return _remove(data, Ptr->next);
    }
    return false;
}

template <class T>
void List<T>::_delNode(Nptr& Ptr)
{
    Nptr temp = Ptr->next;
    Ptr->next = Ptr->next->next;
    delete temp;
}

template <class T>
bool List<T>::del(int index) { return _del(index, head); }

template <class T>
bool List<T>::_del(int index, Nptr& Ptr)
{
    if (index == 0 && Ptr == head)
    {
        Nptr temp = Ptr;
        Ptr = Ptr->next;
        delete temp;
        --length;
        return true;
    }
    else if (Ptr->next)
    {
        if (index == 1)
        {
            _delNode(Ptr);
            --length;
            return true;
        }
        return _del(index - 1, Ptr->next);
    }
    return false;
}

template <class T>
void List<T>::appendRange(T list[], int len) { _appendRange(list, len); }

template <class T>
void List<T>::_appendRange(T list[], int len)
{
    Nptr Ptr = head;
    while (Ptr->next) { Ptr = Ptr->next; }
    if (Ptr == head)
    {
        Nptr node = new Node();
        node->next = NULL;
        node->data = *(list);
        Ptr = node;
        ++length;
        for (int i = 1; i < len; i++)
        {
            _appendNode(Ptr, *(list + i));  
        }
        return;
    }
    for (int i = 0; i < len; i++)
    {
        _appendNode(Ptr, *(list + i));   
    }
}

template <class T>
void List<T>::insertRange(T list[], int len, int index) { _insertRange(list, len, index, head); }

template <class T>
void List<T>::_insertRange(T list[], int len, int index, Nptr& Ptr)
{
    if (index == 0)
    {
        _insertHead(head, *list);
        Nptr tail = head;
        for (int i = 1;i < len;i++)
        {
			_insertNode(tail, *(list + i));  
        }
        return;
    }
	else if (index == 1)
	{
		Nptr node = new Node();
		node->next = Ptr->next;
		node->data = *list;
		Ptr->next = node;
		Nptr tail = Ptr->next;
		for (int i = 1;i < len;i++)
		{
			_insertNode(tail, *(list + i));
		}
		return;
	}
	Nptr tail = Ptr->next;
    for (int i = 2;i < index;i++)
    {
    	tail = tail->next;  
    }
    for (int i = 0;i < len;i++)
    {
        _insertNode(tail, *(list+i));
    }
}

template <class T>
void List<T>::_insertNode(Nptr& Ptr, T data)
{
    Nptr node = new Node();
    node->data = data;
    node->next = Ptr->next;
    Ptr->next = node;
    Ptr = Ptr->next;
    ++length;
}

template <class T>
void List<T>::_insertHead(Nptr& Ptr, T data)
{
	
    Nptr node = new Node();
    node->data = data;
    node->next = head;
    Ptr = node;
    ++length;
}

template <class T>
void List<T>::_appendNode(Nptr& Ptr, T data)
{
    Nptr node = new Node();
    node->next = NULL;
    node->data = data;
    Ptr->next = node;
    Ptr = Ptr->next;
    ++length;
}

template <class T>
void List<T>::reverse() { _reverse(head); }

template <class T>
void List<T>::_reverse(Nptr& Ptr) 
{
    Nptr previous = NULL;
    Nptr current = head;
    Nptr next = head;

    while (current)
    {
        next = next->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}
