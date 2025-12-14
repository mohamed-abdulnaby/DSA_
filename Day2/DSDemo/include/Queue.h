#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
    Queue(int _size)
    {
        queueSize = _size;
        arr = new int[queueSize];
        frot = rear = -1;
    }

    bool Enqueue(int val)
    {
        if (IsFull())
            return false;

        if (IsEmpty())
            frot = 0;

        rear++;
        arr[rear] = val;
        return true;
    }

    bool Dequeue(int &val)
    {
        if (IsEmpty())
            return false;

        val = arr[frot];
        shift();
        rear--;

        if (IsEmptyAfterDequeue())
            frot = rear = -1;

        return true;
    }

    void Reverse()
    {
        if (IsEmpty())
            return;

        int start = frot;
        int end = rear;

        while (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    bool IsEmpty()
    {
        return (frot == -1 && rear == -1);
    }

    bool IsFull()
    {
        return (rear == queueSize - 1);
    }

protected:

private:
    int queueSize;
    int frot, rear;
    int *arr;

    void shift()
    {
        for (int i = frot; i < rear; ++i)
            arr[i] = arr[i + 1];
    }

    bool IsEmptyAfterDequeue()
    {
        return rear < frot;
    }
};

#endif // QUEUE_H
