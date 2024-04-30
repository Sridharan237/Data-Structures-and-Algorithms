// cpp program to write a class for queue using array and perfrom various operations
#include<iostream>

using namespace std;

// class for Queue
class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue() {size = 10;front = rear = -1;Q = new int[size];};
    Queue(int size) {this->size = size;front = rear = -1;Q = new int[this->size];}

    void enqueue(int x);
    int dequeue();

    void display();

    bool isEmpty();
    bool isFull();
};

// implementing the above functions of the class

//  function to perfrom enqueue operation on a queue
void Queue :: enqueue(int x)
{
    if(isFull())
        cout<<"\nQueue is Full"<<endl;
    else
    {
        rear++;

        Q[rear] = x;
    }
}

//  function to perform dequeue operation on a queue 
int Queue :: dequeue()
{
    int x = -1;

    if(isEmpty())
        cout<<"\nQueue is empty"<<endl;
    else
    {
        front++;

        x = Q[front];
    }

    return x;
}

//  function to perform display operation
void Queue :: display()
{
    int i;

    for(i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";

    cout<<"\n";
}

//  function to check whether queue is empty or not
bool Queue :: isEmpty()
{
    if(front == rear)
        return true;
    return false;
}

//  function to check whether queue is full or not
bool Queue :: isFull()
{
    if(rear == size-1)
        return true;
    return false;
}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout<<"Deleted Element : "<<q.dequeue()<<endl;

    q.display();
}