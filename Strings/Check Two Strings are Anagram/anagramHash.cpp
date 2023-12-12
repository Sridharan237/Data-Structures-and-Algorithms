//program to check anagram or not using hash table
#include<iostream>

using namespace std;

int anagramHash(char A[], char B[])          //function for checking anagram or not using hash table
{
    int i, H[26];

    for(i=0;i<26;i++)                   // for making every values in the hash table as 0
    {
        H[i] = 0;
    }

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97] += 1;
    }

    for(i=0;B[i]!='\0';i++)
    {
        H[B[i]-97] -= 1;
    }
    
    for(int i=0;i<26;i++)
    {
        if(H[i]>0)
        {
            return 0;
        }
    }

    return 1;
}

int main() 
{
    char str1[] = "decimal";
    char str2[] = "medical";
    
    if(anagramHash(str1, str2) == 1)
    {
        cout<<"They are \'Anagram\'";
    }
    else
    {
        cout<<"They are not \'Anagram\'";
    }
}