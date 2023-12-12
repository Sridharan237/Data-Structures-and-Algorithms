//program to change the case of a string 
#include <iostream>

using namespace std;

char* toLowerCase(char string[])          //function for changing uppercase letters to lowercase letters
{
    int i;

    for(i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        if(string[i]>=65 && string[i]<=90)                  // condition for finding uppercase 65-90
           string[i] += 32;
    }
    return string;
}

char* toUpperCase(char string[])          //function for changing lowercase letters to uppercase letters
{
    int i;

    for(i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        if(string[i]>='a' && string[i]<=122)           //// condition for finding lowercase 97-122
           string[i] -= 32;
    }
    return string;
}

char* ToggleCase(char string[])          //function for toggling the cases 
{
    int i;

    for(i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        if(string[i]>='A' && string[i]<=90)                  // condition for finding uppercase 65-90
           string[i] += 32;
        else if(string[i]>=97 && string[i]<='z')           //// condition for finding lowercase 97-122
           string[i] -= 32;
    }
    return string;
}

int main() 
{
    char str1[] = "WELCOME";
    char str2[] = "hello";
    char str3[] = "WelCome";
    
    cout<<"To lowercase : "<<toLowerCase(str1)<<endl;
    cout<<"To uppercase : "<<toUpperCase(str2)<<endl;
    cout<<"changing every case to opposite case : "<<ToggleCase(str3)<<endl<<endl;
}