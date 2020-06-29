#include "list.cpp"

int main()
{
    List<int> list = List<int> ();
    for (int i = 0;i < 5;i++)
    {
        list.append(i);
    }
    list.print();
    return 0;
}