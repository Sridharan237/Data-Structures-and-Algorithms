// cpp class for a singly circular linked list 
#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;
public:
    CircularLinkedList(int A[], int n);
    ~CircularLinkedList();
    Node* getHead() {return head;}
    void Display();
    void RecursiveDisplay(Node *p);
};

// implementing the functions of the above class CircularLinkedList
CircularLinkedList :: CircularLinkedList(int A[], int n)
{
    Node *t, *tail;
    int i;

    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;

    for(i=1;i<n;i++)
    {
        t = new Node;
        
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

CircularLinkedList :: ~CircularLinkedList()
{
    Node *p = head;

    while(p->next != head)
        p = p->next;
    
    while(p != head)
    {
        p->next = head->next;

        delete head;

        head = p->next;
    }

    if(p == head)
    {
        delete head;
        head = nullptr;
    }
}

void CircularLinkedList :: Display()
{
    Node *p = head;

    do
    {
        cout<<p->data<<"->";
        p = p->next;
    }while(p!=head);

    cout<<endl;
}

void CircularLinkedList :: RecursiveDisplay(Node *p)
{
    static int flag = 0;

    if(p != head || flag == 0)
    {
        flag = 1;
        cout<<p->data<<"->"<<flush;
        RecursiveDisplay(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));

    cl.Display();
}