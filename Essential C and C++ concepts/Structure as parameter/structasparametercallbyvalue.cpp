#include <iostream>

using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

void fun(struct Rectangle r1)
{
   r1.length=20;

   cout<<r1.length<<endl;
   cout<<r1.breadth<<endl;
}

int main() {
    struct Rectangle r={10,5};

    cout<<"Using a function:"<<endl;
    fun(r);

    cout<<"Inside main function:"<<endl;
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
}