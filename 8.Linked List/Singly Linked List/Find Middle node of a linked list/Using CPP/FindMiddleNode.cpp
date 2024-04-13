// cpp program to find the middle node of a linked list using 3 methods
// methods:
// 1. Length of linked list divided by 2
// 2. Two pointers (or) sliding pointers (or) fast, slow pointers method
// 3. Using stack

#include<iostream>
#include "linkedlist.h" // Using singly linked list that I have coded in cpp and using it as a header file for finding middle node and main() method should not be there in linkedlist.h
#include<cmath>
#include<stack>

using namespace std;

// function for finding the middle node of a linked list using method1
void FindMiddleNode1(LinkedList l)
{
    Node *p = l.first;

    int i, length = l.Length();

    int middleNode = (int)(floor(length/2));

    for(i=0;i<middleNode-1;i++)
        p = p->next;

    cout<<"\nMiddle Node\'s data (Method-I) : "<<p->data<<endl;
}

// function for finding the middle node of a linked list using method2
void FindMiddleNode2(LinkedList l)
{
    Node *p, *q;

    p = q = l.first;
    
    while(q != NULL)
    {
        q = q->next;

        if(q) q = q->next;

        if(q) p = p->next;
    }

    cout<<"\nMiddle Node\'s data (Method-II) : "<<p->data<<endl;
}

// function for finding the middle node of a linked list using method3
void FindMiddleNode3(LinkedList l)
{
    Node *p = l.first;

    stack<Node*> s;

    while(p != nullptr)
    {
        s.push(p);
        p = p->next;
    }

    int length = s.size();

    int popLength = (int)(floor(length/2.0));

    while(popLength)
    {
        s.pop();
        popLength--;
    }

    cout<<"\nMiddle Node\'s data (Method-III) : "<<s.top()->data<<endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinkedList l(A, 10);

    l.Display();
    
    FindMiddleNode3(l);
}