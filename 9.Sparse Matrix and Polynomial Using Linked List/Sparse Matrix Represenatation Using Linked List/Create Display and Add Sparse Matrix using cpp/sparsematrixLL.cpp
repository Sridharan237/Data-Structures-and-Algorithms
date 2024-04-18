// cpp program to create, display and add sparse matrix (sparse matrix representation using linked list) 
// sparse matrix - order = m x n 
// m-rows, n-columns

#include<iostream>

using namespace std;

struct Node
{
    int column;
    int value;  // non zero element in sparse matrix
    Node *next;
};

class SparseMatrix
{
    public:
        Node **A; // A - pointer to an array of Node pointers created inside heap
        int rows;  // no. of rows in the sparse matrix
        int columns;  // no. of columns in the sparse matrix
        int nonzero; // nonzero - no. of non-zero elements in the linked list

        SparseMatrix() {A = nullptr;rows = 0;columns=0;nonzero = 0;} 
        SparseMatrix(int rows, int columns);
        ~SparseMatrix();

        void insert(int rowno, int columnno, int nonzero);
        SparseMatrix addSparse(SparseMatrix B);
        
        void Display();
};

// implementation of the above functions are below

SparseMatrix :: SparseMatrix(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    this->nonzero = 0;

    this->A = new Node*[this->rows]; // creating inside heap

    for(int i=0;i<this->rows;i++)
        A[i] = 0;
}

SparseMatrix :: ~SparseMatrix()
{
    int i;

    Node* p;

    for(i=0;i<this->nonzero;i++)
    {
        if(A[i] != nullptr)
        {
            p = A[i];

            while(p != nullptr)
            {
                A[i] = p->next;

                delete p;

                p = A[i];
            } 
        }
    }
}

// function to display a sparse matrix
void SparseMatrix :: Display()
{
    int i, j;

    Node *p;
    
    cout<<"Sparse Matrix : "<<endl;
    
    for(i=0;i<this->rows;i++)
    {
        if(A[i])
        {
            p = A[i];
            
            for(j=0;j<this->columns;j++)
            {
                if(p != nullptr && j == p->column)
                {
                    cout<<p->value<<" ";

                    if(p != nullptr)
                        p = p->next;
                }
                else
                    cout<<"0 ";
            }

            cout<<endl;
        }
    }
}

// function to insert nonzero elements into the sparse matrix
void SparseMatrix :: insert(int rowno, int columnno, int nonzero)
{
    Node *p, *t;

    if(A[rowno] == nullptr)
    {
        A[rowno] = new Node;

        A[rowno]->column = columnno;    
        A[rowno]->value = nonzero;
        A[rowno]->next = nullptr;
    }
    else
    {
        p = A[rowno];

        while(p->next != nullptr)
            p = p->next;

        t = new Node;
        
        t->column = columnno;
        t->value = nonzero;
        t->next = nullptr;

        p->next = t;
    }
}


// function to add two sparse matrices
SparseMatrix SparseMatrix :: addSparse(SparseMatrix B)
{
    int i, j;

    Node *p, *q;

    SparseMatrix sum(this->rows, this->columns);

    if(this->rows == B.rows && this->columns == B.columns)
    {
        for(i=0;i<this->rows;i++)
        {
        p = this->A[i];
        q = B.A[i];

        for(j=0;j<this->columns;j++)
        {
            if(p != nullptr && q != nullptr)
            {
                if(j == p->column && j == q->column)
                {
                    sum.insert(i, j, p->value+q->value);

                    p = p->next;
                    q = q->next;

                    sum.nonzero++;
                }
                else if(j == p->column)
                {
                    sum.insert(i, j, p->value);

                    p = p->next;

                    sum.nonzero++;
                }
                else if(j == q->column) 
                { 
                    sum.insert(i, j, q->value);

                    q = q->next;

                    sum.nonzero++;
                }
            }
            else if(p != nullptr)
            {
                if(j == p->column)
                {
                    sum.insert(i, j, p->value);

                    p = p->next;

                    sum.nonzero++;
                }
            }
            else if(q != nullptr)
            {
                if(j == q->column)
                {
                    sum.insert(i, j, q->value);

                    q = q->next;

                    sum.nonzero++;
                }
            }
        }
        }
    }

    return sum;
}

int main()
{
    SparseMatrix A(3, 3);

    A.insert(0, 0, 1);
    A.insert(1, 1, 1);
    A.insert(2, 2, 1);

    A.Display();

    SparseMatrix B(3, 3);

    B.insert(0, 0, 1);
    B.insert(1, 0, 1);
    B.insert(2, 0, 1);

    B.Display();

    SparseMatrix C = A.addSparse(B);

    cout<<endl<<"Sparse matrix C : "<<C.rows<<" "<<C.columns<<" "<<C.nonzero<<endl;

    C.Display();
}