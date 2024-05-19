// cpp program to create and insert and delete elements in an AVL Tree
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
    int level;  // No. of levels below this Node (level of leftsubtree (or) level of rightsubtree - whichever is greater take it)
    Node* rchild;
};

// class for AVL Tree
class AVLTree
{
private:
    Node* root;

public:
    AVLTree() {root = nullptr;}

    Node* getRoot() {return root;}

    Node* RecursiveInsert(int key) {RecursiveInsert(root,key);}
    Node* RecursiveInsert(Node* p, int key);

    // Rotations for Insertion of a node in AVL Tree
    // single rotation
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    //double rotation
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);

    int nodeLevel(Node* p);

    int balanceFactor(Node* p);

    void RecursiveDelete(int key) {RecursiveDelete(root, key);}
    Node* RecursiveDelete(Node* p, int key);

    Node* InorderPredecessor(Node* p);
    Node* InorderSuccessor(Node* p);

    // Rotations for Deletion of a node in AVL Tree
    // Left rotations
    Node* L1Rotation(Node* p) {return LLRotation(p);}
    Node* Lminus1Rotation(Node* p) {return LRRotation(p);}
    Node* L0Rotation(Node* p) {return LLRotation(p);}   // can be LLRotation (or) LRRotation
    // Right rotations
    Node* R1Rotation(Node* p) {return RLRotation(p);}
    Node* Rminus1Rotation(Node* p) {return RRRotation(p);}
    Node* R0Rotation(Node* p) {return RRRotation(p);}   // can be RRRotation (or) RLRotation

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

// function to perform insertion operation in a AVL Tree recursively
Node* AVLTree :: RecursiveInsert(Node* p, int key)
{
    Node* t = nullptr;

    if(root == nullptr)
    {
        t = new Node;

        t->data = key;

        t->lchild = t->rchild = nullptr;

        t->level = 1;   // leafnode => (no. of levels = 1)

        root = t;

        return root;
    }
    else if(p == nullptr)
    {
        t = new Node;

        t->data = key;

        t->lchild = t->rchild = nullptr;

        t->level = 1;   // leafnode => (no. of levels = 1)

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

    p->level = nodeLevel(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RRRotation(p);
    
    return p;
}

// functions to perform rotations in an AVL Tree

// function to perform LLRotation in an AVL Tree
Node* AVLTree :: LLRotation(Node* p)
{
    Node *pl = p->lchild, *plr = pl->rchild;    

    pl->rchild = p;

    p->lchild = plr;

    if(p == root)
        root = pl;

    p->level = nodeLevel(p);

    pl->level = nodeLevel(pl);

    return pl;
}

// function to perform LRRotation in an AVL Tree
Node* AVLTree :: LRRotation(Node* p)
{
    Node *pl = p->lchild, *plr = pl->rchild;    

    pl->rchild = plr->lchild;

    p->lchild = plr->rchild;

    plr->rchild = p;

    plr->lchild = pl;

    if(p == root)
        root = plr;

    plr->level = nodeLevel(plr);

    p->level = nodeLevel(p);

    pl->level = nodeLevel(pl);

    return plr;
}

// function to perform RRRotation in an AVL Tree
Node* AVLTree :: RRRotation(Node* p)
{
    Node *pr = p->rchild, *prl = pr->lchild;    

    p->rchild = prl;

    pr->lchild = p;

    if(p == root)
        root = pr;

    p->level = nodeLevel(p);

    pr->level = nodeLevel(pr);

    return pr;
}

// function to perform RLRotation in an AVL Tree
Node* AVLTree :: RLRotation(Node* p)
{
    Node *pr = p->rchild, *prl = pr->lchild;    

    p->rchild = prl->lchild;

    pr->lchild = prl->rchild;

    prl->lchild = p;

    prl->rchild = pr;

    if(p == root)
        root = prl;

    prl->level = nodeLevel(prl);

    p->level = nodeLevel(p);

    pr->level = nodeLevel(p);

    return prl;
}

// function to find the level of a node
int AVLTree :: nodeLevel(Node* p)
{
    int ll, lr;     // ll - level of leftsubtree, lr - level of rightsubtree

    ll = (p && p->lchild)?p->lchild->level:0;    // ll - level of leftsubtree

    lr = (p && p->rchild)?p->rchild->level:0;    // lr - level of rightsubtree

    return (ll > lr)?ll+1:lr+1;
}

// function to find the balance factor of a node
int AVLTree :: balanceFactor(Node* p)
{
    int ll, lr;     // ll - level of leftsubtree, lr - level of rightsubtree

    ll = (p && p->lchild)?p->lchild->level:0;    // ll - level of leftsubtree

    lr = (p && p->rchild)?p->rchild->level:0;    // lr - level of rightsubtree

    return ll-lr;   // bf = level of leftsubtree - level of rightsubtree
}

// function to perform delete operation in an AVL Tree recursively
Node* AVLTree :: RecursiveDelete(Node* p, int key)
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

    p->level = nodeLevel(p);

    // Rotations fo Deletion
    // Left Rotations
    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return L1Rotation(p);   
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return Lminus1Rotation(p);  // L-1 Rotation
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0)
        return L0Rotation(p);
    //Right Rotations
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return R1Rotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return Rminus1Rotation(p);  // R-1 Rotation
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0)
        return R0Rotation(p);

    return p;
}

