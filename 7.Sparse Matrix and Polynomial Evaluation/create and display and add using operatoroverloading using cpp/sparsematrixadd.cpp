//cpp program for 
// ->creating sparse matrix
// ->displaying sparse matrix
// ->add 2 sparse matrices
//using friend, member functions and operator overloading in cpp

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

        //operator overloading
        Sparse operator+(Sparse &s);    
        //implemented using friend functions
        friend istream& operator>>(istream & is, Sparse &s);   // >> - extraction operator
        friend ostream & operator<<(ostream & os, Sparse &s);  // << - insertion operator

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

Sparse Sparse :: operator+(Sparse &s)
{
    Sparse * sum;

    if(m != s.m && n != s.n)
        return Sparse(0, 0, 0);

    //creating and pointing sum in heap
    sum = new Sparse(m, n, N+s.N);

    int i, j, k;
    i=j=k=0;

    //Adding
    while(i<N && j<s.N)
    {
        if(element[i].i < s.element[j].i)
            sum->element[k++] = element[i++];
        else if(element[i].i > s.element[j].i)
            sum->element[k++] = s.element[j++];
        else
        {
            if(element[i].j < s.element[i].j)
                sum->element[k++] = element[i++];
            else if(element[i].j > s.element[i].j)
                sum->element[k++] = element[j++];
            else        //if both are at same row number and column number
            {
                sum->element[k] = element[i++];
                sum->element[k++].x += s.element[j++].x;
            }
        }
    }

    for(;i<N;i++)
        sum->element[k++] = element[i];

    for(;j<s.N;j++)
        sum->element[k++] = element[j];
    
    sum->N = k;

    return *sum;
}

//friend function for reading the non-zero elements
istream& operator>>(istream & is, Sparse &s)  
{
    int i;

    cout<<"Enter all the non-zero elements : "<<endl;

    for(i=0;i<s.N;i++)
    {
        cin>>s.element[i].i>>s.element[i].j>>s.element[i].x;
    }

    return is;
}

//friend function for displaying sparse matrix
ostream& operator<<(ostream &os, Sparse &s)
{
    int i, j, k=0;

    cout<<"Sparse Matrix : "<<endl;

    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i == s.element[k].i && j == s.element[k].j)
            {
                cout<<s.element[k++].x<<" ";    //k++ -> post increment - 1.assign, 2.increment
            }
            else 
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

    return os;
}

int main() 
{
    Sparse s1(5, 5, 5), s2(5, 5, 5);

    cin>>s1;
    cin>>s2;

    cout<<s1;
    cout<<s2;

    Sparse sum = s1+s2;

    cout<<"Sum Matrix : "<<endl;
    cout<<sum;

    return 0;
}