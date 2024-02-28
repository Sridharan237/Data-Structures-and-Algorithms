//Menu Driven CPP program for tri-diagonal matrix
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

    TriDiagonalMatrix Create(int n);
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimension();
};

// implementing the above declared functions of the above class using scope resolution operator


TriDiagonalMatrix TriDiagonalMatrix :: Create(int n)
{
    TriDiagonalMatrix tdm(n);    // creating an object for the diagonal class and passing n to the parameterized constructor

    int x;

    cout<<"Enter the elements :\n";

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;

            if(i - j == 1)
            {
                tdm.A[i-2] = x;
            }
            else if(i - j == 0)
            {
                tdm.A[n-1+i-1] = x;
            }
            else if(i - j == -1)
            {
                tdm.A[n-1+n+i-1] = x;
            }
        }
    }

    return tdm;
}

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
    TriDiagonalMatrix tdm;

    int choice, i, j, x, n;

    do
    {
        //Display Menu
        cout<<"\nxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<"x\tMenu          x\n";
        cout<<"xxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<"\t1.Create\n";
        cout<<"\t2.Set\n";
        cout<<"\t3.Get\n";
        cout<<"\t4.Display\n";
        cout<<"\t5.Exit\n";
        cout<<"xxxxxxxxxxxxxxxxxxxxxxx\n\n";

        cout<<"Enter you choice : ";
        cin>>choice;
        cout<<endl;
        
        switch(choice)
        {
            case 1://create
                cout<<"Enter the dimension : ";
                cin>>n;
                
                tdm = tdm.Create(n);

                break;

            case 2://set

                cout<<"Enter the row number, column number, element : ";
                cin>>i>>j>>x;

                tdm.Set(i, j, x);
                
                break;
            
            case 3://get

                cout<<"Enter the row number, column number : ";
                cin>>i>>j;

                cout<<"Element : "<<tdm.Get(i, j);
                cout<<endl;

                break;

            case 4://display
                tdm.Display();

                break;
        }

        // important :- break will only break the switch case otherwise it will check every other cases also, but it will not break the do while loop
    }while(choice<5);
}