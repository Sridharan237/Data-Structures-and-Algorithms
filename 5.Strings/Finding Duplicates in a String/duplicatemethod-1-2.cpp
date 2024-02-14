//program to finding duplicates in a string ---> 1)normal method 2)using hash table 3)using bits 
#include<iostream>

using namespace std;

void duplicate1(char A[])          //function for finding duplicates in a string using method-1
{
    int i, j, duplicateCount;

    for(i=0;A[i]!='\0';i++)
    {
        duplicateCount = 0;
        j = i+1;

        while(A[j]!='\0')
        {
            if(A[i] == A[j])
            {
                duplicateCount++;
                A[j] = '0';
            }
            j++;
        }

        if(duplicateCount>1)
        {
            cout<<"Duplicate character : "<<A[j]<<endl;
        }
    }

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

    duplicate1(str1);
}