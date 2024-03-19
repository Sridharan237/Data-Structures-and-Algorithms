//c program for 
// ->creating sparse matrix
// ->displaying sparse matrix
// ->add 2 sparse matrices

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

struct Sparse * add(struct Sparse * s1, struct Sparse * s2)
{
    struct Sparse * sum;

    //creating and pointing sum in heap
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));

    sum->m = s1->m;
    sum->n = s1->n;

    sum->element = (struct Element *)malloc((s1->N+s2->N)*sizeof(struct Element));

    int i, j, k;
    i=j=k=0;

    //Adding
    while(i<s1->N && j<s2->N)
    {
        if(s1->element[i].i < s2->element[j].i)
            sum->element[k++] = s1->element[i++];
        else if(s1->element[i].i > s2->element[j].i)
            sum->element[k++] = s2->element[j++];
        else
        {
            if(s1->element[i].j < s2->element[i].j)
                sum->element[k++] = s1->element[i++];
            else if(s1->element[i].j > s2->element[i].j)
                sum->element[k++] = s1->element[j++];
            else        //if both are at same row number and column number
            {
                sum->element[k] = s1->element[i++];
                sum->element[k++].x += s2->element[j++].x;
            }
        }
    }

    for(;i<s1->N;i++)
        sum->element[k++] = s1->element[i];

    for(;j<s2->N;j++)
        sum->element[k++] = s1->element[j];
    
    sum->N = k;
    
    return sum;
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
    struct Sparse s1, s2, *sum;

    create(&s1);
    create(&s2);

    sum = add(&s1, &s2);

    printf("First Matrix : \n");
    display(s1);

    printf("Second Matrix : \n");
    display(s2);

    printf("Sum Matrix : \n");
    display(*sum);      // deferencing the sum because it is call by value

    return 0;
}