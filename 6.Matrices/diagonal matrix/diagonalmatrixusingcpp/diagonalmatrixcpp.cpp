//CPP program for diagonal matrix
#include<iostream>

using namespace std;

class Diagonal
{
private:
    int * A;
    int n;              //no. of elements in the array

public:
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }

    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

// implementing the above declared functions of the above class using scope resolution operator

void Diagonal :: Set(int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i == j)
    {
        A[i-1] = x;
    }
}

int Diagonal :: Get(int i, int j)
{
    if(i == j)
        return A[i-1];
    else 
        return 0;
}

void Diagonal :: Display()
{
    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i == j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal dm(4);
    dm.Set(1, 1, 1);
    dm.Set(2, 2, 2);
    dm.Set(3, 3, 3);
    dm.Set(4, 4, 4);
    
    cout<<dm.Get(2, 3)<<endl;

    dm.Display();
}