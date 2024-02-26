//C program for symmetric matrix using => upper triangular matrix using column major mapping
#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

void Set(struct Matrix * smutm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i <= j)
    {
        smutm->A[(j*(j-1)/2)+(i-1)] = x;
    }
}

int Get(struct Matrix smutm, int i, int j)
{
    if(i <= j)
        return smutm.A[(j*(j-1)/2)+(i-1)];
    else 
        return 0;
}

void Display(struct Matrix smutm)
{
    int i, j;

    for(i=1;i<=smutm.n;i++)
    {
        for(j=1;j<=smutm.n;j++)
        {
            if(i <= j)
                printf("%d ", smutm.A[(j*(j-1)/2)+(i-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix smutm;

    printf("Enter the dimension : ");
    scanf("%d", &smutm.n);

    smutm.A = (int *)malloc(smutm.n*(smutm.n+1)/2*sizeof(int));

    int i, j, x;

    printf("Enter all the elements of the array : ");

    for(i=1;i<=smutm.n;i++)
    {
        for(j=1;j<=smutm.n;j++)
        {
            scanf("%d", &x);
            Set(&smutm, i, j, x);
        }
    }
    
    printf("%d \n",Get(smutm, 3, 2));

    Display(smutm);
}