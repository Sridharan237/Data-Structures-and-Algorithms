// c program to create, display and find the length of a doubly linked list
#include<stdio.h>
#include<stdlib.h>

// Node structure of a doubly linked list
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

// function for creating a doubly linked list
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));

    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;

    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = A[i];
        t->next = NULL;

        last->next = t;
        t->prev = last;
        last = t;
    }
}

// function to find the length of a doubly linked list
int Length(struct Node *p)
{
    int len = 0;

    while(p)
    {
        len++;
        p = p->next;
    }

    return len;
}

// function to display a doubly linked list
void Display(struct Node *p)
{
    while(p)
    {
        if(p->next != NULL)
            printf("%d<->", p->data);
        else
           printf("%d->", p->data); 
        p = p->next;
    }
    printf("NULL");
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    create(A, 5);

    printf("\nLength : %d\n", Length(first));

    Display(first);

    return 0;
}