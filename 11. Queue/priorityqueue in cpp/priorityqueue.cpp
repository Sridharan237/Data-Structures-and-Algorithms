// cpp program to create and perform enqueue and dequeue operations on priority queue
// Two methods of implementing priority queue
// 1.set of limited priorities
// 2.element priority (unlimited priority)

// Here, we will implement using set of limited priorities

#include<iostream>
#include "queuearraytemplateclasscpp.h"

class PriorityQueue
{
private:
    int priority;
    Queue<char> *q;

public:
    PriorityQueue() {this->priority = 3; q = new Queue<char>[this->priority+1];};
    PriorityQueue(int priority) {this->priority = priority;q = new Queue<char>[this->priority+1];}

    void enqueue(char x, int priority);
    char dequeue();
};

// implementation of the above functions of the class
void PriorityQueue :: enqueue(char x, int priority)
{
    q[priority].enqueue(x);
}

char PriorityQueue :: dequeue()
{
    char x = '\0', i = 1;

    while(q[i].isEmpty())
    {
        i++;
    }

    if(!q[i].isEmpty())
        x = q[i].dequeue();

    return x;
}

int main()
{
    PriorityQueue pq;

    pq.enqueue('A', 1);
    pq.enqueue('B', 2);
    pq.enqueue('C', 3);
    pq.enqueue('D', 1);
    pq.enqueue('E', 2);
    pq.enqueue('F', 3);

    cout<<"Deleted Element : "<<pq.dequeue()<<endl;
    cout<<"Deleted Element : "<<pq.dequeue()<<endl;
    cout<<"Deleted Element : "<<pq.dequeue()<<endl;
}