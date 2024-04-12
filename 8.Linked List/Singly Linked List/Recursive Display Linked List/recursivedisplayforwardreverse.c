//C program to display linked list recursively in forward and reverse directions 
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
    printf("NULL");
}

void RforwardDisplay(struct Node* p)
{
    if(p != NULL)
    {
        printf("%d->", p->data);
        RforwardDisplay(p->next);
    }
    else
    {
        printf("NULL\n");
    }
}

void RreverseDisplay(struct Node* p)
{
    if(p != NULL)
    {
        RreverseDisplay(p->next);
        printf("->%d", p->data);
    }
    else
    {
        printf("NULL");
    }
}

int main()
{
    int A[] = {3, 5, 7, 9, 10};

    create(A, 5);

    RforwardDisplay(first);

    RreverseDisplay(first);

    return 0;
}