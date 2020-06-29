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

    void _print(Nptr);
    void _makeNode(T);
    void _makeNode(T, int);
    void _append(Nptr&, Nptr);
    void _insert(Nptr&, Nptr, int);
    void _getPointers();
    void _reverse(Nptr&, Nptr, Nptr);
    void _clear(Nptr&, Nptr&);
public:
    List(): length(0), head(NULL) {}
    int length;
    void print();
    void append(T);
    void insert(T, int);
    void appendRange(T[]);
    void insertRange(T[], int);
    bool remove(T);
    bool remove(T, int);
    void clear();
    void reverse();
};