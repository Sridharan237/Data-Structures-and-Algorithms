#include <iostream>

using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

void fun(struct Rectangle *p)
{
   p->length=20;

   cout<<p->length<<endl;
   cout<<p->breadth<<endl;
}

int main() {
    struct Rectangle r={10,5};

    cout<<"Using a function:"<<endl;
    fun(&r);

    cout<<"Inside main function:"<<endl;
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
}