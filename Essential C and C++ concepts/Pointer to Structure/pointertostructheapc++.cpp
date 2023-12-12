  #include <iostream>

using namespace std;

struct Rectangle 
{
  int l;
  int b;
};

int main() 
{
  struct Rectangle *p=new Rectangle;

  p->l=100,p->b=50;

  cout<<p->l<<endl<<p->b<<endl;
}
