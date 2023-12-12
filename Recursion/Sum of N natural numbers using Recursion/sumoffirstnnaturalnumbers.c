//sum of first n natural numbers - using loop or recursion
#include<stdio.h>
//sum of first n natural numbers - using recursion
int sumR(int n)
{
     if(n==0)
       return 0;
     return sumR(n-1)+n;
}

//sum of first n natural numbers - using loop 
int sumI(int n)
{
    int i,sum=0;
    
    for(i=0;i<=n;i++)
    sum += i;
    return sum;
}
int main()
{
    int x;
    printf("Enter the last number :");
    scanf("%d",&x);
    
    printf("Sum using recursion : %d\n",sumR(x));
    printf("Sum using iteration : %d\n",sumI(x));
}