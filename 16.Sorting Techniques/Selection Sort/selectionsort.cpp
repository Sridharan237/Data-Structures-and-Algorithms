// cpp program to implement selection sort
#include<iostream>

using namespace std;

// function to implement selection Sort
void selectionSort(int A[], int n)
{
    int i, j, k;

    for(i=0;i<n-1;i++)  // for passes
    {
        for(j=k=i;j<n;j++)  // for finding sorted element for position 'i'
        {
            if(A[j] < A[k])
                k = j;
        }

        swap(A[i], A[k]);   // built-in function for swapping in cpp
    }
}

int main()
{
    int A[] = {10, 15, 3, 4, 8}, n = 5;

    selectionSort(A, n);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
}