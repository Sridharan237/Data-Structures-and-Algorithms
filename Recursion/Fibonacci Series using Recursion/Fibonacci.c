#include<stdio.h>

Fibonacci(int n);

main(){
   int n;
   scanf("%d",&n);

   Fibonacci(n);
}

Fibonacci(int n){
    int first=0,second=1;
    if(n>=1)
       printf("%d\n",first);
    if(n>=2)
       printf("%d\n",second);
    if(n>2){
       int temp;

       for(int i=3;i<=n;i++){
           temp = first + second;
           printf("%d\n",temp);
           first=second;
           second=temp;
       }
    }
}
