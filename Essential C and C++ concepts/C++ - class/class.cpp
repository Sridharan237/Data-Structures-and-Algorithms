#include <iostream>

using namespace std;

class Rectangle   
{
   int length;   
   int breadth;

public:
void initialize(int l,int b)      
{                   
   length = l;
   breadth = b;
}                                               
                                               
int area()                                
{
    return length*breadth;   
}                           

int perimeter()
{
   int p;
   p=2*(length+breadth);

  return p;
}

};

int main() {
    Rectangle r;
  
    int length,breadth;
   
    cout<<"Enter length and breadth : "<<endl;
    cin>>length>>breadth;

    r.initialize(length,breadth);
  
    int a=r.area();
    int peri=r.perimeter();

    cout<<"Area : "<<a<<endl;
    cout<<"Perimeter : "<<peri<<endl;

    return 0;
}