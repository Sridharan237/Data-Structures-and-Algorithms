// c program to create, display a stack using Linked list and perform push, pop, stackTop, isEmpty, isFull operations on it
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

int isEmpty()
{
    return (top==NULL)?1:0;
}

int isFull()
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));

    int res = (t==NULL)?1:0;

    free(t);

    return res;
}

void push(int x)
{
    struct Node* t;

    if(!isFull())
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = x;
        t->next = top;
        
        top = t;
    }
    else
        printf("stack is full\n");
}

int pop()
{
    int x = -1;
    struct Node* p;

    if(!isEmpty())
    {
        p = top;

        x = top->data;

        top = top->next;

        free(p);
    }
    else
        printf("stack is empty\n");
    
    return x;
}

void display()
{
    struct Node *p = top;

    while(p != NULL)
    {
        printf("%d ", p->data);

        p = p->next;
    }
}

int peek(int pos)
{
    int x = -1, i;
    struct Node *p;

    if(!isEmpty())
    {
        p = top;

        for(i=0;p!=NULL&&i<pos-1;i++)
            p = p->next;

        x = p->data;
    }
    else
        printf("stack is empty\n");

    return x;
}

int stackTop()
{
    if(!isEmpty())
        return top->data;
    return -1;
}

// int main()
// {
//     push(10);
//     push(20);
//     push(30); 
//     push(40);  

//     printf("\nPopped element : %d\n", pop());

//     printf("stack top : %d\n", stackTop());

//     printf("peek at 2 : %d\n", peek(2));
    
//     display();
// }