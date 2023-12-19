//permutation of a string using method - 1
#include<stdio.h>

void permutate(char [], int);          // function header (or) signature (or) prototype (or) declaration

void main()
{
    char s[] = "ABC";
    
    // printf("Permutations of the string %s is : \n", s);
    permutate(s, 0);
}

void permutate(char s[], int k)
{
    static int A[4];
    char static Res[4];

    if(s[k] == '\0')
    {
        Res[k] = s[k];
        printf("%s\n", Res);
    }
    else
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;

                permutate(s, k+1);

                A[i] = 0;
            }
        }
    }
}