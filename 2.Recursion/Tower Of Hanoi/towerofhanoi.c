//Tower of Hanoi

#include<stdio.h>

int i=1;
void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("%d.(%d,%d)\n",i,A,C);
        i++;
        TOH(n-1,B,A,C);
    }
}
int main()
{
    TOH(1,1,2,3);
}