#include<stdio.h>

int factorial(int n);

int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);

    printf("Factorial is:%d",factorial(n));
}

int factorial(int n){
    if(n==0){
       return 1;
    }
    else{
       return n*factorial(n-1);
    }
}
