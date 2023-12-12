#include<stdio.h>

struct Array
{
      int A[10];
      int size;
      int length;
};

void Display(struct Array arr)
{
    int i;
    
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct Array *arr,int key)       // key or target value 
{
    int i;

    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        { 
           //swap(&arr->A[i],&arr->A[i-1]);      ---> transposition
            swap(&arr->A[i],&arr->A[0]);        // ---> move to front / head
           return i;
        }
    }
    return -1;
}
int main()
{
    struct Array arr={{2,3,5,7,9},10,5};

    printf("%d\n",LinearSearch(&arr,5));
    Display(arr);
}