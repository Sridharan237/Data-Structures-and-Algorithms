//C program for toeplitz matrix

#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

void Set(struct Matrix * tm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i <= j)
    {
        tm->A[j-i] = x;
    }
    else if(i > j)
    {
        tm->A[n+i-j-1] = x;
    }
}

int Get(struct Matrix tm, int i, int j)
{
    if(i <= j)
    {
        return tm->A[j-i];
    }
    else if(i > j)
    {
        return tm->A[n+i-j-1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix tm)
{
    int i, j;

    for(i=1;i<=tm.n;i++)
    {
        for(j=1;j<=tm.n;j++)
        {
            if(i <= j)
            {
                printf("%d ", tm->A[j-i]);
            }   
            else if(i > j)
            {
                printf("%d ", tm->A[n+i-j-1]);
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
    struct Matrix tm;

    printf("Enter the dimension : ");
    scanf("%d", &tm.n);

    tm.A = (int *)malloc((2*tm.n-1)*sizeof(int));

    int i, j, x;

    printf("Enter all the elements of the array : ");

    for(i=1;i<=tm.n;i++)
    {
        for(j=1;j<=tm.n;j++)
        {
            scanf("%d", &x);
            Set(&tm, i, j, x);
        }
    }
    
    printf("%d \n",Get(tm, 3, 2));

    Display(tm);
}