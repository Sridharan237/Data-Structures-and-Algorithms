//C program to search in a  linked list iteratively, recursively and improve searching by move to head (or) front
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

int Iterativecount(struct Node* p)
{
    int count = 0;

    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

int RecursiveCount(struct Node* p)
{
    if(p)
    {
        return RecursiveCount(p->next) + 1;
    }

    return 0;
}

//Iterative function for Linear Search in a linked list
struct Node * LSearch(struct Node* p, int key)
{
    while(p)
    {
        if(key == p->data)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

//Recursive function for Linear Search in a linked list
struct Node * RLSearch(struct Node * p, int key)
{
    if(p == NULL)
        return NULL;

    if(key == p->data)
        return p;

    return RLSearch(p->next, key);
}

//Iterative function for improve searching using Linear Search in a linked list using move to front (or) head method
struct Node * ImproveLSearch(struct Node * p, int key)
{
    struct Node * q = NULL;    //previous node pointer for p

    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;     // move to front (or) head method
            p->next = first;
            first = p;

            return p;
        }

        q = p;
        p = p->next;
    }

    return NULL;
}

int main()
{
    struct Node * temp;

    int A[] = {3, 5, 7, 9, 10};

    create(A, 5);

    Display(first);

    temp = ImproveLSearch(first, 10);

    if(temp)
        printf("Key is Found %d\n", temp->data);
    else
        printf("Key is not Found\n");

    Display(first);

   
    return 0;
}