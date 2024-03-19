//cpp program for 
// ->creating sparse matrix
// ->displaying sparse matrix
// ->add 2 sparse matrices

#include<iostream>

using namespace std;

class Element
{
    public:
        int i;  //row number
        int j;  //column number
        int x;  //non-zero element
};

class Sparse
{
    private:
        int m;  //no. of rows
        int n;  //no. of columns
        int N;  //no. of non-zero elements
        Element * element;  //pointer to object

    public:
        Sparse(int m, int n, int N);
        ~Sparse();

        void read();
        void display();
};

Sparse :: Sparse (int m, int n, int N)
{
    this->m = m;
    this->n = n;
    this->N = N;

    element = new Element[N];
}

Sparse :: ~Sparse()
{
    delete [] element;
}

//function for reading the non-zero elements
void Sparse :: read()  
{
    int i;

    cout<<"Enter all the non-zero elements : "<<endl;

    for(i=0;i<N;i++)
    {
        cin>>element[i].i>>element[i].j>>element[i].x;
    }
}

//function for displaying sparse matrix
void Sparse :: display()
{
    int i, j, k=0;

    cout<<"Sparse Matrix : "<<endl;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i == element[k].i && j == element[k].j)
            {
                cout<<element[k++].x<<" ";    //k++ -> post increment - 1.assign, 2.increment
            }
            else 
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main() 
{
    Sparse s(5, 5, 5);

    s.read();

    s.display();

    return 0;
}