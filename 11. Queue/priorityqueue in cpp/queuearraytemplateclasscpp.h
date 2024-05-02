// cpp program to write a class for queue using array and perfrom various operations
#include<iostream>

using namespace std;

// class for Queue
template<class T>
class Queue
{
private:
    int size;
    int front;
    int rear;
    T *Q;

public:
    Queue() {size = 10;front = rear = -1;Q = new T[size];};
    Queue(int size) {this->size = size;front = rear = -1;Q = new T[this->size];}

    void enqueue(T x);
    int dequeue();

    void display();

    bool isEmpty();
    bool isFull();
};

// implementing the above functions of the class

//  function to perfrom enqueue operation on a queue
template<class T>
void Queue<T> :: enqueue(T x)
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
template <class T>
int Queue<T> :: dequeue()
{
    int x = -1;

    if(isEmpty())
        cout<<"\nQueue is Empty"<<endl;
    else
    {
        front++;

        x = Q[front];
    }

    return x;
}

//  function to perform display operation
template<class T>
void Queue<T> :: display()
{
    int i;

    for(i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";

    cout<<"\n";
}

//  function to check whether queue is empty or not
template<class T>
bool Queue<T> :: isEmpty()
{
    if(front == rear)
        return true;
    return false;
}

//  function to check whether queue is full or not
template<class T>
bool Queue<T> :: isFull()
{
    if(rear == size-1)
        return true;
    return false;
}

// int main()
// {
//     Queue q(5);

//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);

//     q.display();

//     cout<<"Deleted Element : "<<q.dequeue()<<endl;

//     q.display();
// }