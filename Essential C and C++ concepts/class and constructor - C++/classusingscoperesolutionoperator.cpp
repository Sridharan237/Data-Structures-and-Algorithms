#include <iostream>

using namespace std;

class Arithmetic
{
private:
    int a;
    int b;
public:
   Arithmetic(int a,int b);   //default constructor 
   int add();   //function prototype /function signature /function header
   int sub();  //function prototype /function signature /function header
};

Arithmetic::Arithmetic(int a,int b)
{
    this->a=a;
    this->b=b;
}
int Arithmetic::add()
{
    return a+b;
}
int Arithmetic::sub()
{
    int c;
    c=a-b;
    return c;
}
int main()
{
    Arithmetic ar(8,3);
    
    cout<<"Object 1 : "<<endl;
    cout<<"Add : "<<ar.add()<<endl;
    cout<<"Subtract : "<<ar.sub()<<endl;
    
}
