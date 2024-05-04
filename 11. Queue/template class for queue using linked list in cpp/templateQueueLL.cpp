// cpp program to write a template class for queue using linked list and perfrom various operations
#include<iostream>
#include<queue>

using namespace std;

// class for Node
template <class T> 
class Node
{
public:
    T data;
    Node<T>* next;
};

// class for Queue

template <class T>
class Queue
{
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() {front = rear = nullptr;}

    void enqueue(T x);
    T dequeue();

    void display();

    bool isEmpty();
};

// implementing the above functions of the class

//  function to perfrom enqueue operation on a 
template <class T>
void Queue<T> :: enqueue(T x)
{
    Node<T>* t = new Node<T>;

    if(t == nullptr)    // Heap is full
        cout<<"\nQueue is Full"<<endl;
    else
    {
        t->data = x;
        
        t->next = nullptr;

        if(isEmpty())
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;

            rear = t;
        }
    }
}

//  function to perform dequeue operation on a queue
template <class T> 
T Queue<T> :: dequeue()
{
    T x = 0;

    Node<T>* p = front;

    if(isEmpty())
        cout<<"\nQueue is empty"<<endl;
    else
    {
        x = front->data;

        front = front->next;

        delete p;
    }

    return x;
}

//  function to perform display operation
template <class T> 
void Queue<T> :: display()
{
    Node<T>* p = front;

    while(p != nullptr)
    {
        cout<<p->data<<" ";

        p = p->next;
    }

    cout<<"\n";
}

//  function to check whether queue is empty or not
template <class T> 
bool Queue<T> :: isEmpty()
{
    if(front == nullptr && rear == nullptr)
        return true;
    return false;
}

int main()
{
    Queue<char> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout<<"Deleted Element : "<<q.dequeue()<<endl;

    q.display();
}