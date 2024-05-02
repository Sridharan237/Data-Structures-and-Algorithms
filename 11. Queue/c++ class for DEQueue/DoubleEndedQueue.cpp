//  cpp program for DEQueue - Double Ended Queue 
#include<iostream>

using namespace std;

// class for DEQueue - Double Ended Queue
class DEQueue
{
private:
    int size;
    int front;  // here, front - always points before the first element
    int rear;   // here, rear - always points at the last element
    int *Q;

public:
    DEQueue() {size = 10;front = rear = -1;Q = new int[size];}
    DEQueue(int size) {this->size = size;front = rear = -1;Q = new int[this->size];} 

    void insertAtFront(int x);
    int deleteAtFront();
    void insertAtLast(int x);
    int deleteAtLast();

    void display();

    bool isEmpty();
    bool isFull();
};

// implementing the above functions of the class

//  function to perform insertion at front
void DEQueue :: insertAtFront(int x)
{
    if(isFull())
        return ;
    else
    {
        if(isEmpty())
        {
            return ;
        }
        else if(!(front <= -1))
        {
            Q[front] = x;

            front--;
        }
    }
}

//  function to perform deletion at Front
int DEQueue :: deleteAtFront()
{
    int x = -1;

    if(isEmpty())
        return x;
    else
    {
        front++;

        x = Q[front];
    }

    return x;
}

//  function to perform insertion at Last
void DEQueue :: insertAtLast(int x)
{
    if(isFull())
        return ;
    else
    {
            rear++;

            Q[rear] = x;
    }
}

//  function to perform Deletion at Last
int DEQueue :: deleteAtLast()
{
    int x = -1;

    if(isEmpty())
        return x;
    else
    {
        x = Q[rear];

        rear--;
    }

    return x;
}

//  function to check whether DEQueue is Empty or not
bool DEQueue :: isEmpty()
{
    if(front == rear)
    {
        cout<<"\nDEQueue is Emtpy\n";

        return true;
    }

    return false;
}

//  function to check whether DEQueue is Full or not
bool DEQueue :: isFull()
{
    if(rear == size-1)
    {
        cout<<"\nDEQueue is Full\n";

        return true;
    }

    return false;
}

//  function to display a DEQueue 
void DEQueue :: display()
{
    int i;

    for(i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";
    
    cout<<endl;
}

int main()
{
    DEQueue dq;

    dq.insertAtLast(10);
    dq.insertAtLast(20);
    dq.insertAtLast(30);
    dq.insertAtLast(40);

    dq.display();

    cout<<"Deleted Element At Last : "<<dq.deleteAtLast()<<endl;

    dq.display();

    cout<<"Deleted Element At Front : "<<dq.deleteAtFront()<<endl;
    cout<<"Deleted Element At Front : "<<dq.deleteAtFront()<<endl;

    dq.display();

    dq.insertAtFront(100);
    dq.insertAtFront(200);

    dq.display();
}