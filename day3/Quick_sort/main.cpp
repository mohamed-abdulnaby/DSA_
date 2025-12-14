#include <iostream>
#define SIZE 7

void quick_sort(int arr[], int left, int right);
void print_array(int* arr, int Size);
void Swap(int& num1, int& num2);

using namespace std;

int main()
{
    int arr[SIZE] = {1,4,5,8,7,4,5};
    print_array(arr,SIZE);
    quick_sort(arr, 0, SIZE - 1);
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

void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

void quick_sort(int arr[], int left, int right)
{
    if (left >= right) return;

    int i = left - 1;

    for (int j = left; j < right ; j++)
    {

        if(arr[j] < arr[right])
            Swap(arr[j], arr[++i]);
    }

    Swap(arr[i+1], arr[right]);
    int pivot = i+1;

    quick_sort(arr, left, pivot -1);
    quick_sort(arr, pivot + 1, right);

    return;
}


