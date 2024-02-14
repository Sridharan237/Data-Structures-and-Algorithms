//combination using iteration and completely by recursion

#include<stdio.h>

//combination using normal function and factorial function
int fact(int);      //function prototype (or) function signature (or)  function header
int nCr(int n,int r)
{
    int numer,denom;

    numer=fact(n);
    denom=fact(r)*fact(n-r);

    return numer/denom;
}
int fact(int n)
{
    if(n==0) return 1;
    return fact(n-1)*n;
}

//combination using recursion
int NCR(int n,int r)
{
    if(r==0||n==r) return 1;
    return NCR(n-1,r-1) + NCR(n-1,r);
}

int main()
{
    printf("%d\n",NCR(2,1));
}
