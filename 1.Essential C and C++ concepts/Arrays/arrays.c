#include<stdio.h>

int main()
{
    //ways of declaration and initialization of arrays

    int A[5];
    int B[5]={2,4,6,8,10};
    int C[5]={2,4};
    int D[5]={0};
    int E[]={2,4,6,8,10};

    //ways of accessing elements of an array

    for(int i=0;i<5;i++)                  //accessing using for loop 
        printf("%d ",B[i]);
    
    printf("\n%d\n",B[2]);
    printf("\n%d\n",2[B]);
    printf("\n%d\n",*(B+2));                //accessing using pointer arithmetic
    
}