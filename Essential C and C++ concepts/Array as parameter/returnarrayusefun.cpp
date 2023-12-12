#include <iostream>

using namespace std;

int* fun(int size){  
//int [ ] and int * are same //syntactically
   int *p;
   p=new int[size];

   for(int i=0;i<size;i++)
      p[i]=i+1;
  
  return (p);
}

//link of pointer p will be destroyed once the fun() function ends

int main() {
    int sz=5;

    int *ptr=fun(sz);

    for(int i=0;i<sz;i++)
      cout<<ptr[i]<<" ";
}