#include<stdio.h>
#include<stdlib.h>

struct Array
{
      int n;
      int * A;
};

void set(struct Array * s)
{
     for(int i=0;i<s->n;i++)
     {
         printf("Enter the value : ");
         scanf("%d",&s->A[i]);
     }
}

void findMissElements(struct Array s)
{
    int diff = s.A[0];

    for(int i=1;i<s.n;i++)
    {
        if(diff != s.A[i]-i)
        {
            while(diff<s.A[i]-i)
            {
                 printf("Missing Element : %d\n",diff+i);
                 diff++;
            }
        }   
    }
}

int main()
{
    struct Array arr;
    
    printf("Enter the number of elements in an array : ");
    scanf("%d",&arr.n);

    arr.A = (int *)malloc(arr.n*sizeof(int));

    set(&arr);
    
    findMissElements(arr);

}