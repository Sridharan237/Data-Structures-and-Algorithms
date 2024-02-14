#include <iostream>

using namespace std;

void swap(int * a,int * b)  //function prototype /signature /function declaration 
{                          //funtion definition
    int temp;
    temp=*a;
    *a=*b;                 
    *b=temp;
}


int main()
{
   int x,y;
   x=10,y=15;
   
   swap(&x,&y);           //function calling
   
   cout<<"X value: "<<x<<endl<<"Y value: "<<y<<endl;
}