//CPP program for Upper triangular matrix using Column major mapping
#include<iostream>

using namespace std;

class UpperTriangularMatrix
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    UpperTriangularMatrix()
    {
        n = 2;
        A = new int[n*(n + 1)/2];
    }

    UpperTriangularMatrix(int n)
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

void UpperTriangularMatrix :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i <= j)
    {
        A[(j*(j-1)/2)+(i-1)] = x;
    }
}

int UpperTriangularMatrix :: Get(int i, int j)
{
    if(i <= j)
        return A[(j*(j-1)/2)+(i-1)];
    else 
        return 0;
}

void UpperTriangularMatrix :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i <= j)
                cout<<A[(j*(j-1)/2)+(i-1)]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int UpperTriangularMatrix :: getDimension()
{
    return n;
}

int main()
{
    int d;                  // d - dimension 

    cout<<"Enter the dimension of the matrix : ";
    cin>>d;

    UpperTriangularMatrix utm(d);
    
    int i, j, x;

    cout<<"Enter the elements of the array : ";

    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            scanf("%d", &x);
            utm.Set(i, j, x);
        }
    }
    
    cout<<utm.Get(2, 3)<<endl;

    utm.Display();
}