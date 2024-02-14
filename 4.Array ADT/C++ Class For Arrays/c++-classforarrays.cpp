//c program to c++ program on Arrays-concept
#include<iostream>
#include<stdlib.h>

using namespace std;

class Array
{
private:                             //private members ---> can be accessible from within the class
    int *A;
    int size;
    int length;
    void swap(int *x,int *y);

public:
    
    Array(int sz)
    {
         size=sz;
         A=new int[size];
         length=0;
    }

    ~Array()
    {
        delete [] A;
    }

    void Display();           //function header (or) function prototype (or) function signature
    void Append(int x);
    void Insert(int x,int index);        // (struct Array *arr)     ---> parameter in insert function is ignored because member function of a class can directly access the data members of the class
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int RBinSearch(int l,int h,int key);
    int Get(int index);
    void Set(int index,int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);

};

 void Array::swap(int *x,int *y)    
    {
       int temp;

       temp=*x;
       *x=*y;
       *y=temp;
    }
    
void Array::Display()                // :: ---> scope resolution operator
{
   int i;
   printf("\nElements are\n");

   for(i=0;i<length;i++)
       printf("%d ",A[i]);
}

void Array::Append(int x)
{
    if(length<size)
      A[length++]=x;
}

void Array::Insert(int x,int index)
{
     int i;
     if(index>=0 && index <=length)
     {
         for(i=length;i>index;i--)
             A[i]=A[i-1];

         A[index]=x;
         length++;
     }
}

int Array::Delete(int index)
{
    int x=0;
    int i;

    if(index>=0 && index<length)
    {
         x=A[index];

       for(i=index;i<length-1;i++)
          A[i]=A[i+1];

       length--;

       return x;
    }

 return 0;
}


int Array::LinearSearch(int key)
{
    int i;

    for(i=0;i<length;i++)
    {
        if(key==A[i])
        {
            swap(&A[i],&A[0]);

            return i;
        }
    }

    return -1;
}

int Array::BinarySearch(int key)
{
 int l,mid,h;
 l=0;
 h=length-1;

 while(l<=h)
 {
 mid=(l+h)/2;
 if(key==A[mid])
 return mid;
 else if(key<A[mid])
 h=mid-1;
 else
 l=mid+1;
 }
 return -1;
}

int Array::RBinSearch(int l,int h,int key)
{
 int mid;
 
 if(l<=h)
 {
 mid=(l+h)/2;
 if(key==this->A[mid])
 return mid;
 else if(key<this->A[mid])
 return RBinSearch(l,mid-1,key);
 else
 return RBinSearch(mid+1,h,key);
 }
 return -1;
}

int Array::Get(int index)
{
 if(index>=0 && index<length)
 return A[index];
 return -1;
}

void Array::Set(int index,int x)
{
 if(index>=0 && index<length)
 A[index]=x;
}

int Array::Max()
{
    int max=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]>max)
           max=A[i];
    }
   return max;
}

int Array::Min()
{
 int min=A[0];
 int i;
 for(i=1;i<length;i++)
 {
 if(A[i]<min)
 min=A[i];
 }
 return min;
}

int Array::Sum()
{
    int s=0;
    int i;
    for(i=0;i<length;i++)
        s+=A[i];

    return s;
}

float Array::Avg()
{
 return (float)Sum()/length;
}

void Array::Reverse()
{
 int *B;
 int i,j;

 B=(int *)malloc(length*sizeof(int));
 for(i=length-1,j=0;i>=0;i--,j++)
 B[j]=A[i];
 for(i=0;i<length;i++)
 A[i]=B[i];

}

void Array::Reverse2()
{
 int i,j;
 for(i=0,j=length-1;i<j;i++,j--)
 {
 swap(&A[i],&A[j]);
 }
}

void Array::InsertSort(int x)
{
 int i=length-1;
 if(length==size)
 return;
 while(i>=0 && A[i]>x)
 {
 A[i+1]=A[i];
 i--;
 }
 A[i+1]=x;
 length++;

}

int Array::isSorted()
{
 int i;
 for(i=0;i<length-1;i++)
 {
 if(A[i]>A[i+1])
 return 0;
 }
 return 1;
}

