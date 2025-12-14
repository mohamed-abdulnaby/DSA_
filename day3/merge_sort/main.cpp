#include <iostream>
#define SIZE 7


void print_array(int* arr, int Size);
void Merge_sort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);

using namespace std;

int main()
{
    int arr[SIZE] = {1,4,5,8,7,4,5};
    print_array(arr,SIZE);
    Merge_sort(arr, 0, SIZE-1);
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


void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left +1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];


    for (int i = 0; i < n1; i++)
        L[i] = arr[left+i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid+1+j];

    int i = 0, j = 0;
    int k = left;


    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];

        }else
        {
            arr[k] = R[j++];

        }
        k++;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];

    }
    while(j < n2)
    {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}



void Merge_sort(int arr[], int left, int right)
{
    if(left >= right) return;

    int mid = (left)+(right - left) / 2;
    Merge_sort(arr,left,mid);
    Merge_sort(arr,mid + 1,right);
    Merge(arr, left, mid, right);
}
