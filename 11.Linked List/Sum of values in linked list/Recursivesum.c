//C program to sum of all elements in linked list recursively
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node * next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;

    int i;

    first = (struct Node*)malloc(sizeof(struct Node));       //first (or) head node

    first->data = A[0];                     
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)       //create and append to the previous node and make point the last pointer to the created node
    {
        t = (struct Node*)malloc(sizeof(struct Node));

        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

void Display(struct Node* p)
{
    while(p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int IterativeCount(struct Node* p)
{
    int count = 0;

    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

int IterativeSum(struct Node* p)
{
    int sum = 0;

    while(p)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int RecursiveSum(struct Node* p)
{
    int sum = 0;

    if(p)
    {
        return RecursiveSum(p->next) + p->data;
    }

    return 0;
}

int main()
{
    int A[] = {3, 5, 7, 9, 10};

    create(A, 5);

    Display(first);

    printf("Sum of all values in linked list is : %d\n", RecursiveSum(first));


    return 0;
}