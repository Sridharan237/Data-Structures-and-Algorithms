// cpp program to implement insertion sort
#include<iostream>

using namespace std;

// function to implement Insertion Sort
void insertionSort(int A[], int n)
{
    int i, j, x;

    for(i=1;i<n;i++)    // for passes
    {
        j = i-1;
        x = A[i];

        while(j > -1 && A[j] > x)     // for swapping
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = x;
    }
}

int main()
{
    int A[] = {10, 15, 3, 4, 8}, n = 5;

    insertionSort(A, n);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
}