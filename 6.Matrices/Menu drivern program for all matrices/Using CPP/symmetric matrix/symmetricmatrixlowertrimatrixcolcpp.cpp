//Menu driven CPP program for symmetric matrix using => lower triangular matrix using Column major mapping
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

    SymmetricMatrixLowerTriangular Create(int n);
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

// implementing the above declared functions of the above class using scope resolution operator

SymmetricMatrixLowerTriangular SymmetricMatrixLowerTriangular :: Create(int n)
{
    SymmetricMatrixLowerTriangular smltm(n);    // creating an object for the diagonal class and passing n to the parameterized constructor

    int x;

    cout<<"Enter the elements : \n";

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;

            if(i >= j)
            {
                smltm.A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)] = x;
            }
        }
    }

    return smltm;
}

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
    else if(j > i)
        return A[n*(i-1) -(i-2)*(i-1)/2 + (j-i)];
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
                cout<<A[n*(i-1) -(i-2)*(i-1)/2 + (j-i)]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    SymmetricMatrixLowerTriangular smltm;

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
                
                smltm = smltm.Create(n);

                break;

            case 2://set

                cout<<"Enter the row number, column number, element : ";
                cin>>i>>j>>x;

                smltm.Set(i, j, x);
                
                break;
            
            case 3://get

                cout<<"Enter the row number, column number : ";
                cin>>i>>j;

                cout<<"Element : "<<smltm.Get(i, j);
                cout<<endl;

                break;

            case 4://display
                smltm.Display();

                break;
        }

        // important :- break will only break the switch case otherwise it will check every other cases also, but it will not break the do while loop
    }while(choice<5);
}