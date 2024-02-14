#include <iostream>
#include<stdio.h>

using namespace std;

int main() {
   int length = 0, breadth = 0;// As it is good practice to initialize the variables to 0 for avoiding any problems 
  
   printf("Enter the length and breadth: ");
   cin>>length>>breadth;

   int area = (length*breadth);
   int perimeter = 2*(length + breadth);

   cout<<"Area : "<<area<<"\nPerimeter : "<<perimeter;
}