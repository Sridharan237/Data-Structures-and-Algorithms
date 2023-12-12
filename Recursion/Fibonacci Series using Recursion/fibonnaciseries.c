#include<stdio.h>
int main(){
    int n,a=0,b=1,s=0;
    scanf("%d",&n);
    printf("%d,%d,",a,b);
    for(int i=0;i<n;i++){
        s+=b;
        b=s;
        printf("%d,",s);
    }
}
