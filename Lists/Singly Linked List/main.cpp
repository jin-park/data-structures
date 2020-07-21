#include <iostream>
#include "list.cpp"
using namespace std;

int main()
{
	List<int> list = List<int>();
    for (int i = 0;i < 15;i++)
    { 
        list.append(i);
    }
    int li[9] = {111, 112, 113, 114, 115, 116, 117, 118, 119};
    list.insertRange(li, 9, 3);
    list.print();
    //cout << list.length << endl;
    return 0;
}
