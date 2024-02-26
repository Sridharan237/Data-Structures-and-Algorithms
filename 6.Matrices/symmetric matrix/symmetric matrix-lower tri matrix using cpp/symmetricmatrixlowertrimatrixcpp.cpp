//CPP program for symmetric matrix using => lower triangular matrix using Column major mapping
#include<iostream>

using namespace std;

class SymmetricMatrixLowerTriangular
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    SymmetricMatrixLowerTriangular()
    {
        n = 2;
        A = new int[n*(n + 1)/2];
    }

    SymmetricMatrixLowerTriangular(int n)
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

void SymmetricMatrixLowerTriangular :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i >= j)
    {
        A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)] = x;
    }
}

int SymmetricMatrixLowerTriangular :: Get(int i, int j)
{
    if(i >= j)
        return A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)];
    else 
        return 0;
}

void SymmetricMatrixLowerTriangular :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i >= j)
                cout<<A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int SymmetricMatrixLowerTriangular :: getDimension()
{
    return n;
}

int main()
{
    int d;                  // d - dimension 

    cout<<"Enter the dimension of the matrix : ";
    cin>>d;

    SymmetricMatrixLowerTriangular smltm(d);
    
    int i, j, x;

    cout<<"Enter the elements of the array : ";

    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            scanf("%d", &x);
            smltm.Set(i, j, x);
        }
    }
    
    cout<<smltm.Get(2, 3)<<endl;

    smltm.Display();
}