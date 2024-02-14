#include <iostream>

using namespace std;

class Rectangle 
{

    int length;
    int breadth;
    
    public:
    Rectangle()                 //------->default constructor
    {
        length=0;
        breadth=0;
    }
    Rectangle(int l,int b)      //------>parameterized constructor
    {
        length=l;
        breadth=b;
    }
    int area()                                //facilitators-which perform operations on data members
    {
        return length*breadth;
    }
    int perimeter()                           //facilitator
    {
        return 2*(length+breadth);
    }
    void setLength(int l)                             //mutator (or)   setter function
    {
        length=l;
    }
    void setBreadth(int b)                            //mutator  (or)   setter function
    { 
        breadth=b;
        
    }
    int getLength()                                  //accessor (or)  getter function
    {
        return length;
    }
    int getBreadth()                                //accessor  (or)   getter function     
    {
        return breadth;
    }
    ~Rectangle()
    {
        cout<<"Destructor";
    }
};

int main()
{
    Rectangle r(10,5);
    
    cout<<"Area : "<<r.area()<<endl;
    cout<<"Perimeter : "<<r.perimeter()<<endl;
    
    r.setLength(20);
    
    cout<<"length : "<<r.getLength()<<endl;
    cout<<"breadth : "<<r.getBreadth()<<endl;
}
