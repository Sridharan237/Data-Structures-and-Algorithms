//C program to count no. of nodes in linked list iteratively
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

int main()
{
    int A[] = {3, 5, 7, 9, 10};

    create(A, 5);

    Display(first);

    printf("No. of nodes is : %d\n", IterativeCount(first));

    return 0;
}