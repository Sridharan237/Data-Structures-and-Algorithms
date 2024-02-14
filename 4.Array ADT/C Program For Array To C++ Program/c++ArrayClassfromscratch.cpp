#include<iostream>

using namespace std;

//class definition
class Array          //class -> data members and member function
{
 private: 
    //data members of the class
    int *A;
    int size;
    int length;
public:
    //(non parameterized) constructor
    Array()
    {
        size=10;
        A=new int[size];
        length=0;
    }

    //(parameterized) constructor
    Array(int sz)
    {
        size=sz;
        A=new int[size];
        length=0;
    }

    //destructor
    ~Array()
    {
         delete [] A;            // this line is same as free() in c -> to free the allocated space in heap memory
    }

    //function header (or) function prototype (or) function signature (or) function definition
    void Display();                        
    void Insert(int index,int x);
    int Delete(int index);
};

//function definition ---> member functions of the class

void Array::Display()
{
    printf("\nElements are ...\n");

    for(int i=0;i<length;i++)
       cout<<A[i]<<" ";
    cout<<endl;
}

void Array::Insert(int index,int x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>index;i--)
           A[i+1]=A[i];
        A[index]=x;
        length++;
    }
}

int Array::Delete(int index)
{
    if(index>=0 && index<length)
    {
        int deletedElement=0;
        deletedElement=A[index];

        for(int i=index;i<length-1;i++)
           A[i]=A[i+1];
        A[length-1]=0;
        length--;

        return deletedElement;
    }

    return 0;
}

int main()
{
    Array arr(10);

    arr.Insert(0,2);
    arr.Insert(1,3);
    arr.Insert(2,5);

    arr.Display();

    cout<<endl<<"Deleted Element is : "<<arr.Delete(0)<<endl;

    arr.Display();
}