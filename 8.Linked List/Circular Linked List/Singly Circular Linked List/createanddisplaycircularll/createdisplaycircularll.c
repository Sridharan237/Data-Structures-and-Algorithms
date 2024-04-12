// c program to create and display singly circular linked list 
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

// function for creating a singly circular linked list by passing an array as a parameter
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;  // making Head point to itself
    last = Head;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// function to display a linked list using iteration
void Display(struct Node *h)    // h-pointer to head of a circular linked list
{
    do
    {
        printf("%d->", h->data);
        h = h->next;
    } while (h!=Head);
    
}

// function to display a linked list using recursion
void RDisplay(struct Node *h)
{
    static int flag = 0; // flag variable 

    if(h != Head || flag == 0)
    {
        flag = 1;

        printf("%d->", h->data);
        RDisplay(h->next);
    }

    flag = 0;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    create(A, 5);

    Display(Head);

    return 0;
}