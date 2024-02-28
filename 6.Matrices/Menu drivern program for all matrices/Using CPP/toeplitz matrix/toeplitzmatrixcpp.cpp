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

    ToeplitzMatrix Create(int n);
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimension();
};

// implementing the above declared functions of the above class using scope resolution operator

ToeplitzMatrix ToeplitzMatrix :: Create(int n)
{
    ToeplitzMatrix tm(n);    // creating an object for the diagonal class and passing n to the parameterized constructor

    int x;

    cout<<"Enter the elements :\n";

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;

            if(i <= j)
            {
                tm.A[j-i] = x;
            }
            else if(i > j)
            {
                tm.A[n+i-j-1] = x;
            }
        }
    }

    return tm;
}

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
    ToeplitzMatrix tm;

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
                
                tm = tm.Create(n);

                break;

            case 2://set

                cout<<"Enter the row number, column number, element : ";
                cin>>i>>j>>x;

                tm.Set(i, j, x);
                
                break;
            
            case 3://get

                cout<<"Enter the row number, column number : ";
                cin>>i>>j;

                cout<<"Element : "<<tm.Get(i, j);
                cout<<endl;

                break;

            case 4://display
                tm.Display();

                break;
        }

        // important :- break will only break the switch case otherwise it will check every other cases also, but it will not break the do while loop
    }while(choice<5);
}