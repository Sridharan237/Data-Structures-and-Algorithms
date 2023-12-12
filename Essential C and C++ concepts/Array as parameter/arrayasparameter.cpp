#include <iostream>

using namespace std;

void fun(int A[],int size)
{
   for(int i=0;i<size;i++)
     cout<<A[i]<<" ";
}

int main() {
    int A[]={2,4,6,8,10},size=5;

    fun(A,size);

    cout<<endl;
  
    for(int x:A)
      cout<<x<<" ";
}