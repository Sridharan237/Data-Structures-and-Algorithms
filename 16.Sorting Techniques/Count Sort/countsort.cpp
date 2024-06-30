// cpp program to implement count sort
#include<iostream>

using namespace std;

// function to find the maximum element in an array
int findMax(int A[], int n)
{
    int max = A[0];

    for(int i=1;i<n;i++)
    {
        if(A[i] > max)
            max = A[i];
    }

    return max;
}

// function to perform count sort
void countSort(int A[], int n)
{
    int i, j, max;

    max = findMax(A, n);

    int *count = new int[max+1];

    for(i=0;i<max+1;i++)    // initializing all elements to zero
        count[i] = 0;

    for(i=0;i<n;i++)    // incrementing the occurrence of element in A as index in count
        count[A[i]]++;

    i=0, j=0;

    while(i < max+1)
    {
        if(count[i] > 0)
        {
            A[j++] = i;

            count[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int A[] = {10, 5, 3, 2, 9}, n = 5;

    countSort(A, n);

    for(int i=0;i<n;i++)    // for displaying the array elements
        cout<<A[i]<<" ";
}