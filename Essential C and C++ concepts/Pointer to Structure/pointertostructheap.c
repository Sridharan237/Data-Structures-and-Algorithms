#include <iostream>

using namespace std;

struct Rectangle 
{
  int a;
  int b;
};

int main() 
{
  struct Rectangle *p=(struct Rectangle*)malloc(sizeof(struct Rectangle));

  p->l=100,p->b=50;

  cout<<p->l<<endl<<p->b<<endl;
}