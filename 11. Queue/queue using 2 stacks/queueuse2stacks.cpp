// cpp program to implement a queue using 2 stacks
#include<iostream>
#include<stack>

using namespace std;

// class for queue using 2 stacks
class Queue2stacks
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x);
    int dequeue();
};

void Queue2stacks :: enqueue(int x)
{
    s1.push(x);
}

int Queue2stacks :: dequeue()
{
    int x = -1;

    if(s2.empty())
    {
        if(s1.empty())
            cout<<"\nQueue is Empty\n";
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());

                s1.pop();
            }  

            x = s2.top();

            s2.pop();
        }
    }
    else
    {
        x = s2.top();

        s2.pop();
    }

    return x;
}

int main()
{
    Queue2stacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout<<"Deleted Element : "<<q.dequeue()<<endl;
    cout<<"Deleted Element : "<<q.dequeue()<<endl;
    cout<<"Deleted Element : "<<q.dequeue()<<endl;
}