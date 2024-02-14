#include<iostream>

using namespace std;

int main()
{
    int a=10;
    int &r=a;  //r-reference r,a are same
    
    cout<<a<<endl<<r<<endl;
    int b=5;
    r=b;
    cout<<a<<endl<<r;
}