#ifndef QUEUE_H
#define QUEUE_H
#include <Node.h>

class Queue
{
    public:
        Queue()
        {
            frot = rear = NULL;
            Count = 0;
        }

        void Enqueue(int val)
        {
            Node* temp = new Node(val);

            if(IsEmpty())
            {
                frot = rear = temp;
            }else
            {
                temp->next = rear;
                rear->prev = temp;
                rear = temp;
            }
            Count++;
            return;

        }

        void Dequeue(int &val)
        {
            //O(n)
            if(IsEmpty())
                return;
            val = frot->data;
            Node* temp = frot;
            frot = frot->next;
            delete temp;
            Count--;

        }

        bool IsEmpty()
        {
            return (frot == rear);
        }

        int Size()
        {
            return Count;
        }


    protected:

    private:

        Node* frot;
        Node* rear;
        int Count;



};

#endif // QUEUE_H
