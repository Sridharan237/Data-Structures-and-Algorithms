#include<iostream>
#include<stdio.h>

struct Rectangle
{
   int length;
   int breadth;
};

/*
struct Rectangle
{
   int length;      ------>global declaration
   int breadth;
};
struct Rectangle r1,r2;
*/

/*
struct Rectangle
{
   int length;      ------>global declaration
   int breadth;
} r1,r2;
*/

int main()
{
   struct Rectangle r1={10,5};    ---->declaration + initialization

   cout<<r1.length<<endl;
   cout<<r1.breadth<<endl;
}
