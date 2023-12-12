//program to find minimum and maximum element in single scan in array
#include<stdio.h>

void findMinMax(int *A, int size)      //function to find minimum and maximum element in a single for loop 
{ 
    int min,max;

    min = max = A[0];

    for(int i=1;i<size;i++)      
        if(A[i]<min)
        {
           min = A[i];
        }
        else if(A[i]>max)
        {
           max = A[i];
        }

    printf("Minimum element : %d\n", min);
    printf("Maximum element : %d\n", max);
}

int main()
{
    int array[] = {9,3,1,16,7,2,12,19,8,4,11,-100};
    
    int size = sizeof(array)/sizeof(array[0]);
    
    findMinMax(array, size);
}