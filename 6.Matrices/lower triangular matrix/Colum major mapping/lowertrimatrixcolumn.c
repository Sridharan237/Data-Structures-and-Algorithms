//C program for lower triangular matrix using column major mapping
#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

void Set(struct Matrix * ltm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i >= j)
    {
        ltm->A[ltm->n*(j-1) + (i-j)] = x;
    }
}

int Get(struct Matrix ltm, int i, int j)
{
    if(i >= j)
        return ltm.A[ltm.n*(j-1) + (i-j)];
    else 
        return 0;
}

void Display(struct Matrix ltm)
{
    int i, j;

    for(i=1;i<=ltm.n;i++)
    {
        for(j=1;j<=ltm.n;j++)
        {
            if(i >= j)
                printf("%d ", ltm.A[ltm.n*(j-1) + (i-j)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix ltm;

    printf("Enter the dimension : ");
    scanf("%d", &ltm.n);

    ltm.A = (int *)malloc(ltm.n*(ltm.n+1)/2*sizeof(int));

    int i, j, x;

    printf("Enter all the elements of the array : ");

    for(i=1;i<=ltm.n;i++)
    {
        for(j=1;j<=ltm.n;j++)
        {
            scanf("%d", &x);
            Set(&ltm, i, j, x);
        }
    }
    
    printf("%d \n",Get(ltm, 3, 2));

    Display(ltm);
}