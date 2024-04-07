//C program to concatenate two linked lists

#include<stdio.h>
#include<stdlib.h>
#define MIN_INT -65536     // 4byte minimum integer

struct Node 
{
    int data;
    struct Node * next;
}*first=NULL,*second=NULL,*third=NULL;

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

void create2(int A[], int n)
{
    struct Node *t, *last;

    int i;

    second = (struct Node*)malloc(sizeof(struct Node));       //first (or) head node

    second->data = A[0];                     
    second->next = NULL;
    last = second;

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

int isSorted(struct Node* p)
{
    int x = MIN_INT;    //macro

    while(p)
    {
        if(x > p->data)
            return 0;
        
        x = p->data;
        p = p->next;
    }

    return 1;
}

void RemoveDuplicates(struct Node* p)
{
    struct Node* q = first->next;   // Here, p-tailing (or) following pointer of pointer - q

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

//function for Reversing a linked list by method - 1.Reversing elements
void Reverse1(struct Node *p)
{
    struct Node *q = p;     // Here, q - is a temporary pointer (or) linked list traversing pointer
    int *A, i=0;

    A = (int *)malloc(sizeof(int)*Iterativecount(p));

    // for copying elements from linked list to array
    while(q != NULL)
    {
        A[i++] = q->data;
        q = q->next;
    }

    q = p;
    i--;

    // for copying elements from array to linked list
    while(q != NULL)
    {
        q->data = A[i--];
        q = q->next;
    }   
}

// function for reversing a linked list using method - 2.Reversing links
void Reverse2(struct Node *p)
{
    struct Node *q, *r;
    q = r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// function for reversing a linked list using - method 2.Reversing links by Recursion
void Reverse3(struct Node *q, struct Node *p)
{
    if(p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

//function to concatenate 2 linked lists
void Concatenate(struct Node *p, struct Node *q)
{
    third = p;  // third is the head node of the concatenated linked list

    while(p->next != NULL)
        p = p->next;

    p->next = q;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {1, 2, 0, 4, -1};

    create(A, 5);
    create2(B, 5);

    printf("\nFirst\n");
    Display(first);
    printf("\n");

    printf("\nSecond\n");
    Display(second);
    printf("\n");

    return 0;
}