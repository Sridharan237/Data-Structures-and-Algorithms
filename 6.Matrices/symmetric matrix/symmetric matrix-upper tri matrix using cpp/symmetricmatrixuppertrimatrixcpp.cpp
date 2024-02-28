//CPP program for symmetric matrix using => Upper triangular matrix using Column major mapping
#include<iostream>

using namespace std;

class SymmetricMatrixUpperTriangular
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    SymmetricMatrixUpperTriangular()
    {
        n = 2;
        A = new int[n*(n + 1)/2];
    }

    SymmetricMatrixUpperTriangular(int n)
    {
        this->n = n;
        A = new int[n*(n + 1)/2];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimension();
};

// implementing the above declared functions of the above class using scope resolution operator

void SymmetricMatrixUpperTriangular :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i <= j)
    {
        A[(j*(j-1)/2)+(i-1)] = x;
    }
}

int SymmetricMatrixUpperTriangular :: Get(int i, int j)
{
    if(i <= j)
        return A[(j*(j-1)/2)+(i-1)];
    else 
        return A[i*(i-1)/2+(j-1)];
}

void SymmetricMatrixUpperTriangular :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i <= j)
                cout<<A[(j*(j-1)/2)+(i-1)]<<" ";
            else
                cout<<A[i*(i-1)/2+(j-1)]<<" ";
        }
        cout<<endl;
    }
}

int SymmetricMatrixUpperTriangular :: getDimension()
{
    return n;
}

int main()
{
    int d;                  // d - dimension 

    cout<<"Enter the dimension of the matrix : ";
    cin>>d;

    SymmetricMatrixUpperTriangular smutm(d);
    
    int i, j, x;

    cout<<"Enter the elements of the array : ";

    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            scanf("%d", &x);
            smutm.Set(i, j, x);
        }
    }
    
    cout<<smutm.Get(2, 3)<<endl;

    smutm.Display();
}