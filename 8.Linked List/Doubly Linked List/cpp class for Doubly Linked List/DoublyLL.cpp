// cpp program to perform create, display, find length, insert and delete in Linear Doubly Linked List
#include<iostream>

using namespace std;

// Node structure in a class for DLL
class Node
{
    public:
        Node* prev;
        int data;
        Node* next;
};

class DoublyLinkedList 
{
private:
    Node* first;

public:
    DoublyLinkedList(){first = NULL;}   // Default constructor
    DoublyLinkedList(int A[], int n);     // Parameterized constructor - for creating a linked list using an array
    ~DoublyLinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

// implementation for the functions of the above class
DoublyLinkedList :: DoublyLinkedList(int A[], int n)    // creating DLL using inserting at last node
{
    int i;
    Node* t, *last;

    //creating first node and connecting global pointer of the class
    t = new Node;

    t->prev = nullptr;
    t->data = A[0];
    t->next = nullptr;

    first = last = t;

    for(i=1;i<n;i++)
    {
        t = new Node;

        last->next = t;
        t->prev = last;
        t->data = A[i];
        t->next = nullptr;
        last = t;
    }
}

DoublyLinkedList :: ~DoublyLinkedList()
{
    Node* p = first;

    while(p != nullptr)
    {
        p = p->next;

        delete first;

        first = p;
    }
}

void DoublyLinkedList :: Display()
{
    Node *p = first;

    while(p != nullptr)
    {
        if(p->next != nullptr)
            cout<<p->data<<"<->";
        else
            cout<<p->data<<"->NULL"<<endl;
        
        p = p->next;
    }
}

int DoublyLinkedList :: Length()
{
    int len = 0;

    Node* p = first;

    while(p != nullptr)
    {
        len++;
        p = p->next;
    }

    return len;
}

void DoublyLinkedList :: Insert(int index, int x)
{
    int i;

    Node* p = first, *t;

    if(index < 0 || index > Length())
        return ;
    
    t = new Node;

    t->prev = nullptr;
    t->data = x;
    t->next = nullptr;

    // insert before head (or) first node
    if(index == 0)
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p = p->next;    

        t->prev = p;
        t->next = p->next;

        p->next->prev = t;
        p->next = t;
    }
}

int DoublyLinkedList :: Delete(int index)
{
    int i, x = -1;

    Node* p = first;

    if(index < 1 || index > Length())   
        return -1;
    
    if(index == 1)
    {
        if(first == nullptr)
            return -1;
        else if(first->next == nullptr)
        {
            x = first->data;

            delete first;

            first = nullptr;
        }
        else
        {
            p = p->next;
            p->prev = nullptr;

            x = first->data;

            delete first;

            first = p;
        }
    }
    else
    {
        for(i=0;i<index-1 && p;i++)
            p = p->next;

        p->prev->next = p->next;
        p->next->prev = p->prev;

        x = p->data;

        delete p;
    }

    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    DoublyLinkedList dll(A, sizeof(A)/sizeof(A[0]));

    dll.Delete(3);

    dll.Display();

    cout<<"Length : "<<dll.Length()<<endl;
}