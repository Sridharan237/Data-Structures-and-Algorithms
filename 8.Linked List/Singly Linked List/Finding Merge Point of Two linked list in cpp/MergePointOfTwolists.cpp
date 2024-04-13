// cpp program to find the merge point of two Linked List in cpp
//method:
// 1.two stacks method

#include<iostream>
#include<stack>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

Node *first = NULL, *flast = NULL, *second = NULL;

// function to create a linked list called first
void create1(int A[], int n)
{
    int i;

    Node *t;

    t = new Node;
    
    t->data = A[0];
    t->next = NULL;

    first = flast = t;

    for(i=1;i<n;i++)
    {
        t = new Node;
        
        t->data = A[i];
        t->next = NULL;
        
        flast->next = t;
        flast = t;
    }
}

// function to create a linked list called second
void create2(int A[], int n)
{
    int i;

    Node *t, *last = NULL;

    t = new Node;
    
    t->data = A[0];
    t->next = NULL;

    second = last = t;

    for(i=1;i<n;i++)
    {
        t = new Node;
        
        t->data = A[i];
        t->next = NULL;
        
        last->next = t;
        last = t;
        
        if(i == 3)
        {
            // connecting linked list1's last node's next to linked list2's last node
            flast ->next = t;
        }
    }
}

// function to display a linked list
void Display(Node *p)
{
    while(p != NULL)
    {
        if(p->next == NULL)
            cout<<p->data<<endl;
        else 
            cout<<p->data<<"->";
        
        p = p->next;
    }
}

// function to find the merge point of two linked list using two stacks method
void mergePoint(Node *p, Node *q)
{
    // r - is the result pointer pointing to the Merging node of two linked list
    Node *r;

    // Create stack1 
    stack<Node*> stack1;

    // Create stack2
    stack<Node*> stack2;

    // push the address of first linked list into stack1
    while(p != NULL)
    {
        stack1.push(p);
        p = p->next;
    }

    // push the address of second linked list into stack2
    while(q != NULL)
    {
        stack2.push(q);
        q = q->next;
    }

    // pop from stack1 and stack2 at same time until they are equal
    while(stack1.top() == stack2.top())
    {
        r = stack1.top();
        stack1.pop();
        stack2.pop();

        if(stack1.empty() || stack2.empty())
            break;
    }

    cout<<"\nMerging Node's data : "<<r->data<<endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {7, 8, 9, 10, 11};

    create1(A, sizeof(A)/sizeof(A[0]));
    create2(B, sizeof(B)/sizeof(B[0]));

    Display(first);
    Display(second);

    mergePoint(first, second);

    return 0;
}