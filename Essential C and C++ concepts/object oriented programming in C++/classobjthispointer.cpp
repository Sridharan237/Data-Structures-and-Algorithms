//program to illustrate class object and this pointer in cpp

#include <iostream>

using namespace std;

class Arithmetic
{
private:
    int a;
    int b;
public:
    Arithmetic(int a,int b){
        this->a=a;                //this is a pointer to the current object 
        this->b=b;                //this->a - means data members of a class 
    }                             //this points to ar-object 1, ar1-object 2  separately because this pointer will be created in memory of ar,ar1 separately and they points to the data members of each object separately
    int add()
    {
        return a+b;
    }
    int sub()
    {
        int c;
        c=a+b;
        return c;
    }
};
int main()
{
    Arithmetic ar(3,8),ar1(4,6);
    
    cout<<"Object 1 : "<<endl;
    cout<<"Add : "<<ar.add()<<endl;
    cout<<"Subtract : "<<ar.sub()<<endl;
    cout<<"Object2 : "<<endl;
    cout<<"Add : "<<ar1.add()<<endl;
    cout<<"Subtract : "<<ar1.sub()<<endl;
}
