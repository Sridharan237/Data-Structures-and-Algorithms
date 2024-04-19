// cpp program to create, display a stack using Linked list and perform push, pop, stackTop, isEmpty, isFull operations on it
#include<iostream>

using namespace std;

// class for Node
class Node
{
public:
    int data;
    Node *next;
};

// class for Stack
class Stack
{
private:
    Node *top;

public:
    Stack() {top = nullptr;}

    void push(int x);
    int pop();

    void display();

    int stackTop();
    int peek(int position);

    bool isEmpty();
    bool isFull();
};

void Stack :: push(int x)
{
    Node *t;

    if(!isFull())
    {
        t = new Node;

        t->data = x;
        t->next = top;

        top = t;
    }
    else
        cout<<"Stack is full"<<endl;
}

int Stack :: pop()
{
    int x = -1;

    Node *p;

    if(!isEmpty())
    {
        x = top->data;

        p = top;

        top = top->next;

        delete p;
    }
    else
        cout<<"stack is empty"<<endl;

    return x;
}

void Stack :: display()
{
    Node *p = top;

    while(p != nullptr)
    {
        cout<<p->data<<" ";

        p = p->next;
    }

    cout<<"\n";
}

int Stack :: stackTop()
{
    return (!isEmpty())?top->data:-1;
}

int Stack :: peek(int position)
{
    int x = -1, i;

    Node *p;

    if(!isEmpty())
    {
        p = top;

        for(i=0;p != nullptr && i<position-1;i++)
            p = p->next;
        
        if(p != nullptr)
            x = p->data;
    }
    else
        cout<<"stack is empty"<<endl;

    return x;
    
}

bool Stack :: isEmpty()
{
    return (top==nullptr)?1:0;
}

bool Stack :: isFull()
{
    Node *t = new Node;

    bool result;

    result = (t==nullptr)?1:0;

    delete t;

    return result;
}

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();
    
    cout<<"Popped element : "<<s.pop()<<endl;

    cout<<"stack top : "<<s.stackTop()<<endl;

    cout<<"peek at 2 : "<<s.peek(2)<<endl;
}