#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

void sort_by_freq(int* arr, int n);

int main()
{
    int arr1[] = {5, 5, 4, 6, 4};
    int n1 = 5;

    sort_by_freq(arr1, n1);

    for(int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int arr2[] = {9, 9, 9, 2, 5};
    int n2 = 5;

    sort_by_freq(arr2, n2);

    for(int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;


    return 0;
}



void sort_by_freq(int* arr, int n)
{
    map<int, int> freqmap;

    for (int i = 0 ; i < n; i++)
    {
        freqmap[arr[i]]++;
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(freqmap[arr[i]] < freqmap[arr[j]])
            {
                swap(arr[i], arr[j]);
            }else if (freqmap[arr[i]] == freqmap[arr[j]] && arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
