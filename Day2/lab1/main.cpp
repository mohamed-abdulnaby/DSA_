#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s;

    cout << "Pushing values...\n";
    s.Push(10);
    s.Push(20);
    s.Push(30);

    int x;

    cout << "Peeking...\n";
    if (s.Peek(x)) {
        cout << "Top = " << x << endl;
    }

    cout << "Popping...\n";
    while (s.Pop(x)) {
        cout << "Popped: " << x << endl;
    }

    cout << "Trying to pop from empty stack...\n";
    s.Pop(x);  // should print empty message

    return 0;
}
