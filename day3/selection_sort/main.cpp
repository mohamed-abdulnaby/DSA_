#include <iostream>
#define SIZE 7

void selection_sort(int arr[], int Size);
void print_array(int* arr, int Size);


using namespace std;

int main()
{
    int arr[SIZE] = {1,4,5,8,7,4,5};
    print_array(arr,SIZE);
    selection_sort(arr,SIZE);
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


void selection_sort(int arr[], int Size)
{

    int Max = 0;
    for(int i = 0 ; i < Size; i++)
    {
        Max = i;
        for(int j = i+1  ; j < Size ; j++)
        {
            if(arr[Max] < arr[j])
            {
                Max = j;
            }else continue;
        }
        int temp = arr[i];
        arr[i] = arr[Max];
        arr[Max] = temp;
    }
    return;
}
