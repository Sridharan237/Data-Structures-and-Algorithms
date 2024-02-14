#include <iostream>

using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

struct Rectangle * fun()   //function without parameter
{
      struct Rectangle *p;
      p=new Rectangle; //to create memory in heap new //operator is used

      p->length=10;
      p->breadth=5;

      return (p);
  
}

int main() {
    struct Rectangle *ptr;
    ptr=fun();    

    cout<<"Inside main function:"<<endl;
    cout<<ptr->length<<endl;
    cout<<ptr->breadth<<endl;
}