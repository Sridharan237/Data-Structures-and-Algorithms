//program to compare two strings
#include<iostream>

using namespace std;

char* toUpperCase(char string[])          //function for changing lowercase letters to uppercase letters
{
    int i;

    for(i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        if(string[i]>='a' && string[i]<=122)           // condition for finding lowercase 97-122
           string[i] -= 32;
    }
    return string;
}

void compare(char A[], char B[])          //function for comparing two strings 
{
    A = toUpperCase(A);
    B = toUpperCase(B);

    int i,j;
    
    for(i=j=0;A[i]!='\0' && A[j]!='\0';i++,j++)         //   '\0' -> null character
    {
        if(A[i] != B[j])              //character in two strings not equal
          break;
    }
    
    if(A[i] == B[j])
        cout<<"Two strings are equal";
    else if(A[i]>B[j])
        cout<<"First string is greater";
    else 
        cout<<"First string is smaller";
}

int main() 
{
    char str1[] = "painter";
    char str2[] = "Painting";

    compare(str1, str2);
}