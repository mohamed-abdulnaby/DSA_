#include <iostream>
#define SIZE 7

void bubble_sort(int arr[], int Size);
void print_array(int* arr, int Size);


using namespace std;

int main()
{
    int arr[SIZE] = {1,4,5,8,7,4,5};
    print_array(arr,SIZE);
    bubble_sort(arr,SIZE);
    print_array(arr,SIZE);
    return 0;
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


void bubble_sort(int arr[], int Size)
{
    bool swapped = false;
    for(int i = 0 ; i < Size-1; i++)
    {
        for(int j = i  ; j < Size-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!swapped) break;
    }
}
