// cpp program to create and insert and delete elements in a BST (Binary Search Tree)
#include<iostream>
#include<stack>
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

// class for binary search tree
class BinarySearchTree
{
private:
    Node* root;

public:
    BinarySearchTree() {root = nullptr;}

    Node* getRoot() {return root;}

    void IterativeInsert(int key);

    Node* RecursiveInsert(int key) {RecursiveInsert(root,key);}
    Node* RecursiveInsert(Node* p, int key);

    Node* RecursiveDelete(Node* p, int key);

    Node* InorderPredecessor(Node* p);
    Node* InorderSuccessor(Node* p);

    bool search(int key);

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

    int height() {return level(root)-1;}
    int height(Node* p) {return level(p)-1;}

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

// function to insert into a BST(Binary Search Tree) iteratively
void BinarySearchTree :: IterativeInsert(int key)
{
    Node* p = root, *q = nullptr, *t = nullptr;     // q - tail pointer, t - temporary pointer

    if(root == nullptr)
    {
        root = new Node;

        root->data = key;

        root->lchild = root->rchild = nullptr;
        
        return ;
    }
    else
    {   // for searching the correct position
        while(p != nullptr)
        {
            q = p;

            if(key == p->data)  // key already exit
                return ;
            else if(key < p->data)
                p = p->lchild;
            else
                p = p->rchild;
        }

        t = new Node;

        t->data = key;

        t->lchild = t->rchild = nullptr;

        if(key < q->data)   
            q->lchild = t;
        else 
            q->rchild = t;
    }
}

// function to perform insertion operation in a BST recursively
Node* BinarySearchTree :: RecursiveInsert(Node* p, int key)
{
    Node* t = nullptr;

    if(root == nullptr)
    {
        t = new Node;

        t->data = key;

        t->lchild = t->rchild = nullptr;

        root = t;

        return root;
    }
    else if(p == nullptr)
    {
        t = new Node;

        t->data = key;

        t->lchild = t->rchild = nullptr;

        return t;
    }
    else
    {
        if(key == p->data)
            return nullptr;
        else if(key < p->data)
            p->lchild = RecursiveInsert(p->lchild, key);
        else
            p->rchild = RecursiveInsert(p->rchild, key);
    }

    return p;
}

// function to perform delete operation in a BST recursively
Node* BinarySearchTree :: RecursiveDelete(Node* p, int key)
{
    Node *q = nullptr;

    if(p == nullptr)    // key - not found
        return nullptr;
    
    if(p->lchild == nullptr && p->rchild == nullptr)    // key = leaf node
    {
        if(p == root)   // key = `root node` as well as `leaf node`
            root = nullptr;
        
        delete p;

        return nullptr;
    }   

    // key = nonleaf node
    if(key < p->data)
        p->lchild = RecursiveDelete(p->lchild, key);
    else if(key > p->data)
        p->rchild = RecursiveDelete(p->rchild, key);
    else    // perform Inorder predecessor, Inorder successor to delete the key
    {
        if(height(p->lchild) > height(p->rchild))   // height of left subtree > height of right subtree - find => Inorder predecessor
        {
            q = InorderPredecessor(p->lchild);

            p->data = q->data;  // swapping the data of Inorder predecessor with the current node

            p->lchild = RecursiveDelete(p->lchild, q->data);    // deleting the Inorder predecessor on left subtree of p - pointing node
        }
        else    // height of left subtree < height of right subtree - find => Inorder successor
        {
            q = InorderSuccessor(p->rchild);

            p->data = q->data;  // swapping the data of Inorder successor with the current node

            p->rchild = RecursiveDelete(p->rchild, q->data);   // deleting the Inorder successor on right subtree of p - pointing node 
        }
    }
    return p;
}

// function to find Inorder predecessor iteratively 
Node* BinarySearchTree :: InorderPredecessor(Node* p)
{
    while(p->rchild != nullptr) // right most element in left subtree
        p = p->rchild;

    return p;
}


// function to find Inorder successor iteratively
Node* BinarySearchTree :: InorderSuccessor(Node* p)
{
    while(p->lchild != nullptr) // left most element in right subtree
        p = p->lchild;

    return p;
}

// function to perform search operation in a BST iteratively
bool BinarySearchTree :: search(int key)
{
    Node* p = root;

    while(p != nullptr)
    {
        if(key == p->data)
            return true;
        else if(key < p->data)
            p = p->lchild;
        else 
            p = p->rchild;
    }

    return false;
}

// function to perform preorder traversal
void BinarySearchTree :: preorder(Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";

        preorder(p->lchild);
        preorder(p->rchild);
    }   
}

// function to perform inorder traversal
void BinarySearchTree :: inorder(Node* p)
{
    if(p)
    {
        inorder(p->lchild);

        cout<<p->data<<" ";
        
        inorder(p->rchild);
    }   
}

// function to perform postorder traversal
void BinarySearchTree :: postorder(Node* p)
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
void BinarySearchTree :: IterativePreorder()
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
void BinarySearchTree :: IterativeInorder()
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
void BinarySearchTree :: IterativePostorder()
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
void BinarySearchTree :: Levelorder()
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
int BinarySearchTree :: level(Node* p)
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
int BinarySearchTree :: countNodes(Node* p)
{
    if(p)
        return countNodes(p->lchild) + countNodes(p->rchild) + 1;
    return 0;
}

// function to find the total sum of values in all the nodes in a binary tree recursively
int BinarySearchTree :: sum(Node* p)
{
    if(p)
        return sum(p->lchild) + sum(p->rchild) + p->data;
    return 0;
}

// function to find the count the leaf nodes in a binary tree recursively - Total nodes with degree 0 (or) external nodes
int BinarySearchTree :: countLeaf(Node* p)
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
int BinarySearchTree :: countNonLeaf(Node* p)
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
int BinarySearchTree :: internalNodes(Node* p)
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
int BinarySearchTree :: NodesWithDegree1(Node* p)
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
    int target = 0;

    BinarySearchTree bst;

    bst.RecursiveInsert(9);
    bst.RecursiveInsert(15);
    bst.RecursiveInsert(5);
    bst.RecursiveInsert(20);
    bst.RecursiveInsert(16);
    bst.RecursiveInsert(8);
    bst.RecursiveInsert(12);
    bst.RecursiveInsert(3);
    bst.RecursiveInsert(6);

    cout<<"Iterative Preorder : ";

    bst.IterativePreorder();

    cout<<"\n";

    cout<<"Iterative Inorder : ";

    bst.IterativeInorder();

    cout<<"\n";

    cout<<"Iterative Postorder : ";

    bst.IterativePostorder();

    cout<<"\n";

    target = 16;

    if(bst.search(target))
        cout<<"Element "<<target<<" Found"<<endl;
    else
        cout<<"Element "<<target<<" Not Found"<<endl;

    bst.RecursiveDelete(bst.getRoot(), 9);

    bst.inorder();

    cout<<endl;
    
    return 0;
}