//program to check anagram or not 
#include<iostream>

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

int duplicate1(char A[])          //function for finding duplicates in a string using method-1
{
    int i, j, duplicateCount = 0;

    for(i=0;A[i]!='\0';i++)
    {
        j = i+1;

        while(A[j]!='\0')
        {
            if(A[i] == A[j] && A[i] != '0')
            {
                duplicateCount++;
                A[j] = '0';
            }
            j++;
        }
    }
    
    if(duplicateCount>0)
    {
       return duplicateCount; 
    }
    
    return 0;
}

void anagram(char A[], char B[])          //function for checking anagram or not 
{
    int i, j, count = 0, duplicateCountA = 0, duplicateCountB = 0;
    
    int lenOfA = strLength(A);
    int lenOfB = strLength(B);

    if(strLength(A) == strLength(B))
    {
        for(int i=0;A[i]!='\0';i++)
        {
            j = 0;

            while(B[j]!='\0')
            {
                if(A[i] == B[j])
                {
                    count++;
                }
                j++;
            }
        }
    }
    
    duplicateCountA = duplicate1(A);
    duplicateCountB = duplicate1(B);
    
    if(duplicateCountA == duplicateCountB && (count-(duplicateCountA+duplicateCountB)) == lenOfA)
    {
       cout<<"They are \'Anagram\'"; 
    }
    else
    {
        cout<<"They are not \'Anagram\'";
    }

}

int main() 
{
    char str1[] = "verbose";
    char str2[] = "observe";

    anagram(str1, str2);
}