// cpp program to perform create, display, find length, insert and delete in Circular Doubly Linked List
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

class CircularDoublyLinkedList 
{
private:
    Node* head;

public:
    CircularDoublyLinkedList(){head = NULL;}   // Default constructor
    CircularDoublyLinkedList(int A[], int n);     // Parameterized constructor - for creating a linked list using an array
    ~CircularDoublyLinkedList();

    Node* getHead(){return head;}   // getter method for head

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

// implementation for the functions of the above class
CircularDoublyLinkedList :: CircularDoublyLinkedList(int A[], int n)    // creating DLL using inserting at last node
{
    int i;
    Node* t, *last;

    //creating first node and connecting global pointer of the class
    t = new Node;

    t->prev = nullptr;
    t->data = A[0];
    t->next = nullptr;

    head = last = t;
    head->next = head->prev = head;

    for(i=1;i<n;i++)
    {
        t = new Node;

        t->data = A[i];
        
        last->next->prev = t;
        t->next = last->next;

        last->next = t;
        t->prev = last;

        last = t;
    }
}

CircularDoublyLinkedList :: ~CircularDoublyLinkedList()
{
    Node* p = head;

    while(p != nullptr)
    {
        p = p->next;

        p->prev = head->prev;

        head->prev->next = p;

        delete head;

        head = p;

        if(p->next == head)
        {
            delete head;

            head = p = nullptr;
        }
    }
}

void CircularDoublyLinkedList :: Display()
{
    Node *p = head;

    do
    {
            cout<<p->data<<"<->";
            
            p = p->next;
    }while(p != head);

    cout<<endl;
}

int CircularDoublyLinkedList :: Length()
{
    int len = 0;

    Node* p = head;

    if(p != nullptr)
    {
        do
        {
            len++;
            p = p->next;
        } while(p != head);
    }
    else
        return 0;
    

    return len;
}

void CircularDoublyLinkedList :: Insert(int index, int x)
{
    int i;

    Node* p = head, *t;

    if(index < 0 || index > Length())
        return ;
    
    t = new Node;

    t->prev = nullptr;
    t->data = x;
    t->next = nullptr;

    // insert before head (or) first node
    if(index == 0)
    {
        t->next = head;
        t->prev = head->prev;
        head->prev = t;
        t->prev->next = t;

        head = t;
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

int CircularDoublyLinkedList :: Delete(int index)
{
    int i, x = -1;

    Node* p = head;

    if(index < 1 || index > Length())   
        return -1;
    
    if(index == 1)
    {
        if(head == nullptr)
            return -1;
        else if(head->next == head)
        {
            x = head->data;

            delete head;

            head = nullptr;
        }
        else
        {
            p = p->next;

            p->prev = head->prev;
            head->prev->next = p;

            x = head->data;

            delete head;

            head = p;
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

    CircularDoublyLinkedList cdll(A, sizeof(A)/sizeof(A[0]));

    cdll.Delete(1);

    cdll.Display();

    cout<<"Length : "<<cdll.Length()<<endl;
}