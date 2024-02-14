#include <iostream>

using namespace std;

int add(int a,int b)  
{
    int c;
    c=a+b;
    
    return (c);
}


int main()
{
   int x,y;
   x=10,y=15;
   
   int z=add(x,y);
   
   cout<<z;
}
