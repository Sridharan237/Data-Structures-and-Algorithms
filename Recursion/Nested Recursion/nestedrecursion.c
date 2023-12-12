#include<stdio.h>

int fun(int n)
{
    if(n>100)
       return n-10;                    //In this program containing functions returns some value then the function ends
    return fun(fun(n+11));
}

int main()
{
    int result;
    
    result=fun(95);
    printf("%d",result);
}