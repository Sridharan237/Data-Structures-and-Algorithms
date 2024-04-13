// c++ class for linked list
#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *first;
    LinkedList() {first = NULL;}    // Default constructor
    LinkedList(int A[], int n);     // Parameterized constructor - for creating a linked list using an array
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

// Implementation for the above function declarations inside the LinkedList class

// Parameterized constructor - for creating a linked list using an array
LinkedList :: LinkedList(int A[], int n)
{
    Node *t, *last;

    int i;

    first = new Node;       //first (or) head node

    first->data = A[0];                     
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)       //create and append to the previous node and make point the last pointer to the created node
    {
        t = new Node;

        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

// Destructor to delete the whole linked list iteratively
LinkedList :: ~LinkedList()
{
    Node *p = first;

    while(first != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList :: Display()
{
    Node *p = first;

    while(p != NULL)
    {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL";
}

// function to insert a node at given position
void LinkedList :: Insert(int position, int x)   // x - element (or) data to be inserted
{
    Node *p = first;

    int i;

    Node *t = new Node;

    if(position < 0 && position > Length())
        return ;
    
    //node creation and data setting
    t->data = x;

    if(position == 0)  //case 1 : inserting before first node
    {
        t->next = first;
        first = t;
    }
    else if(position > 0)  // case 2: inserting at a given position
    {
        for(i=0;i<position-1 && p;i++)     //traversing the linked list and checking if p is NULL (or) not
            p = p->next;
        
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

// function to delete a node at a given index in a linked list
int LinkedList :: Delete(int position)
{
    Node *p = first;
    Node* q = NULL;  //tailing (or) following pointer

    int x = -1, i;

    if(position < 1 || position > Length())
        return x;

    if(position == 1)
    {
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        for(i=0;i<position-1;i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

// function to count the no. of nodes in a linked list Iteratively
int LinkedList :: Length()
{
    Node *p = first;

    int count = 0;

    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

// int main()
// {
//     int A[] = {1, 2, 3, 4, 5};

//     // Object creation
//     LinkedList l(A, 5);
    
//     cout<<l.Length()<<endl;

//     l.Display();
    
//     return 0;
// }