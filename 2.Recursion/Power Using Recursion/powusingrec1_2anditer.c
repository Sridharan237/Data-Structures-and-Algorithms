//power using recursive function - 1, 2 and using iteration
#include<stdio.h>
//recursion 1
int power1(int m,int n)           //pow()- is a built in math function to calculate power => pow(a,b) = a to the power of b
{
    if(n==0)
       return 1;
    return power1(m,n-1)*m;
}
//recursion 2
int power2(int m,int n)
{
    if(n==0)
       return 1;
    if(n%2==0)
       return power2(m*m,n/2);
    return m*power2(m*m,(n-1)/2);
}

//iterative function - function using loop
int powI(int m,int n)
{
    int p=1,i;
    
    for(i=1;i<=n;i++)
       p=p*m;
    return p;
}
int main()
{
    int r1,r2,r3;
    r1=power1(2,9);
    r2=power2(2,9);
    r3=powI(2,9);
    printf("Power using recursion1 : %d\n",r1);
    printf("Power using recursion2 : %d\n",r2);
    printf("Power using iteration : %d\n",r3);
    return 0;
}