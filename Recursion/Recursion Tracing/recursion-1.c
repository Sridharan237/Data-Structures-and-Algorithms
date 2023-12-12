#include<stdio.h>

void fun(int n)                       //tail recursion
{
    if(n>0)
    {
        printf("%d ",n);
        fun(n-1);
    }
}

int main()
{
    int x=3;

    fun(x);
    return 1;
}