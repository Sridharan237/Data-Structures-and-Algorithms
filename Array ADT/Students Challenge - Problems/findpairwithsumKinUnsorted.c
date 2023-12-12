//program to find pair of elements in an unsorted array with sum K and array without duplicates
#include<stdio.h>
#include<stdlib.h>

void findSumWithPairKinUnsorted(int *A, int size, int sum)    //function to find pair of elements with sum k in an unsorted array
{ 
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(A[i]+A[j] == sum)
            {
                printf("%d + %d = %d\n", A[i], A[j], sum);
            }
        }
    }
}

int maxElement(int A[], int size)               //--->     int[] A (or)   int A[]     (or)    int * A
{
    int max = A[0];

    for(int i=1;i<size;i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }

    return max;
}

void findSumWithPairKinUnsortedHash(int *A, int size, int sum)      //function to find a pair of elements with sum k in an unsorted array 
{ 
    int max;
    
    max = maxElement(A, size);

    int* H= (int *)malloc(max*sizeof(int));     //Hash table
    H[0] = 0;

    for(int i=1;i<=max;i++)          //for making all the values in Hash table as 0
    {
        H[i] = 0;
    }
    
    for(int i=0;i<size;i++)
    {
        H[A[i]]++;

        if(H[sum-A[i]] == 1 && A[i]<= sum && sum-A[i] != A[i])           // Here, a + b = c , then b = c - a
        {
            printf("%d + %d = %d\n", A[i], sum-A[i], sum);
        }
    }
}


int main()
{
    int array[] = {9,8,12,14,3,7,2,4,11,10,6,5};
    
    int size = sizeof(array)/sizeof(array[0]);
    
    findSumWithPairKinUnsorted(array, size, 10); //Here, sum (or) k is 10
    findSumWithPairKinUnsortedHash(array, size, 10);
}