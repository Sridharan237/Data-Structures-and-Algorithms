// c program to create, display a queue and perform various operations on a queue using array 
#include<stdio.h>
#include<stdlib.h>

// structure for a queue
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// function to check whether a queue is emtpy or not
int isEmpty(struct Queue q)
{
    if(q.front == q.rear)
        return 1;
    return 0;
}

// function to check whether a queue is full or not
int isFull(struct Queue q)
{
    if(q.rear == q.size-1)
        return 1;
    return 0;
}

//  function to perform enqueue operation on a queue
void enqueue(struct Queue *q, int x)
{
    if(isFull(*q))  // dereferencing structure pointer - q
        printf("\nQueue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

//  function to perfrom dequeue operation on a queue
int dequeue(struct Queue *q)
{
    int x = -1;

    if(isEmpty(*q)) // dereferencing structure pointer - q
        printf("\nQueue is empty\n");
    else
    {
        q->front++;
        
        x = q->Q[q->front];
    }

    return x;
}  

//  function to display a queue 
void display(struct Queue q)
{
    int i;

    for(i=q.front+1;i<=q.rear;i++)
        printf("%d ", q.Q[i]);
    
    printf("\n");
}

int main()
{
    struct Queue q;

    printf("Enter the size of queue : ");
    scanf("%d", &q.size);

    q.Q = (int *)malloc(q.size*sizeof(int));

    // Queue initialized
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);

    printf("Deleted element : %d\n", dequeue(&q));

    display(q);
}