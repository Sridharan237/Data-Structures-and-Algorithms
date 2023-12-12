//Taylor's series using horner's rule using recursion
#include<stdio.h>

double e(int x,int n)
{
    static double s;
    if(n==0)
       return s;
    s=1+(double)x/n*s;                   // (or) s=1+double(x/n)*s   (or) s=1+s*x/n       [s*x --->double , double/int =double , float /int =float]
    return e(x,n-1);
}

int main()
{
    printf("%lf ",e(1,10));
}