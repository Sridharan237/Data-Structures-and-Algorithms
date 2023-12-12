//program to find string length
#include <iostream>

using namespace std;

int strLength(char string[])          //function for finding string length
{
    int i;

    for(i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        
    }
    return i;

    /*
    for(int i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        
    }                                          
    //returns garbage value if int i is declared in outside of for loop and in the for loop 
    but gives error "undeclared" if the int i is declared only within the for loop because the scope of the variable declared in the for loop is within the loop only 

    return i;
    */
}

int main() 
{
    char name[] = "superman";
    
    cout<<"Length of the string "<<name<<" is "<<strLength(name)<<endl;
}