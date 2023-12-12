//Binary Search 
#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

//iterative version 
int BinarySearch(struct Array arr,int key)              
{
    int l,mid,h;          // l-> low , h->high , and mid -> middle index
    
    l=0,h=arr.length-1;

    while(l<=h)
    {
         mid=(l+h)/2;

        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h = mid-1;
        else
            l=mid+1;
    }

    return -1;
}
//recursive version
int RBinSearch(int a[],int l,int h,int key)
{
    int mid = (l+h)/2;
    if(l<=h)
    {
       if(key==a[mid])
         return mid;
       else if(key<a[mid])
         return RBinSearch(a,l,mid-1,key);
       else
         return RBinSearch(a,mid+1,h,key);
    }
    return -1;
}

int main()
{
    struct Array arr={{2,4,6,8,10},10,5};

    printf("%d\n",RBinSearch(arr.A,0,arr.length-1,6));
}