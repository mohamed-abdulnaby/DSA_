#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include <Queue.h>
using namespace std;

int main()
{
//    Stack * stc = new Stack(5);
//
//    // 10    5    -20
//    stc->Push(10);
//    stc->Push(5);
//    stc->Push(-20);
//
//    int popvalue;
//    if(stc->Pop(popvalue))
//        cout<<popvalue;    // -20
//
//    if(stc->Pop(popvalue))
//        cout<<popvalue;    // 5
//
//    if(stc->Peek(popvalue))
//        cout<<popvalue;    // 10
//
//    if(!stc->Pop(popvalue))
//        cout<<"stack is empty";
//
//    else cout<<popvalue;


Stack s(10);

    // Fill the stack
    int values[] = {4, 5, 2, 10, 8};
    for(int i = 0; i < 5; i++)
        s.Push(values[i]);

    // Compute next greater elements
    int* res = s.next_greater(values);

    cout << "Next greater elements:\n";
    for(int i = 0; i <= s.top; i++)
    {
        cout << values[i] << " -> " << res[i] << endl;
    }

    delete[] res; // clean up

    // Test edge case: decreasing array
    int values2[] = {10, 8, 6, 4, 2};
    Stack s2(5);
    for(int i = 0; i < 5; i++)
        s2.Push(values2[i]);

    res = s2.next_greater(values2);
    cout << "\nDecreasing array:\n";
    for(int i = 0; i <= s2.top; i++)
        cout << values2[i] << " -> " << res[i] << endl;

    delete[] res;

    // Test edge case: all same elements
    int values3[] = {7, 7, 7, 7};
    Stack s3(4);
    for(int i = 0; i < 4; i++)
        s3.Push(values3[i]);

    res = s3.next_greater(values3);
    cout << "\nAll same elements:\n";
    for(int i = 0; i <= s3.top; i++)
        cout << values3[i] << " -> " << res[i] << endl;

    delete[] res;

 Queue q(5);

    cout << "Enqueue elements: 10, 20, 30, 40, 50\n";
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    // Dequeue and print queue elements
    cout << "Queue elements before reverse: ";
    int val;
    int count = 0;
    while(!q.IsEmpty() && count < 5) // limit to size
    {
        q.Dequeue(val);
        cout << val << " ";
        count++;
    }
    cout << endl;

    // Enqueue again to test Reverse
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    // Reverse the queue
    q.Reverse();

    // Dequeue and print reversed queue
    cout << "Queue elements after reverse: ";
    count = 0;
    while(!q.IsEmpty() && count < 5)
    {
        q.Dequeue(val);
        cout << val << " ";
        count++;
    }
    cout << endl;
    return 0;

}
