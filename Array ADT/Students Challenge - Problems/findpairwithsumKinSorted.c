//program to find pair of elements in a sorted array with sum K and array without duplicates
#include<stdio.h>
#include<stdlib.h>

void findSumWithPairKinSorted(int *A, int size, int sum)
{ 
    int i,j;

    for(i=0,j=size-1;i<j; )      //Here, we are giving modification (or) updation statement in the for loop
    {
        if(A[i]+A[j] == sum)
        {
           printf("%d + %d = %d\n", A[i], A[j], sum);
           i++,j--;
        }
        else if(A[i]+A[j]>sum)
        {
           j--;
        }
        else                           //   (or) condition : A[i]+A[j]<sum  
        {
            i++;
        }
    }
}

int main()
{
    int array[] = {1,2,3,4,6,8,9,10,12,14,15};
    
    int size = sizeof(array)/sizeof(array[0]);
    
    findSumWithPairKinSorted(array, size, 10); //Here, sum (or) k is 10
}