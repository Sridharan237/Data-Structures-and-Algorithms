//program to find duplicates and count duplicates in a sorted array
#include<stdio.h>
#include<stdlib.h>

void findDuplicates(int *A, int size)
{
    int lastDuplicate = 0;

    for(int i=0;i<size-1;i++)
    {
        if(A[i] == A[i+1] && A[i] != lastDuplicate)
        {
            printf("Duplicate : %d\n", A[i]);
            lastDuplicate = A[i]; 
        }
    }
}

void countDuplicates(int *A, int size)
{
    int count = 1;
    

    for(int i=0;i<size-1;i++)
    {
        if(A[i] == A[i+1])
        {
            j=i+1;

            while(A[j] == A[i])
            {
                j++;
            }
            printf("Duplicate %d is appearing %d times\n", A[i], j-i);
            i = j-1;
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

void findCountDuplicatesHash(int A[], int size)       //function for finding and counting duplicates using hashing
{
    int max = maxElement(A, size);
     
    int* H= (int *)malloc(max*sizeof(int));     //Hash table
    H[0] = 0;

    for(int i=1;i<=max;i++)          //for making all the values in Hash table as 0
    {
        H[i] = 0;
    }

    for(int i=A[0];i<size;i++)    // for incrementing values in hash table
    {
        H[A[i]]++;
    }

    for(int i=0;i<=max;i++)
    {
        if(H[i]>1)
        {
            printf("Duplicate is %d appearing %d times\n", i, H[i]);
        }
    }
}

int main()
{
    int array[] = {1, 3, 3, 5, 7, 9, 9, 9, 10, 22, 22, 22, 200};
    
    int size = sizeof(array)/sizeof(array[0]);

    //findDuplicates(array, size);
    //countDuplicates(array, size);
    findCountDuplicatesHash(array, size);
}