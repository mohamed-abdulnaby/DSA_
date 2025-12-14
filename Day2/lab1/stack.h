
#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iostream>
using namespace std;
class Stack
{
    public:
        // array
        Node* top;
        int Count;

        Stack()
        {
            top = NULL;
            Count = 0;
        }


        void Push(int val)
        {

            Node *temp = new Node(val);

            temp-> next = top;
            top = temp;
            Count++;



        }

        bool Pop(int &val)
        {
            if(top == NULL)
            {
                cout << "Stack is Empty" << endl;
                return false;
            }
            Node* temp = top;
            top = top->next;
            Count--;
            val = temp->data;
            delete temp;
            return true;
        }

        bool Peek(int &val)
        {
            if(top == NULL)
            {
                cout << "Stack is empty" << endl;
                return false;
            }
            val = top->data;
            return true;

        }

    protected:

    private:

};

#endif // STACK_H
