#include <iostream>

using namespace std;

template<class T>                                                         //scope of template class T is within the class(starts from class ends at "};")
class Arithmetic
{
private:
    T a;
    T b;
public:
   Arithmetic(T a,T b);   //default constructor 
   T add();   //function prototype /function signature /function header
   T sub();  //function prototype /function signature /function header
};                                                   

template<class T>                       //scope of template class T end within the constructor function definition
Arithmetic<T>::Arithmetic(T a,T b)
{
    this->a=a;
    this->b=b;
}

template <class T>                     //scope of template class T ends within  the add function definition
T Arithmetic<T>::add()
{
    return a+b;
}

template <class T>                    //scope of template class T end within the sub function definition
T Arithmetic<T>::sub()                  
{
    T c;
    c=a-b;
    return c;
}

int main()
{
    Arithmetic<int> ar(8,3);
    
    cout<<"Object 1 : "<<endl;
    cout<<"Add : "<<ar.add()<<endl;
    cout<<"Subtract : "<<ar.sub()<<endl;
    
}
