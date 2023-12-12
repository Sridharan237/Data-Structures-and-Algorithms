//Factorial using recursion and iteration
#include<stdio.h>

int fact(int n)
{
    if(n==0)
       return (1);
    return fact(n-1)*n;
}
int Ifact (int n)
{
    int f=1,i;
    
    for(i=1;i<=n;i++)
        f=f*i;
    return (f);
}

int main()
{
    int r1,r2;
    r1=fact(5);
    //r2=Ifact(5);
    printf("Factorial using recursion : %d\n",r1);
    //printf("Factorial using iteration : %d\n",r2);
}