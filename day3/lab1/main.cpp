#include <iostream>
#define SIZE 7
using namespace std;

void Insert_sort(int* arr,int Size);
void print_array(int* arr, int Size);

int main()
{
    int arr[SIZE] = {1,4,5,8,7,4,5};
    print_array(arr,SIZE);
    Insert_sort(arr,SIZE);
    print_array(arr,SIZE);
    return 0;
}



void Insert_sort(int* arr,int Size)
{

    for(int i = 1; i < Size ; i++)
    {
        int val = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > val)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }

}



void print_array(int* arr, int Size)
{
    cout << "array values are : ";
    for(int i = 0 ; i < Size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
