// cpp program to implement bubble sort with adaptive(flag)
#include<iostream>

using namespace std;

// function to swap 2 numbers in their respective addresses
void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}

// function to implement Bubble Sort with adaptive (flag)
void BubbleSort(int A[], int n)
{
    int i, j, flag;

    for(i=0;i<n-1;i++)  // passing
    {
        flag = 0;

        for(j=0;j<n-1-i;j++)    // swapping
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);

                flag = 1;           
            }
        }

        if(flag == 0)   // array already sorted
            break;
    }
}

int main()
{
    int A[] = {10, 15, 3, 4, 8}, n = 5;

    BubbleSort(A, n);

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
}