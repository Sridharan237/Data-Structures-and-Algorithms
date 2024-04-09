// c program to insert values into a doubly linked list
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
        printf("%d<->", p->data);
        p = p->next;
    }
    printf("NULL");
}

// function to insert into a doubly linked list
void Insert(struct Node *p, int index, int x)
{
    struct Node *t; 
    int i;

    if(index < 0 || index > Length(p))
        return ;
    
    if(index == 0)  // insert before first node
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = x;
        t->prev = NULL;

        if(first == NULL) // No first node
        {
            first = t;
            first->next = NULL;
        }
        else
        {
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = x;

        for(i=0;i<index-1;i++) 
            p = p->next;
        
        t->prev = p;
        t->next = p->next;
        
        if(p->next) p->next->prev = t;

        p->next = t;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    create(A, 5);

    Insert(first, 5, 15);

    printf("\nLength : %d\n", Length(first));

    Display(first);

    return 0;
}