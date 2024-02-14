#include <iostream>

using namespace std;

struct Rectangle 
{
   int length;
   int breadth;
};

void initialize(Rectangle *p,int l,int b)      //c++ syntax: (structure variable declare)
{                                              //           struct    sturcture_name   structure_variable;
   p->length=l;                                //               (OR)
   p->breadth=b;                               //            structure_name   sturcture_variable;
}                                               
                                               //c syntax:(structure variable declare) 
int area(Rectangle r1)                         //         struct    sturcture_name   structure_variable;
{
    return r1.length*r1.breadth;
}

int perimeter(Rectangle r1)
{
   int p;
   p=2*(r1.length+r1.breadth);

  return p;
}

int main() {
   Rectangle r={0,0};

    int length,breadth;
   
    cout<<"Enter length and breadth : "<<endl;
    cin>>length>>breadth;

    initialize(&r,length,breadth);//initializing using a function
  
    int a=area(r);//when the function is called an object //will be created inside area function
    int peri=perimeter(r);//when the function is called //an object will be created inside perimeter function

    cout<<"Area : "<<a<<endl;
    cout<<"Perimeter : "<<peri<<endl;

    return 0;
}