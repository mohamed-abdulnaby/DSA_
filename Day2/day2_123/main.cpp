#include <iostream>
#include "Queue.h"       // your Queue class (linked-list queue)
#include "circ_queue.h" // circular queue header (rename your file accordingly)
#include "Stack.h"       // stack header
using namespace std;

int main()
{

    cout << "=== Testing Circular Queue ===" << endl;
    Queue_circ cq(5);

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);

    int x;
    cq.Dequeue(x);
    cout << "Dequeued from circular queue: " << x << endl;

    cq.Enqueue(40);
    cq.Enqueue(50);
    cq.Enqueue(60);
    cq.Enqueue(70);


    cout << "Dequeued from circular queue: " << x << endl;


    cout << "Circular queue size: " << cq.Size() << endl << endl;



    cout << "=== Testing Linked-List Queue ===" << endl;
    Queue q;

    q.Enqueue(100);
    q.Enqueue(200);
    q.Enqueue(300);

    q.Dequeue(x);
    cout << "Dequeued from linked-list queue: " << x << endl;

    q.Enqueue(400);

    cout << "Linked-list queue size: " << q.Size() << endl << endl;



    cout << "=== Testing Stack ===" << endl;
    Stack st;

    st.Push(5);
    st.Push(15);
    st.Push(25);

    st.Pop(x);
    cout << "Popped from stack: " << x << endl;

    st.Peek(x);
    cout << "Top of stack: " << x << endl;

    cout << "Stack size: " << st.Size() << endl;

    return 0;
}
