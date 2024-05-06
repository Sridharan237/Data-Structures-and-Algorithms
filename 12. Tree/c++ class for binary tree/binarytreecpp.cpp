// cpp program to create a binary tree and perform various traversals in linked representation

#include<iostream>
#include<queue>

using namespace std;

// class for Node
class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

// class for binary tree
class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree() {root = nullptr;}

    void createBinaryTree();

    // perform function overloading to preorder, inorder, postorder
    void preorder() {preorder(root);}   
    void preorder(Node *p);

    void inorder() {inorder(root);}
    void inorder(Node *p);

    void postorder() {postorder(root);}
    void postorder(Node *p);
};

// implementing the above functions of the class

// function to create a Binary tree using queue
void BinaryTree :: createBinaryTree()
{
    int x;

    // creating an object of queue
    queue<Node*> q;

    Node *p, *t;

    cout<<"Enter the root value : ";
    cin>>x;

    root = new Node;

    root->data = x;

    root->lchild = root->rchild = nullptr;

    q.push(root);

    while(!q.empty())
    {
        p = q.front();

        q.pop();

        // left child
        printf("Enter the left child of %d : ", p->data);
        scanf("%d", &x);    // enter -1 if left child doesn't exist

        if(x != -1)
        {
            t = new Node;

            t->data = x;

            t->lchild = t->rchild = NULL;

            p->lchild = t;

            q.push(t);
        }

        //  right child
        printf("Enter the right child of %d : ", p->data);
        scanf("%d", &x);    // enter -1 if right child doesn't exist

        if(x != -1)
        {
            t = new Node;

            t->data = x;

            t->lchild = t->rchild = NULL;

            p->rchild = t;

            q.push(t);
        }
    }
}

// function to perform preorder traversal
void BinaryTree :: preorder(Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";

        preorder(p->lchild);
        preorder(p->rchild);
    }   
}

// function to perform inorder traversal
void BinaryTree :: inorder(Node* p)
{
    if(p)
    {
        preorder(p->lchild);

        cout<<p->data<<" ";
        
        preorder(p->rchild);
    }   
}

// function to perform postorder traversal
void BinaryTree :: postorder(Node* p)
{
    if(p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);

        cout<<p->data<<" ";
    }   
}

int main()
{
    BinaryTree bt;

    bt.createBinaryTree();

    cout<<"Preorder : "<<endl;
    bt.preorder();

    cout<<endl;

    cout<<"Inorder : "<<endl;
    bt.inorder();

    cout<<endl;

    cout<<"Postorder : "<<endl;
    bt.postorder();

    return 0;
}