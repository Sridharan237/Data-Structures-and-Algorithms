// c program to create, display and perform various operations on a Circular Queue using array 
#include<stdio.h>
#include<stdlib.h>

// structure for a queue
struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// function to check whether a Circular queue is emtpy or not
int isEmpty(struct CircularQueue cq)
{
    if(cq.front == cq.rear)
        return 1;
    return 0;
}

// function to check whether a Circular queue is full or not
int isFull(struct CircularQueue cq)
{
    if((cq.rear+1)%cq.size == cq.front)
        return 1;
    return 0;
}

//  function to perform enqueue operation on a Circular queue
void enqueue(struct CircularQueue *cq, int x)
{
    if(isFull(*cq))  // dereferencing structure pointer - q
        printf("\nCircular Queue is full\n");
    else
    {
        cq->rear = (cq->rear + 1) % cq->size;
        cq->Q[cq->rear] = x;
    }
}

//  function to perfrom dequeue operation on a Circular queue
int dequeue(struct CircularQueue *cq)
{
    int x = -1;

    if(isEmpty(*cq)) // dereferencing structure pointer - q
        printf("\nCircular Queue is empty\n");
    else
    {
        cq->front = (cq->front + 1) % cq->size;
        
        x = cq->Q[cq->front];
    }

    return x;
}  

//  function to display a Circular queue 
void display(struct CircularQueue cq)
{
    int i = cq.front+1;

    do
    {
        printf("%d ", cq.Q[i]);
        
        i = (i+1)%cq.size;
    } while (i!=(cq.rear+1)%cq.size);
    
    printf("\n");
}

int main()
{
    struct CircularQueue cq;

    printf("Enter the size of queue : ");
    scanf("%d", &cq.size);

    cq.Q = (int *)malloc(cq.size*sizeof(int));

    // Queue initialized
    cq.front = cq.rear = 0;

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);

    display(cq);

    printf("Deleted element : %d\n", dequeue(&cq));

    display(cq);
}