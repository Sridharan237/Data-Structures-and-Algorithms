//C program for diagonal matrix
#include<stdio.h>

struct Matrix
{
    int A[10];
    int n;              //no. of elements in the array
};

void Set(struct Matrix * m, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i == j)
    {
        m->A[i-1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i == j)
        return m.A[i-1];
    else 
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;

    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i == j)
                printf("%d ", m.A[i-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    Set(&m, 1,1, 1);
    Set(&m, 2,2, 2);
    Set(&m, 3,3, 3);
    Set(&m, 4,4, 4);
    Set(&m, 5,5, 5);
    m.n = 5;
    
    printf("%d \n",Get(m, 3, 2));

    Display(m);
}