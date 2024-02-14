#include<stdio.h>

int fun(int n)                              //recursive function-static variables
{ 
    static int x=0;                         //single copy of the static variable is created inside code section

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