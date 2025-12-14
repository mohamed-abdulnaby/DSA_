#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        // array
        int stackSize;
        int top;
        int *arr;

        Stack(int _stackSize)
        {
            this->stackSize = _stackSize;

            arr = new int[stackSize];
            // last filled cell
            top = -1;

        }


        bool Push(int val)
        {
            // O(1)
            // if stack full
            if(ISFull())
                return false;

            else
            {
                top++;
                arr[top] = val;
                return true;
            }

        }

        bool Pop(int &val)
        {
            //o(1)
            if(IsEmpty())
                return false;

            val = arr[top];
            --top;
            return true;
        }

        bool Peek(int &val)
        {
            //o(1)
            if(IsEmpty())
                return false;
            val = arr[top];
            return true;

        }

        int* next_greater(int nums[])
        {
            bool flag;
            int* res = new int[stackSize];
            for(int i = 0; i <= top;i++)
            {
                flag = false;
                for(int j = i+1; j <= top ; j++)
                {
                    if(nums[i] < nums[j])
                    {
                        flag = true;
                        res[i] = nums[j];
                        break;
                    }

                }
                if(!flag)
                {
                res[i] = -1;

                }
            }


            return res;
        }

    protected:

    private:
        bool ISFull()
        {
            return top == stackSize - 1;
        }


        bool IsEmpty()
        {
            return top == -1;
        }
};

#endif // STACK_H
