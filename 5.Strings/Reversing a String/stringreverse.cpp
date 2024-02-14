//program to reverse the string
#include<iostream>

using namespace std;

void reverseString1(char A[])          //function for reversing the string using method-1
{
    char * B;                          // another character array to store the reverse string
    int i,j;
    
    for(j=0;A[j]!='\0';j++)         //   '\0' -> null character
    {
    }
    j = j-1;                       // j -> length of the array and j-1 -> last index of the array of characters (or)a string

    for(i=0;j>=0;i++,j--)
    {
        B[i] = A[j];
    }
    B[i] = '\0';
    
    cout<<"Reversed String : "<<B;
}

void reverseString2(char A[])          //function for reversing the string using method-1
{
    int t,j;                           // t - temporary character for swapping
    
    for(j=0;A[j]!='\0';j++)         //   '\0' -> null character
    {
    }
    j = j-1;                       // j -> length of the array and j-1 -> last index of the array of characters (or)a string

    for(int i=0;i<j;i++,j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    
    cout<<"Reversed String : "<<A;
}

int main() 
{
    char str1[] = "WELCOME#123";
    
    reverseString2(str1);
}