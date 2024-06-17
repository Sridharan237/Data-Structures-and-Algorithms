// cpp program to implement quick sort
#include<iostream>

using namespace std;

// function to perform partition
int partition(int A[], int low, int high)
{
    int i, j;
    int pivot = A[low];    // Here, selecting first element as pivot

    i = low, j = high;

    do
    {
        do {i++;}while(A[i] <= pivot);   // starting from first
        do {j--;}while(A[j] > pivot);  // starting from last

        if(i < j) swap(A[i], A[j]);
    }while(i<j);
    

    if(i > j)   // finished scanning the whole array - crossed their path
        swap(A[low], A[j]);     // A[low] - pivot

    return j;   // return pivot's position
}

// function to implement quick sort
void quickSort(int A[], int low, int high)
{
    int j;

    if(low < high)
    {
        j = partition(A, low, high);

        quickSort(A, low, j);
        quickSort(A, j+1, high);
    }
}

int main()
{
    int A[] = {10, 15, 3, 4, 8, INT32_MAX}, n = 6;  //  INT32_MAX - to denote the end of list

    quickSort(A, 0, 5);

    for(int i=0;i<n-1;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
}