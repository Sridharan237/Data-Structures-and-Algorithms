//C program to delete in a  linked list iteratively

//cases
//1.delete first node
//2.delete at a given position

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

//function to insert a node at given position
void Insert(struct Node* p, int index, int x)   //x - element (or) data to be inserted
{
    int i;

    struct Node* t = (struct Node *)malloc(sizeof(struct Node));

    if(index < 0 && index > Iterativecount(p))
        return ;
    
    //node creation and data setting
    t->data = x;

    if(index == 0)  //case 1 : inserting before first node
    {
        t->next = first;
        first = t;
    }
    else if(index > 0)  // case 2: inserting at a given position
    {
        for(i=0;i<index-1 && p;i++)     //traversing the linked list and checking if p is NULL (or) not
            p = p->next;
        
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

//function for inserting in a sorted position in a linked list
void sortedInsert(struct Node *p, int x)
{
    struct Node *t, *q=NULL;

    t = (struct Node*)malloc(sizeof(struct Node));

    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data<x)
        {
            q = p;
            p = p->next;
        }

        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// function to delete a node in a linked list at a given position 
int Delete(struct Node* p, int position) //position - 1 to n
{
    struct Node* q = NULL;  //tailing (or) following pointer

    int x = -1, i;

    if(position < 1 || position > Iterativecount(p))
        return x;

    if(position == 1)
    {
        first = first->next;
        x = p->data;
        free(p);
    }
    else
    {
        for(i=0;i<position-1;i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {3, 5, 7, 9, 10};

    create(A, 5);

    printf("Deleted Element : %d\n", Delete(first, 3));

    Display(first);
   
    return 0;
}