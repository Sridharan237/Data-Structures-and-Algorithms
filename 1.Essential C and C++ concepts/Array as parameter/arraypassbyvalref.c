#include<stdio.h>

 fun1(int val);
 fun2(int *ref,int size);

int main(){
   int a[5];

   for(int i=0;i<5;i++){
       scanf("%d",&a[i]);
   }

   fun1(a[3]);
   fun2(a,5);

}

 fun1(int val){    //function for call/pass by value in array
    printf("%d\n",val);
}

fun2(int *ref,int size){     //function for call/pass by reference in array
    for(int i=0;i<size;i++){
        printf("%d ",ref[i]);
    }
}
