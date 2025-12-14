#ifndef QUEUE_CIRC_H
#define QUEUE_CIRC_H


class Queue_circ
{
    public:
        Queue_circ(int _size)
        {
            queueSize = _size;
            arr = new int[queueSize];
            frot = rear = Count = 0;
        }

        bool Enqueue(int val)
        {
            //O(1)
            if(IsFull())
                return false;
            arr[rear] = val;
            rear = (rear+1) % queueSize;
            Count++;
            return true;

        }

        bool Dequeue(int &val)
        {
            //O(1)
            if(IsEmpty())
                return false;
            val = arr[frot];
            frot = (frot+1) % queueSize;
            Count--;
            return true;

        }

        bool IsEmpty()
        {
            return (Count == 0);
        }
        bool IsFull()
        {
            return (Count == queueSize);
        }
        int Size()
        {
            return Count;
        }

    protected:

    private:
        int queueSize;
        int frot, rear,Count;
        int *arr;




};

#endif //  QUEUE_CIRC_H
