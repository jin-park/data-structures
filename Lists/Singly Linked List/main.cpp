#include <iostream>
#include "list.cpp"
using namespace std;

int main()
{
    List<int> list = List<int>();
    for (int i = 0;i < 6;i++)
    {
        list.append(i);
    }
    list.insert(34,2);
    list.insert(23,0);
    list.print();
    return 0;
}
