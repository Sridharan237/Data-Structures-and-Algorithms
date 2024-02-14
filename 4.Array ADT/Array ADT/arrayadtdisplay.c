#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
     int i;

     printf("Elements are\n");
     for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}
int main()
{
    struct Array arr;
    int n,i;

    printf("Enter the size of an array:");
    scanf("%d",&arr.size);
    arr.length = 0;
    arr.A = (int *)malloc(arr.size*sizeof(int));

    printf("Enter the number of elements of an array:");
    scanf("%d",&n);
    arr.length = n;
    
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
       scanf("%d",&arr.A[i]);

    Display(arr);
}