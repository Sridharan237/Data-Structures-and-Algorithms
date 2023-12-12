//program to find duplicates and count duplicates in an unsorted array
#include<stdio.h>
#include<stdlib.h>

void findCountDuplicatesUnsorted(int *A, int size)     //function for finding and counting duplicates in an unsorted array
{
    int count;
    
    for(int i=0;i<size-1;i++)
    {
        if(A[i] != -1)
        {
            count = 1;

            for(int j=i+1;j<size;j++)
            {
                if(A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }

            if(count>1)
            {
                printf("Duplicate %d is appearing %d times\n", A[i], count);
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

void findCountDuplicatesHashUnsorted(int A[], int size)       //function for finding and counting duplicates in an unsorted array using hashing
{
    int max = maxElement(A, size);
     
    int* H= (int *)malloc(max*sizeof(int));     //Hash table

   for(int i=0;i<=max;i++)          //for making all the values in Hash table as 0
    {
        H[i] = 0;
    }
   

    for(int i=1;i<size;i++)    // for incrementing values in hash table
    {
        H[A[i]]++;
    }

    for(int i=1;i<=max;i++)
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

    findCountDuplicatesUnsorted(array, size);
    findCountDuplicatesHashUnsorted(array, size);
}