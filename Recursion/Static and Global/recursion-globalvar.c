#include<stdio.h>

int x=0;                                    //global variables - used in recursion

int fun(int n)                              
{                                          //single copy of the global variable is created inside code section
    if(n>0)
    {
        x++;                               
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int a=5;
    int result=fun(a);

    printf("Sum of natural numbers until %d is : %d",a,result);
}