#include <iostream>

using namespace std;

struct Rectangle   //structure-have data members
{
   int length;   //variables/properties
   int breadth;


void initialize(int l,int b)      //we can have functions within structure in c++ but not in c language, they are also members of the structure 
{                   
   length = l;
   breadth = b;
}                                               
                                               
int area()                       //member functions           
{
    return length*breadth;   
}                            //we can access the variables inside the structure without using dot(.) operator.

int perimeter()
{
   int p;
   p=2*(length+breadth);

  return p;
}

};

int main() {
    struct Rectangle r={0,0};
  
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