#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList L;

    L.sorted_add(10);

    L.sorted_add(5);

    L.sorted_add(20);

    L.sorted_add(15);

    L.sorted_add(10);
    L.sorted_add(5);

    cout << "Sorted list:\t";
    L.Display();
    cout << endl;

    return 0;
}
