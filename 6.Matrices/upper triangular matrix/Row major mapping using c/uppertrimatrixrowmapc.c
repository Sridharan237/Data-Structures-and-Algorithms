//C program for upper triangular matrix using row major mapping
#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

void Set(struct Matrix * utm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i <= j)
    {
        utm->A[n*(i-1)-(i-2)*(i-1)/2+j-i] = x;
    }
}

int Get(struct Matrix utm, int i, int j)
{
    if(i >= j)
        return utm.A[n*(i-1)-(i-2)*(i-1)/2+j-i];
    else 
        return 0;
}

void Display(struct Matrix utm)
{
    int i, j;

    for(i=1;i<=utm.n;i++)
    {
        for(j=1;j<=utm.n;j++)
        {
            if(i >= j)
                printf("%d ", utm.A[n*(i-1)-(i-2)*(i-1)/2+j-i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix utm;

    printf("Enter the dimension : ");
    scanf("%d", &utm.n);

    utm.A = (int *)malloc(utm.n*(utm.n+1)/2*sizeof(int));

    int i, j, x;

    printf("Enter all the elements of the array : ");

    for(i=1;i<=utm.n;i++)
    {
        for(j=1;j<=utm.n;j++)
        {
            scanf("%d", &x);
            Set(&utm, i, j, x);
        }
    }
    
    printf("%d \n",Get(utm, 3, 2));

    Display(utm);
}