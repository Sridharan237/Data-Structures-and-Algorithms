#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

int Delete(struct Array *arr,int index)
{
    int x=0,i;

    if(index >= 0 && index <arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;

        return x;
    }

    return 0;
}
void Display(struct Array arr)
{
     int i;

     printf("Elements are\n");
     for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int main()
{
    struct Array arr1 = {{1,2,3,4,5},10,5};

    printf("Truncated value : %d\n",Delete(&arr1,4));

    Display(arr1);
}