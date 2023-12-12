#include"stdio.h"

void fun(int n)                       //head recursion
{
    if(n>0)
    {
        fun(n-1);
        printf("%d ",n);
    }
}

int main()
{
    int x=3;

    fun(x);
    return 1;
}