//program to find single missing elements in an Array  and the array elements are starting from 1
#include<stdio.h>
#include<stdlib.h>

struct Array
{
       int n;
       int *A;
};

int main()
{
    struct Array arr;

    printf("Enter the number of elements : ");
    scanf("%d",&arr.n);
    
    printf("Enter the elements : \n");
    
    arr.A = (int *)malloc(arr.n*sizeof(int));

    for(int i=0;i<arr.n;i++)
    {
        scanf("%d",&arr.A[i]);
    }

    int sum1 = 0;
    int lastElement = 0;

    int i=0;
    
    lastElement = arr.A[arr.n-1];

    int sum2 = lastElement*(lastElement+1)/2;             //sum of first n natural numbers (starting from 1) = n*(n+1)/2

    for(int i=0;i<arr.n;i++)
    {
        sum1 += arr.A[i];
    }

    int missingElement = sum2-sum1;

    printf("Sum1 is : %d\nSum2 is : %d\n", sum1,sum2);

    
    printf("Missing element is : %d",missingElement);
}