//reverse ,shift ,rotate an array
#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse1(struct Array * arr)         //using Auxillary array
{
     int *B;
     B=(int *)malloc(arr->length*sizeof(int));
     int i,j;

     for(i=arr->length-1,j=0;i>=0;i--,j++)
         B[j]=arr->A[i];
     
     for(i=0;i<arr->length;i++)
         arr->A[i]=B[i];
}

void Reverse2(struct Array * arr)                //without using auxillary array
{
     int i,j;

     for(i=0,j=arr->length-1;i<j;i++,j--)
         swap(&arr->A[i],&arr->A[j]);
}

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
       printf("%d ",arr.A[i]);
}

void leftshift(struct Array * arr)
{
    int i;

    for(i=1;i<arr->length;i++)
        arr->A[i-1]=arr->A[i];
    arr->A[arr->length-1]=0;
}

void leftrotate(struct Array * arr)
{
    int i,temp;
    temp=arr->A[0];

    for(i=1;i<arr->length;i++)
        arr->A[i-1]=arr->A[i];
    arr->A[arr->length-1]=temp;
}

void rightshift(struct Array * arr)
{
    int i;

    for(i=arr->length-1;i>0;i--)
        arr->A[i]=arr->A[i-1];
    arr->A[0]=0;
}

void rightrotate(struct Array * arr)
{
    int i,temp;
    temp=arr->A[arr->length-1];

    for(i=arr->length-1;i>0;i--)
        arr->A[i]=arr->A[i-1];
    arr->A[0]=temp;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};

    rightrotate(&arr);
    

    display(arr);
}