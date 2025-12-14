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
                rear->next = temp;
                temp->prev = rear;
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

            if(frot != NULL)
                frot->prev = NULL;
            else
                rear = NULL;
            delete temp;
            Count--;

        }

        bool IsEmpty()
        {
            return (frot == NULL);
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
