//C program for symmetric matrix using => lower triangular matrix using column major mapping
#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

void Set(struct Matrix * smltm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i >= j)
    {
        smltm->A[smltm->n*(j-1) -(j-2)*(j-1)/2 + (i-j)] = x;
    }
}

int Get(struct Matrix smltm, int i, int j)
{
    if(i >= j)
        return smltm.A[smltm.n*(j-1) -(j-2)*(j-1)/2 + (i-j)];
    else 
        return 0;
}

void Display(struct Matrix smltm)
{
    int i, j;

    for(i=1;i<=smltm.n;i++)
    {
        for(j=1;j<=smltm.n;j++)
        {
            if(i >= j)
                printf("%d ", smltm.A[smltm.n*(j-1) -(j-2)*(j-1)/2 + (i-j)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix smltm;

    printf("Enter the dimension : ");
    scanf("%d", &smltm.n);

    smltm.A = (int *)malloc(smltm.n*(smltm.n+1)/2*sizeof(int));

    int i, j, x;

    printf("Enter all the elements of the array : ");

    for(i=1;i<=smltm.n;i++)
    {
        for(j=1;j<=smltm.n;j++)
        {
            scanf("%d", &x);
            Set(&smltm, i, j, x);
        }
    }
    
    printf("%d \n",Get(smltm, 3, 2));

    Display(smltm);
}