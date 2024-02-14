#include<stdio.h>

double e(int x,int n)
{
     double s=1;
     int i;
     double numer=1,denom=1;

     for(i=1;i<=n;i++)
     {
        numer*=x;
        denom*=i;
        s+=numer/denom;
     }
     return s;
}

int main()
{
    printf("%lf ",e(1,10));
}