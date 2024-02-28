//Menu driven CPP program for diagonal matrix

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

    Diagonal Create(int n);
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

// implementing the above declared functions of the above class using scope resolution operator
Diagonal Diagonal :: Create(int n)
{
    Diagonal dm(n);    // creating an object for the diagonal class and passing n to the parameterized constructor

    int x;

    printf("Enter the Elements :\n");

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;

            if(i == j)
                dm.A[i-1] = x;
        }
    }

    return dm;
}

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
    Diagonal dm;

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
                
                dm = dm.Create(n);

                break;

            case 2://set

                cout<<"Enter the row number, column number, element : ";
                cin>>i>>j>>x;

                dm.Set(i, j, x);
                
                break;
            
            case 3://get

                cout<<"Enter the row number, column number : ";
                cin>>i>>j;

                cout<<"Element : "<<dm.Get(i, j);
                cout<<endl;

                break;

            case 4://display
                dm.Display();

                break;
        }

        // important :- break will only break the switch case otherwise it will check every other cases also, but it will not break the do while loop
    }while(choice<5);
}