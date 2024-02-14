//program to check whether palindrome or not 
#include<iostream>

using namespace std;

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

char* reverseString1(char A[])          //function for reversing the string using method-1
{
    char * B;                          // another character array to store the reverse string
    int i,j;
    
    for(j=0;A[j]!='\0';j++)         //   '\0' -> null character
    {
    }
    j = j-1;                       // j -> length of the array and j-1 -> last index of the array of characters (or)a string
    
    A = toUpperCase(A);

    for(i=0;j>=0;i++,j--)
    {
        B[i] = A[j];
    }
    B[i] = '\0';
    
    return B;
}

void palindrome1(char A[])          //function for reversing the string using method-1
{
   
    A = toUpperCase(A);
    
    char B[10];                          // another character array to store the reverse string
    int i,j;



//code for reversing the string


    for(j=0;A[j]!='\0';j++)         //   '\0' -> null character
    {
        
    }
    j = j-1;                       // j -> length of the array and j-1 -> last index of the array of characters (or)a string

    for(i=0;j>=0;i++,j--)
    {
        B[i] = A[j];
    }
    B[i] = '\0';
    

//until this is the code for reversing the given string



    for(i=0;A[i]!='\0'&&B[i]!='\0';i++)
    {
           if(A[i] != B[i])
              break;
    }


    if(A[i] == B[i])
        cout<<"palindrome\n";
    else
        cout<<"Not palindrome\n";
}

void palindrome2(char A[])          //function for reversing the string using method-1
{
    int i, j;
    
    for(j=0;A[j]!='\0';j++)         //   '\0' -> null character
    {
    }
    j = j-1;                       // j -> length of the array and j-1 -> last index of the array of characters (or)a string

    for(i=0;i<j;i++,j--)
    {
        if(A[i] != A[j])
            break;
    }
    
    if(A[i]==A[j])
        cout<<"palindrome\n";
    else
        cout<<"Not palindrome\n";
}

int main() 
{
    char str1[] = "mahat";
    
    palindrome1(str1);
    palindrome2(str1);
}
