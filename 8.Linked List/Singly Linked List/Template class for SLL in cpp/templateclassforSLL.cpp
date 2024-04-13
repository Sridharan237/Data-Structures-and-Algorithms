// c++ class for linked list
#include<iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template <class T>
class LinkedList
{
private:
    Node<T>* first;
public:
    LinkedList() {first = NULL;}    // Default constructor
    LinkedList(T A[], int n);     // Parameterized constructor - for creating a linked list using an array
    ~LinkedList();

    void Display();
    void Insert(int index, T x);
    T Delete(int index);
    int Length();
};

// Implementation for the above function declarations inside the LinkedList class

// Parameterized constructor - for creating a linked list using an array
template <class T>
LinkedList<T> :: LinkedList(T A[], int n)
{
    Node<T> *t, *last;

    int i;

    first = new Node<T>;       //first (or) head node

    first->data = A[0];                     
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)       //create and append to the previous node and make point the last pointer to the created node
    {
        t = new Node<T>;

        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

// Destructor to delete the whole linked list iteratively
template <class T>
LinkedList<T> :: ~LinkedList()
{
    Node<T> *p = first;

    while(first != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

template <class T>
void LinkedList<T> :: Display()
{
    Node<T>* p = first;

    while(p != NULL)
    {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL";
}

// function to insert a node at given position
template <class T>
void LinkedList<T> :: Insert(int position, T x)   // x - element (or) data to be inserted
{
    Node<T> *p = first;

    int i;

    Node<T> *t = new Node<T>;

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
template <class T>
T LinkedList<T> :: Delete(int position)
{
    Node<T> *p = first;
    Node<T>* q = NULL;  //tailing (or) following pointer

    T x = -1, i;

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
template <class T>
int LinkedList<T> :: Length()
{
    Node<T> *p = first;

    int count = 0;

    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

int main()
{
    char A[] = {'a', 'b', 'c', 'd', 'e'};

    // Object creation
    LinkedList<char> l(A, 5);
    
    cout<<l.Length()<<endl;

    l.Insert(0, 'f');

    l.Display();
    
    return 0;
}