//program to check if the string is valid or not
#include <iostream>

using namespace std;

int validString(char name[])          //function for checking the given string is valid or not
{

    for(int i=0;name[i]!='\0';i++)         //   '\0' -> null character
    {
        if(!(name[i]>=65 && name[i]<=90 || name[i]>='a' && name[i]<=122 || name[i]>= '0' && name[i]<='9'))                  // condition for finding uppercase 65-90
           return 0;
    }
    return 1;
}

int main() 
{
    char str1[] = "WELCOME#123";
    
    if(validString(str1) == 1)
      cout<<"Valid String\n";
    else
      cout<<"Not a valid string\n";
}