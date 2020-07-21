#include <iostream>
using namespace std;

template <class T>
class List 
{
    typedef struct Node 
    { 
        Node *next;
        T data;
    } *Nptr;

    Nptr head;

    void _print(Nptr); // done
    void _makeNode(T); // done
    void _makeNode(T, int); // done
    void _append(Nptr&, Nptr); // done
    void _insert(Nptr&, Nptr, int); // done
    void _clear(Nptr&); // done
    bool _remove(T, Nptr&); // done
    bool _del(int, Nptr&); // done
    void _delNode(Nptr&); // done
    void _insertRange(T[], int, int, Nptr&); // done
    void _appendRange(T[], int); // done
    void _appendNode(Nptr&, T); // done
    void _insertNode(Nptr&, T);
	void _insertHead(Nptr&, T);
    void _reverse(Nptr&); // done
public:
    List(): length(0), head(NULL) {}
    uint length; // done
    void print(); // done
    void append(T); // done
    void insert(T, int); // done
    void appendRange(T[], int); // done
    void insertRange(T[], int, int); // done
    bool remove(T); // done
    bool del(int); // done
    void clear(); // done
    void reverse(); // done
};
