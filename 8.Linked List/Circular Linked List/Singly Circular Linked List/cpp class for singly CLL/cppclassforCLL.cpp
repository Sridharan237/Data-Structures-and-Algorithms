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
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
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

int CircularLinkedList :: Length()
{
    int len = 0;

    Node *p = head;

    while(p->next != head)
    {
        len++;
        p = p->next;
    }

    return len;
}

void CircularLinkedList :: Insert(int index, int x)
{
    int i;

    Node *p = head;

    if(index < 0 || index > Length())
        return ;

    Node *t;

    t = new Node;

    t->data = x;
    t->next = NULL;

    if(index == 0)
    {
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
                p = p->next;

            t->next = head;
            p->next = t;
            head = t;
        }
    }
    else 
    {
        for(i=0;i<index-1;i++)
            p = p->next;
        
        t->next = p->next;
        
        p->next = t;
    }
}

int CircularLinkedList :: Delete(int index)
{
    int i, x = -1; // x - deleted element 

    Node *p, *q;
    p = head, q = NULL;

    if(index < 1 || index > Length())
        return -1;

    if(index == 1)
    {
        x = head->data;

        while(p->next == head)
            p = p->next;

        if(p == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            p = p->next;
        
        q = p->next;
        p->next = q->next;

        x = q->data;

        delete q;
    }

    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));

    cl.Insert(0, 10);

    cl.Display();
}