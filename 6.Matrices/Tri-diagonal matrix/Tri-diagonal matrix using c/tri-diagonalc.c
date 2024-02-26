//C program for tri-diagonal matrix
//By storing the 2D matrix in a 1D array by (lower-main-upper)diagonal order

#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

void Set(struct Matrix * tdm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i - j == 1)
    {
        tdm->A[i-2] = x;
    }
    else if(i - j == 0)
    {
        tdm->A[n-1+i-1] = x;
    }
    else if(i - j == -1)
    {
        tdm->A[n-1+n+i-1] = x;
    }
}

int Get(struct Matrix tdm, int i, int j)
{
    if(i - j == 1)
    {
        return tdm.A[i-2];
    }
    else if(i - j == 0)
    {
        return tdm.A[n-1+i-1];
    }
    else if(i - j == -1)
    {
        return tdm.A[n-1+n+i-1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix tdm)
{
    int i, j;

    for(i=1;i<=tdm.n;i++)
    {
        for(j=1;j<=tdm.n;j++)
        {
            if(i - j == 1)
            {
                printf("%d ", tdm.A[i-2]);
            }   
            else if(i - j == 0)
            {
                printf("%d ", tdm.A[n-1+i-1]);
            }
            else if(i - j == -1)
            {
                printf("%d ", tdm.A[n-1+n+i-1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix tdm;

    printf("Enter the dimension : ");
    scanf("%d", &tdm.n);

    tdm.A = (int *)malloc((3*tdm.n-2)*sizeof(int));

    int i, j, x;

    printf("Enter all the elements of the array : ");

    for(i=1;i<=tdm.n;i++)
    {
        for(j=1;j<=tdm.n;j++)
        {
            scanf("%d", &x);
            Set(&tdm, i, j, x);
        }
    }
    
    printf("%d \n",Get(tdm, 3, 2));

    Display(tdm);
}