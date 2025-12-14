#include <iostream>
#include <algorithm>

using namespace std;

void sort_matrix(int mat[][3], int n, int m);
void printMatrix(int mat[][3], int m, int n);

int main()
{

    int mat1[3][3] = {
        {5, 4, 7},
        {1, 3, 8},
        {2, 9, 6}
    };

    sort_matrix(mat1, 3, 3);
    printMatrix(mat1, 3, 3);

    cout << "----" << endl;

    int mat2[2][3] = {
        {5, 4, 7},
        {1, 3, 8}
    };

    sort_matrix(mat2, 2, 3);
    printMatrix(mat2, 2, 3);


    return 0;
}


void sort_matrix(int mat[][3], int n, int m)
{
    int Size = n * m;
    int* arr = new int[Size];
    int idx = 0;


    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[idx++] = mat[i][j];
        }
    }
    sort(arr, arr + Size);


    idx = 0;

        for(int i = 0; i < m; i++)
        {
          for(int j = 0; j < n; j++)
          {
              mat[i][j] = arr[idx++];
          }

        }



}


void printMatrix(int mat[][3], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}


