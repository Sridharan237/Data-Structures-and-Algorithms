// cpp program to implement Radix sort
#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// function to find the maximum element in an array
int findMax(int A[], int n)
{
    int max = A[0];

    for(int i=1;i<n;i++)
    {
        if(A[i] > max)
            max = A[i];
    }

    return max;
}

// function to perform insertion into bin
void Insert(Node **bin, int x)
{
    Node *p = *bin;

    // creating a new node
    Node *t = new Node;

    // initializing a new node
    t->data = x;
    t->next = nullptr;

    if(*bin == nullptr)
        *bin = t;
    else
    {
        while(p->next!=nullptr)
            p = p->next;

        p->next = t;
    }
}

// function to perform deletion from bin
int Delete(Node **bin)
{
    Node *p, *q;    // q - tail pointer

    p = *bin;

    int x;

    x = p->data;

    if(p->next == nullptr)
    {
        delete p;

        *bin = nullptr;
    }
    else
    {
        q = p;

        p = p->next;

        *bin = p;

        delete q;
    }

    return x;
}

// function to perform Radix sort
void radixSort(int A[], int n)
{
    int i, j, max, product;

    Node **Bins;

    max = findMax(A, n);

    Bins = new Node*[10];   // size = 10 -> here, A - contains integers (decimal numbers) -> 0 to 9 - total 10 numbers - base 10

    // initializing all the elements in Bins as NULL
    for(i=0;i<10;i++)
        Bins[i] = nullptr;

    product = 1;

    while(max >= product)
    {
        // inserting elements into Bins (or) dropping elements into cans    - Bins behaves like a queue - FIFO
        for(i=0;i<n;i++)
            Insert(&Bins[(A[i]/product)%10], A[i]);   // insertion at end



        // deleting elements from Bins 
        i = 0, j = 0;

        while(i < 10)
        {
            while(Bins[i]!=nullptr)
            {
                A[j++] = Delete(&Bins[i]);
            }

            i++;
        }



        product = product * 10;
    }
}

int main()
{
    int A[] = {10, 5, 3, 2, 9}, n = 5;

    radixSort(A, n);

    for(int i=0;i<n;i++)    // for displaying the array elements
        cout<<A[i]<<" ";
}