// function to find Inorder predecessor iteratively 
Node* AVLTree :: InorderPredecessor(Node* p)
{
    while(p->rchild != nullptr) // right most element in left subtree
        p = p->rchild;

    return p;
}


// function to find Inorder successor iteratively
Node* AVLTree :: InorderSuccessor(Node* p)
{
    while(p->lchild != nullptr) // left most element in right subtree
        p = p->lchild;

    return p;
}

// function to perform search operation in an AVL Tree iteratively
bool AVLTree :: search(int key)
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

// function to perform preorder traversal recursively
void AVLTree :: preorder(Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";

        preorder(p->lchild);
        preorder(p->rchild);
    }   
}

// function to perform inorder traversal recursively
void AVLTree :: inorder(Node* p)
{
    if(p)
    {
        inorder(p->lchild);

        cout<<p->data<<" ";
        
        inorder(p->rchild);
    }   
}

// function to perform postorder traversal recursively
void AVLTree :: postorder(Node* p)
{
    if(p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);

        cout<<p->data<<" ";
    }   
}

// Iterative traversals using stack
// function to perform preorder traversal iteratively    
void AVLTree :: IterativePreorder()
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

//  function to perform inorder traversal iteratively
void AVLTree :: IterativeInorder()
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

//  function to perform postorder traversal iteratively
void AVLTree :: IterativePostorder()
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
void AVLTree :: Levelorder()
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

// function to find the number of levels of an AVL Tree recursively
int AVLTree :: level(Node* p)
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

// function to find the count of total number of nodes in an AVL Tree recursively
int AVLTree :: countNodes(Node* p)
{
    if(p)
        return countNodes(p->lchild) + countNodes(p->rchild) + 1;
    return 0;
}

// function to find the total sum of values in all the nodes in an AVL Tree recursively
int AVLTree :: sum(Node* p)
{
    if(p)
        return sum(p->lchild) + sum(p->rchild) + p->data;
    return 0;
}

// function to find the count the leaf nodes in an AVL Tree recursively - Total nodes with degree 0 (or) external nodes
int AVLTree :: countLeaf(Node* p)
{
    if(p)
    {
        if(!p->lchild && !p->rchild)
            return countLeaf(p->lchild) + countLeaf(p->rchild) + 1;
        return countLeaf(p->lchild) + countLeaf(p->rchild);
    }
    return 0;
}

// function to find the count the leaf nodes in an AVL Tree recursively - Total nodes with degree 2
int AVLTree :: countNonLeaf(Node* p)
{
    if(p)
    {
        if(p->lchild && p->rchild)
            return countNonLeaf(p->lchild) + countNonLeaf(p->rchild) + 1;
        return countNonLeaf(p->lchild) + countNonLeaf(p->rchild);
    }
    return 0;
}

// function to find the count the internal nodes in an AVL Tree recursively - Total nodes with degree 2 or 1
int AVLTree :: internalNodes(Node* p)
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
int AVLTree :: NodesWithDegree1(Node* p)
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

    AVLTree avlt;

    avlt.RecursiveInsert(20);
    avlt.RecursiveInsert(10);
    avlt.RecursiveInsert(40);
    avlt.RecursiveInsert(30);
    avlt.RecursiveInsert(50);
    
    cout<<"Iterative Preorder : ";

    avlt.IterativePreorder();

    cout<<"\n";

    // cout<<"Iterative Inorder : ";

    // avlt.IterativeInorder();

    // cout<<"\n";

    // cout<<"Iterative Postorder : ";

    // avlt.IterativePostorder();

    // cout<<"\n";

    target = 16;

    // if(avlt.search(target))
    //     cout<<"Element "<<target<<" Found"<<endl;
    // else
    //     cout<<"Element "<<target<<" Not Found"<<endl;

    // avlt.RecursiveDelete(avlt.getRoot(), 9);

    cout<<"Recursive Inorder : ";
    avlt.inorder();

    cout<<endl;

    avlt.RecursiveDelete(10);

    cout<<"Recursive Inorder : ";
    avlt.inorder();

    cout<<endl;

    cout<<"Recursive Preorder : ";
    avlt.preorder();

    cout<<endl;
    
    return 0;
}