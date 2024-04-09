// c program to insert in a singly circular linked list 
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

// function to count the no. of nodes in a circular linked list
int Length(struct Node *p)
{
    int count = 0;

    do
    {
        count++;
        p = p->next;
    }while(p != Head);

    return count;
}

// function to insert a node in a singly circular linked list at any given position
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    // index validation
    if(index < 0 || index > Length(Head))
        return;
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        if(index == 0)  // Before Head node  
        {
            if(Head == NULL)    // If there is no node is present (LL is empty)
            {
                Head = t;
                Head->next = Head; // Head will point itself when we have 1 one noce
            }
            else
            {
                while(p->next != Head) 
                    p = p->next;

                p->next = t;
                t->next = Head;
                Head = t;   
            }
        }
        else    // Inserting at any given position 
        {
            for(i=0;i<index-1;i++) 
                p = p->next;

            t->next = p->next;
            p->next = t;
        }
    }

}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    create(A, 5);
    
    Insert(Head, 0, 10);

    Display(Head);

    return 0;
}