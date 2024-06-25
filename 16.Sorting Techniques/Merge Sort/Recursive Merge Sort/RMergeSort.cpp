// cpp program to implement Recursive Merge sort
#include<iostream>

using namespace std;

// function to perform merging
void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;

    i = l, j = mid + 1, k = l;

    int B[50];

    while(i <= mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(;i<=mid;i++)
        B[k++] = A[i];

    for(;j<=h;j++)
        B[k++] = A[j];


    // recopying the elements from Array B to Array A
    for(i=l;i<=h;i++)
        A[i] = B[i];
}

// function to implement Recursive Merge sort
void RMergeSort(int A[], int l, int h)
{
    int mid;

    if(l < h)
    {
        mid = (l+h)/2;

        RMergeSort(A, l, mid);
        RMergeSort(A, mid+1, h);

        Merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {10, 15, 3, 4, 8}, n = 5;  

    RMergeSort(A, 0, n-1);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
}