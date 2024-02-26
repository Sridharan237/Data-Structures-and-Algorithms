//CPP program for tri-diagonal matrix
//By storing the 2D matrix in a 1D array by (lower-main-upper)diagonal order

#include<iostream>

using namespace std;

class TriDiagonalMatrix
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    TriDiagonalMatrix()
    {
        n = 2;
        A = new int[3*n-2];
    }

    TriDiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[3*n-2];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimension();
};

// implementing the above declared functions of the above class using scope resolution operator

void TriDiagonalMatrix :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i - j == 1)
    {
        A[i-2] = x;
    }
    else if(i - j == 0)
    {
        A[n-1+i-1] = x;
    }
    else if(i - j == -1)
    {
        A[n-1+n+i-1] = x;
    }
}

int TriDiagonalMatrix :: Get(int i, int j)
{
    if(i - j == 1)
    {
        return A[i-2];
    }
    else if(i - j == 0)
    {
        return A[n-1+i-1];
    }
    else if(i - j == -1)
    {
        return A[n-1+n+i-1];
    }
    else
    {
        return 0;
    }
}

void TriDiagonalMatrix :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i - j == 1)
            {
                cout<<A[i-2]<<" ";
            }   
            else if(i - j == 0)
            {
                cout<<A[n-1+i-1]<<" ";
            }
            else if(i - j == -1)
            {
                cout<<A[n-1+n+i-1]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int TriDiagonalMatrix :: getDimension()
{
    return n;
}

int main()
{
    int d;                  // d - dimension 

    cout<<"Enter the dimension of the matrix : ";
    cin>>d;

    TriDiagonalMatrix tdm(d);
    
    int i, j, x;

    cout<<"Enter the elements of the array : ";

    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            scanf("%d", &x);
            tdm.Set(i, j, x);
        }
    }
    
    cout<<tdm.Get(2, 3)<<endl;

    tdm.Display();
}