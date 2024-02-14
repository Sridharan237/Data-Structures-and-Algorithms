#include <iostream>

using namespace std;

struct Rectangle 
{
  int a;
  int b;
};

int main() 
{
  struct Rectangle r={10,5};
  
  cout<<r.l<<r.b;

  struct Rectangle *p=&r;
  p->l=100,p->b=50;

  cout<<p->l<<endl<<p->b<<endl;
}