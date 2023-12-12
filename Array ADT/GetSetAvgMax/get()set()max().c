#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
       printf("%d ",arr.A[i]);
}

int main()
{
    struct Array arr={{3,8,5,7,9},10,5};

    display(arr);
}