//CPP program for toeplitz matrix

#include<iostream>

using namespace std;

class ToeplitzMatrix
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    ToeplitzMatrix()
    {
        n = 2;
        A = new int[2*n-1];
    }

    ToeplitzMatrix(int n)
    {
        this->n = n;
        A = new int[2*n-1];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimension();
};

// implementing the above declared functions of the above class using scope resolution operator

void ToeplitzMatrix :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i <= j)
    {
        A[j-i] = x;
    }
    else if(i > j)
    {
        A[n+i-j-1] = x;
    }
}

int ToeplitzMatrix :: Get(int i, int j)
{
    if(i <= j)
    {
        return A[j-i];
    }
    else if(i > j)
    {
        return A[n+i-j-1];
    }
    else
    {
        return 0;
    }
}

void ToeplitzMatrix :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i <= j)
            {
                cout<<A[j-i]<<" ";
            }   
            else if(i > j)
            {
                cout<<A[n+i-j-1]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int ToeplitzMatrix :: getDimension()
{
    return n;
}

int main()
{
    int d;                  // d - dimension 

    cout<<"Enter the dimension of the matrix : ";
    cin>>d;

    ToeplitzMatrix tm(d);
    
    int i, j, x;

    cout<<"Enter the elements of the array : ";

    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            scanf("%d", &x);
            tm.Set(i, j, x);
        }
    }
    
    cout<<tm.Get(2, 3)<<endl;

    tm.Display();
}