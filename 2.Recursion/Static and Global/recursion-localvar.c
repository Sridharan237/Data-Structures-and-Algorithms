#include<stdio.h>

int fun(int n)                              //recursive function-local variables
{
    if(n>0)
    {
        return fun(n-1)+n;
    }
    return 0;
}

int main()
{
    int x=5;
    int result=fun(x);

    printf("Sum of natural numbers until %d is : %d",result);
}