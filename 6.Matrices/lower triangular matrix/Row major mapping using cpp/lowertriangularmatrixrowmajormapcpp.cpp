//CPP program for lower triangular matrix using Row major mapping
#include<iostream>

using namespace std;

class LowerTriangularMatrix
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    LowerTriangularMatrix()
    {
        n = 2;
        A = new int[n*(n + 1)/2];
    }

    LowerTriangularMatrix(int n)
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

void LowerTriangularMatrix :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i >= j)
    {
        A[i*(i-1)/2 + j-1] = x;
    }
}

int LowerTriangularMatrix :: Get(int i, int j)
{
    if(i >= j)
        return A[i*(i-1)/2 + j-1];
    else 
        return 0;
}

void LowerTriangularMatrix :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i >= j)
                cout<<A[i*(i-1)/2 + j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int LowerTriangularMatrix :: getDimension()
{
    return n;
}

int main()
{
    int d;

    cout<<"Enter the dimension of the matrix : ";
    cin>>d;

    LowerTriangularMatrix ltm(d);
    
    int i, j, x;

    cout<<"Enter the elements of the array : ";

    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            scanf("%d", &x);
            ltm.Set(i, j, x);
        }
    }
    
    cout<<ltm.Get(2, 3)<<endl;

    ltm.Display();
}