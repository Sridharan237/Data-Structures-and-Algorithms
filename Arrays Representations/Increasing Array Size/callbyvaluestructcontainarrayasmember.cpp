#include <iostream>

using namespace std;

struct Test 
{
   int A[5];
   int n;
};

void fun(struct Test t1)
{
   t1.A[0]=25;
   t1.A[1]=30;
   t1.n=6;
}

int main() 
{
    struct Test t={{2,4,6,8,10},5};

    cout<<"before passing values to function"<<endl;
  
    for(int x:t.A)
      cout<<x<<" ";
   
    fun(t);  //pass by value (passing structure variable //as value)

    cout<<"\nafter after values to function"<<endl;
  
    for(int x:t.A)
      cout<<x<<" ";
    
}