#include <iostream>
#define SIZE 20

int Binary_search(int arr[], int low, int high, int target);
void print_array(int* arr, int Size);


using namespace std;

int main()
{
    int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    print_array(arr,SIZE);
    int x  = Binary_search(arr, 0, SIZE-1 , 8);
    cout << "\nthe index at which the target '" << 8 << "' is at index: "
        << x << endl;
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


int Binary_search(int arr[], int low, int high, int target)
{
    int mid = high + (low - high) / 2;

    if(target == arr[mid])
    {
        return mid;
    }else if(target < arr[mid])
    {
        high = mid - 1;
    }else if(target > arr[mid])
    {
        low = mid + 1;
    }

    return Binary_search(arr, low, high, target);

}
