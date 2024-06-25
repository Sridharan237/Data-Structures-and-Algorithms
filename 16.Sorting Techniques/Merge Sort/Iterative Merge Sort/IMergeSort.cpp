// cpp program to implement Iterative Merge sort
#include<iostream>
#include<cmath>

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

// function to implement Iterative Merge sort
void IMergeSort(int A[], int n)
{
    int p, i, j;    // p - pass

    int l, mid, h;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l = i;
            h = i+p-1;
            mid = floor((l+h)/2);  // it will take the floor value

            Merge(A, l, mid, h);
        }
    }

    if(p/2 < n)     // if the size of the array is odd then we need to merge the last element also
        Merge(A, 0, p/2-1, n);
}

int main()
{
    int A[] = {10, 15, 3, 4, 8}, n = 5;  

    IMergeSort(A, n);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
}