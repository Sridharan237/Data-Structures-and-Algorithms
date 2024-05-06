// c program to create a binary tree and perform various traversals
#include<stdio.h>
#include<stdlib.h>
#include "circularqueue.h"  // custom header file for a circular queue to store address of type - (Node*)

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

// function to create a binary tree using a circular queue
void create()
{
    int x;

    struct CircularQueue cq;

    // initializing Circular queue

    cq.front = cq.rear = 0;

    cq.size = 30;

    cq.Q = (struct Node **)malloc(cq.size*sizeof(struct Node*));

    struct Node *p, *t;

    printf("Enter the root value : ");
    scanf("%d", &x);

    root = (struct Node*)malloc(sizeof(struct Node));

    root->data = x;

    root->lchild = root->rchild = NULL;

    enqueue(&cq, root);

    while(!isEmpty(cq))
    {
        p = dequeue(&cq);

        // left child
        printf("Enter the left child of %d : ", p->data);
        scanf("%d", &x);    // enter -1 if left child doesn't exist

        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));

            t->data = x;

            t->lchild = t->rchild = NULL;

            p->lchild = t;

            enqueue(&cq, t);
        }

        //  right child
        printf("Enter the right child of %d : ", p->data);
        scanf("%d", &x);    // enter -1 if right child doesn't exist

        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));

            t->data = x;

            t->lchild = t->rchild = NULL;

            p->rchild = t;

            enqueue(&cq, t);
        }
    }
}

// various traversals

// function to perform preorder traversal
void preorder(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);

        preorder(p->lchild);
        preorder(p->rchild);
    }   
}

// function to perform inorder traversal
void inorder(struct Node *p)
{
    if(p != NULL)
    {
        preorder(p->lchild);

        printf("%d ", p->data);
        
        preorder(p->rchild);
    }   
}

// function to perform postorder traversal
void postorder(struct Node *p)
{
    if(p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);

        printf("%d ", p->data);
    }   
}

//  function to perform levelorder traversal
void levelorder(struct Node* root)
{
    struct Node* p = NULL;

    struct CircularQueue cq;

    // initializing Circular queue

    cq.front = cq.rear = 0;

    cq.size = 30;

    cq.Q = (struct Node **)malloc(cq.size*sizeof(struct Node*));

    enqueue(&cq, root); 

    while(!isEmpty(cq))
    {
        p = dequeue(&cq);

        printf("%d ", p->data);

        if(p && p->lchild)
            enqueue(&cq, p->lchild);
        
        if(p && p->rchild)
            enqueue(&cq, p->rchild);
    }
}

int main()
{
    create();

    printf("Preorder : \n");
    preorder(root);

    printf("\n");

    printf("Inorder : \n");
    inorder(root);

    printf("\n");

    printf("Postorder : \n");
    postorder(root);

    printf("\n");

    printf("Levelorder : \n");
    levelorder(root);
}