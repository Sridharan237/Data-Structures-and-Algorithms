// cpp program to create a binary tree and perform various traversals in linked representation

#include<iostream>
#include<queue>
#include<stack>

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

    void IterativePreorder();
    void IterativeInorder();
    void IterativePostorder();

    void Levelorder();

    int level() {level(root);}
    int level(Node* p);

    int countNodes() {countNodes(root);}
    int countNodes(Node* p);

    int sum() {sum(root);}
    int sum(Node* p);

    int countLeaf() {countLeaf(root);}
    int countLeaf(Node* p);

    int countNonLeaf() {countNonLeaf(root);}
    int countNonLeaf(Node* p);

    int internalNodes() {internalNodes(root);}
    int internalNodes(Node* p);

    int NodesWithDegree1() {NodesWithDegree1(root);}
    int NodesWithDegree1(Node* p);
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

// Iterative traversals using stack
//  function to perform preorder iteratively    
void BinaryTree :: IterativePreorder()
{
    Node* p = root;

    stack<Node*> s;

    while(p !=  nullptr || !s.empty())
    {
        if(p != nullptr)
        {
            printf("%d ", p->data);

            s.push(p);

            p = p->lchild;
        }
        else
        {
            p = s.top();

            s.pop();

            p = p->rchild;
        }
    }
}

//  function to perform inorder iteratively
void BinaryTree :: IterativeInorder()
{
    Node* p = root;

    stack<Node*> s;

    while(p !=  nullptr || !s.empty())
    {
        if(p != nullptr)
        {
            s.push(p);

            p = p->lchild;
        }
        else
        {
            p = s.top();

            s.pop();

            printf("%d ", p->data);

            p = p->rchild;
        }
    }
}

//  function to perform postorder iteratively
void BinaryTree :: IterativePostorder()
{
    Node* p = root;

    long int temp = 0;

    stack<long int> s;

    while(p !=  nullptr || !s.empty())
    {
        if(p != nullptr)
        {
            s.push(long(p));

            p = p->lchild;
        }
        else
        {
            temp = s.top();

            s.pop();

            if(temp > 0)    // temp - +ve -> move to rchild
            {
                s.push(-temp);      // push address as long int into stack 2 times

                p = ((Node*)temp)->rchild;
            }
            else            // temp - -ve -> print data
            {
                printf("%d ", ((Node*)(-temp))->data);

                p = nullptr;
            }
        }
    }
}

// function to perform level order traversal
void BinaryTree :: Levelorder()
{
    Node* p = root;

    queue<Node*> q;

    cout<<root->data<<" ";

    q.push(root);

    while(!q.empty())
    {
        p = q.front();  

        q.pop();    // performing dequeue operation in queue

        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";

            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";

            q.push(p->rchild);
        }
    }
}

// function to find the number of levels of a binary tree recursively
int BinaryTree :: level(Node* p)
{
    int x, y;

    x = y = 0;

    if(p)
    {
        x = level(p->lchild);
        y = level(p->rchild);

        if(x > y)
            return x + 1;
        else
            return y + 1;
    }

    return 0;
}

// function to find the count of total number of nodes in a binary tree recursively
int BinaryTree :: countNodes(Node* p)
{
    if(p)
        return countNodes(p->lchild) + countNodes(p->rchild) + 1;
    return 0;
}

// function to find the total sum of values in all the nodes in a binary tree recursively
int BinaryTree :: sum(Node* p)
{
    if(p)
        return sum(p->lchild) + sum(p->rchild) + p->data;
    return 0;
}

// function to find the count the leaf nodes in a binary tree recursively - Total nodes with degree 0 (or) external nodes
int BinaryTree :: countLeaf(Node* p)
{
    if(p)
    {
        if(!p->lchild && !p->rchild)
            return countLeaf(p->lchild) + countLeaf(p->rchild) + 1;
        return countLeaf(p->lchild) + countLeaf(p->rchild);
    }
    return 0;
}

// function to find the count the leaf nodes in a binary tree recursively - Total nodes with degree 2
int BinaryTree :: countNonLeaf(Node* p)
{
    if(p)
    {
        if(p->lchild && p->rchild)
            return countNonLeaf(p->lchild) + countNonLeaf(p->rchild) + 1;
        return countNonLeaf(p->lchild) + countNonLeaf(p->rchild);
    }
    return 0;
}

// function to find the count the internal nodes in a binary tree recursively - Total nodes with degree 2 or 1
int BinaryTree :: internalNodes(Node* p)
{
    if(p)
    {
        if(p->lchild || p->rchild)
            return internalNodes(p->lchild) + internalNodes(p->rchild) + 1;
        return internalNodes(p->lchild) + internalNodes(p->rchild);
    }
    return 0;
}

// function to find the count the total nodes with degree 1 recursively
int BinaryTree :: NodesWithDegree1(Node* p)
{
    if(p)
    {   // p->lchild != nullptr ^ p->rchild != nullptr = ((p->lchild != nullptr)&&(p->rchild == nullptr)) || ((p->lchild == nullptr)&&(p->rchild != nullptr))
        if(p->lchild != nullptr ^ p->rchild != nullptr)
            return NodesWithDegree1(p->lchild) + NodesWithDegree1(p->rchild) + 1;
        return NodesWithDegree1(p->lchild) + NodesWithDegree1(p->rchild);
    }
    return 0;
}

int main()
{
    int height, level;

    BinaryTree bt;

    bt.createBinaryTree();

    // cout<<"Preorder : "<<endl;
    // bt.preorder();

    // cout<<endl;

    // cout<<"Inorder : "<<endl;
    // bt.inorder();

    // cout<<endl;

    // cout<<"Postorder : "<<endl;
    // bt.postorder();

    // cout<<"Iterative Preorder : "<<endl;
    // bt.IterativePreorder();

    // cout<<endl;

    // cout<<"Iterative Inorder : "<<endl;
    // bt.IterativeInorder();

    // cout<<endl;

    // cout<<"Iterative Postorder : "<<endl;
    // bt.IterativePostorder();

    // cout<<endl;

    // cout<<"Levelorder Traversal : "<<endl;
    // bt.Levelorder();

    // cout<<endl;

    // level = bt.level();

    // cout<<"Total No. of Levels : "<<level<<endl;

    // height = level - 1;

    // cout<<"Height of binary tree : "<<height<<endl;

    // cout<<"Total No. of Nodes : "<<bt.countNodes()<<endl;

    // cout<<"Total sum of all values in nodes : "<<bt.sum()<<endl;

    // cout<<"Total No. of leaf nodes : "<<bt.countLeaf()<<endl;

    // cout<<"Total No. of Non-leaf nodes : "<<bt.countNonLeaf()<<endl;

    cout<<"Total no. of internal nodes : "<<bt.internalNodes()<<endl;

    cout<<"Total no. of nodes with degree 1 : "<<bt.NodesWithDegree1()<<endl;

    return 0;
}