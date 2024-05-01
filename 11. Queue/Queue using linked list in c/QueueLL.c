// c program to create a Queue using linked list in c
#include<stdio.h>
#include<stdlib.h>

//structrue for a Node
struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

//  To check whether a queue is empty or not
int isEmpty()
{
    if(front == NULL)
        return 1;
    return 0;
}

//  function to perform enqueue operation
void enqueue(int x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));

    if(t == NULL)   // Means - Heap is Full
       printf("\nQueue is Full\n"); 
    else
    {
        t->data = x;
        t->next = NULL;

        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    } 
}

//  function to perform dequeue operation 
int dequeue()
{
    int x = -1;

    struct Node *p;

    if(isEmpty())
        printf("\nQueue is empty\n");
    else
    {
        p = front;

        front = front->next;

        x = p->data;

        free(p);
    }

    return x;
}

//  function to display a queue
void display()
{
    struct Node *p = front;

    while(p != NULL)
    {
        printf("%d ", p->data);

        p = p->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    printf("Deleted Element : %d\n", dequeue());

    display();
}