void Array::Rearrange()
{
 int i,j;
 i=0;
 j=length-1;

 while(i<j)
 {
 while(A[i]<0)i++;
 while(A[j]>=0)j--;
 if(i<j)swap(&A[i],&A[j]);
 }

}

Array*   Array::Merge(Array arr2)        // Needs to return an object of the Array-class
{
 int i,j,k;
 i=j=k=0;

 Array *arr3 = new Array(length+arr2.length);

 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 arr3->A[k++]=A[i++];
 else
 arr3->A[k++]=arr2.A[j++];
 }
 for(;i<length;i++)
 arr3->A[k++]=A[i];
 for(;j<arr2.length;j++)
 arr3->A[k++]=arr2.A[j];
 arr3->length=length+arr2.length;
 arr3->size=10;

 return arr3;
}

Array*    Array::Union(Array arr2)
{
 int i,j,k;
 i=j=k=0;

 Array *arr3=new Array(length+arr2.length);

 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 arr3->A[k++]=A[i++];
 else if(arr2.A[j]<A[i])
 arr3->A[k++]=arr2.A[j++];
 else
 {
 arr3->A[k++]=A[i++];
 j++;
 }
 }
 for(;i<length;i++)
 arr3->A[k++]=A[i];
 for(;j<arr2.length;j++)
 arr3->A[k++]=arr2.A[j];

 arr3->length=k;
 arr3->size=10;

 return arr3;
}

Array* Array::Intersection(Array arr2)
{
 int i,j,k;
 i=j=k=0;

 Array *arr3=new Array(length + arr2.length);

 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 i++;
 else if(arr2.A[j]<A[i])
 j++;
 else if(A[i]==arr2.A[j])
 {
 arr3->A[k++]=A[i++];
 j++;
 }
 }

 arr3->length=k;
 arr3->size=10;

 return arr3;
}

Array* Array::Difference(Array arr2)
{
 int i,j,k;
 i=j=k=0;

 Array *arr3=new Array(length+arr2.length);

 while(i<length && j<arr2.length)
 {
 if(A[i]<arr2.A[j])
 arr3->A[k++]=A[i++];
 else if(arr2.A[j]<A[i])
 j++;
 else
 {
 i++;
 j++;
 }
 }
 for(;i<length;i++)
 arr3->A[k++]=A[i];


 arr3->length=k;
 arr3->size=10;

 return arr3;
}

int main()
{
   
    /*
    1.Insert
    2.Delete
    3.Search
    4.Sum
    5.Display
    6.Exit
    */

   int INDEX,x;                                //inserting an element at specific position in a sorted array
   int index,deletedElement;             //deleting an element in an array and returning index of the deleted element
   int SearchingElement,searchedElement_index;            //searching an element using linear search and returning the index of the target or key element (or) value
   int sum;                              //returning the sum of the elements in the array
   
   int size;
   cout<<"Enter the size of the array : ";
   cin>>size;
   
    Array* arr1;
    Array  *arr2;
    Array * arr3;          // pointer to an object of class-Array
    
    arr1=new Array(size);
    arr2=new Array(size);

   int option;



  do
  {
    cout<<"\n---Menu---\n";
    cout<<"1.Insert\n";
    cout<<"2.Delete\n";
    cout<<"3.Search\n";
    cout<<"4.Sum\n";
    cout<<"5.Display\n";
    cout<<"6.Exit\n";


    cout<<"Enter your choice : ";
    scanf("%d",&option);


     switch(option)
     {
        case 1:
            cout<<"Enter the element and the position to be inserted : ";
            scanf("%d%d",&x,&INDEX);
            arr1->Insert(x,INDEX);
            break;
        case 2:
            cout<<"Enter the index of the element to be deleted : ";
            scanf("%d",&index);
            deletedElement=arr1->Delete(index);
            cout<<"Deleted element is : "<<deletedElement<<endl;
            break;
        case 3:
            cout<<"Enter the element to be searched : ";
            scanf("%d",&SearchingElement);
            searchedElement_index=arr1->LinearSearch(SearchingElement);
            cout<<"The index of the searched element is :  "<<searchedElement_index<<endl;
            break;
        case 4:
            sum=arr1->Sum();
            cout<<"Sum of the elements in the array is : "<<sum<<endl;
            break;
        case 5:arr1->Display();
       }
   }while(option<6);

}
