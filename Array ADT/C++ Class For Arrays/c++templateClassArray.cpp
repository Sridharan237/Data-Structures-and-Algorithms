#include<iostream>

using namespace std;

//template - class definition
template<class T>
class Array          //class -> data members and member function
{
 private: 
    //data members of the class
    T *A;
    int size;
    int length;
public:
    //(non parameterized) constructor
    Array()
    {
        size=10;
        A=new T[size];
        length=0;
    }

    //(parameterized) constructor
    Array(int sz)
    {
        size=sz;
        A=new T[size];
        length=0;
    }

    //destructor
    ~Array()
    {
         delete [] A;            // this line is same as free() in c -> to free the allocated space in heap memory
    }

    //function header (or) function prototype (or) function signature (or) function definition
    void Display();                        
    void Insert(int index,T x);
    T Delete(int index);
};

//function definition ---> member functions of the class

template<class T>
void Array<T>::Display()
{
    printf("\nElements are ...\n");

    for(int i=0;i<length;i++)
       cout<<A[i]<<" ";
    cout<<endl;
}

template<class T>
void Array<T>::Insert(int index,T x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>index;i--)
           A[i+1]=A[i];
        A[index]=x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    if(index>=0 && index<length)
    {
        T deletedElement=0;
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
    Array<char> arr(10);

    arr.Insert(0,'a');
    arr.Insert(1,'b');
    arr.Insert(2,'c');

    arr.Display();

    cout<<endl<<"Deleted Element is : "<<arr.Delete(0)<<endl;

    arr.Display();
}