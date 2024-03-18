//program for creating and displaying sparse matrix

#include<stdio.h>
#include<stdlib.h>

struct Element 
{
    int i;  //row number
    int j;  //column number
    int x;  //non-zero element
};

struct Sparse 
{
    int m;  //no. of rows
    int n;  //no. of columns
    int N;  //no. of non-zero elements
    struct Element * element;   //for storing and pointing to the non-zero elements in the heap
};

//function for creating sparse matrix
void create(struct Sparse * s)
{ 
    printf("Enter the dimensions:");
    scanf("%d %d %d", &s->m, &s->n, &s->N);

    //creating memory in heap
    s->element = (struct Element *)malloc(s->N*sizeof(struct Element));

    printf("Enter all the non-zero elements : \n");

    for(int i=0;i<s->N;i++)
    {
        scanf("%d %d %d", &s->element[i].i, &s->element[i].j, &s->element[i].x);
    }
}

//function for displaying sparse matrix

void display(struct Sparse s)
{
    int i, j, k=0;

    printf("Sparse Matrix : \n");

    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i == s.element[k].i && j == s.element[k].j)
            {
                printf("%d ", s.element[k++].x);    //k++ -> post increment - 1.assign, 2.increment
            }
            else 
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Sparse s;

    create(&s);

    display(s);

    return 0;
}