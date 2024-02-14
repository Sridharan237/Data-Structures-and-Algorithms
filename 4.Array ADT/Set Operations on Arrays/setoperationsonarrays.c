#include<stdio.h>
#include<stdlib.h>

struct Array 
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    
    for(i=0;i<arr.length;i++)
       printf("%d ",arr.A[i]);
}

//Two Unsorted Arrays
struct Array* Unsorted_Union(struct Array * arr1,struct Array * arr2)
{
    struct Array * arr3;
    arr3=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k,flag=0;
    i=j=k=0;

    while(i<arr1->length)
    {
        arr3->A[k++]=arr1->A[i++];
    }
    
    for(j=0;j<arr2->length;j++)
    {
        for(i=0;i<arr1->length;i++)
        {
            if(arr2->A[j]==arr1->A[i])
            {
                flag=1;break;
            }
        }
        if(flag==0)
        {
            arr3->A[k++]=arr2->A[j];
        }
        else if(flag==1)
             flag=0;
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Unsorted_Intersection(struct Array * arr1,struct Array * arr2)
{
    struct Array * arr3;
    arr3=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k,flag=0;
    i=j=k=0;

    for(i=0;i<arr1->length;i++)
    {
        for(j=0;j<arr2->length;j++)
        {
            if(arr1->A[i]==arr2->A[j])
            {
                flag=1;break;
            }
        }
        if(flag==1)
        {
            arr3->A[k++]=arr1->A[i];
            flag=0;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Unsorted_Difference(struct Array * arr1,struct Array * arr2)
{
    struct Array * arr3;
    arr3=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k,flag;
    i=j=k=0;
    flag=0;

    while(i<arr1->length)
    {
         while(j<arr2->length)
         {
            if(arr1->A[i]==arr2->A[j])
            {
                flag=1;break;
            }
            j++;
         }
        
        if(flag==0)
        {
            arr3->A[k++]=arr1->A[i++];
            j=0;
        }
        else if(flag==1)
        {
            i++;
            flag=0;
        }
        j++;
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

void Unsorted_SetMembership(struct Array * arr1,struct Array * arr2)
{
    int i,j,flag,count_length;
    i=0,j=0;
    flag=0,count_length=0;

    while(i<arr1->length)
    {
        while(j<arr2->length)
        {
            if(arr1->A[i]==arr2->A[j])
            {
               flag=1;break;
            }
            j++;
        }
        if(flag==1)
        {
            count_length++;
            flag=0;
        }
        j=0;
        i++;
    }

    if(count_length==arr1->length)
    {
        printf("Array1 is a subset of Array2");
    }
    else
    {
        printf("Array1 is not a subset of Array2");
    }
}

//Two sorted Arrays
struct Array* Union(struct Array * arr1,struct Array * arr2)
{
     int i,j,k;
     i=j=k=0;
     struct Array * arr3;
     arr3=(struct Array*)malloc(sizeof(struct Array));

     while(i<arr1->length && j<arr2->length)
     {
          if(arr1->A[i]<arr2->A[j])
             arr3->A[k++]=arr1->A[i++];
          else if(arr2->A[j]<arr1->A[i])
              arr3->A[k++]=arr2->A[j++];
          else if(arr1->A[i]==arr2->A[j])
          {
            arr3->A[k++]=arr1->A[i++];
            j++;
          }
     }
     for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
          
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=k;
    arr3->size=10;
    
    return arr3;
}

struct Array* Intersection(struct Array * arr1,struct Array * arr2)
{
     int i,j,k;
     i=j=k=0;
     struct Array * arr3;
     arr3=(struct Array*)malloc(sizeof(struct Array));

     while(i<arr1->length && j<arr2->length)
     {
          if(arr1->A[i]<arr2->A[j])
             i++;
          else if(arr2->A[j]<arr1->A[i])
              j++;
          else if(arr1->A[i]==arr2->A[j])
          {
            arr3->A[k++]=arr1->A[i++];
            j++;
          }
     }
     
    arr3->length=k;
    arr3->size=10;
    
    return arr3;
}

struct Array* Difference(struct Array * arr1,struct Array * arr2)
{
      struct Array * arr3;
      arr3=(struct Array *)malloc(sizeof(struct Array));

      int i,j,k;
      i=j=k=0;

      while(i<arr1->length && j<arr2->length)
      {
           if(arr1->A[i]<arr2->A[j])
              arr3->A[k++]=arr1->A[i++];
           else if(arr2->A[j]<arr1->A[i])
              j++;
           else if(arr1->A[i]==arr2->A[j]) 
              i++,j++;
      }

      for(;i<arr1->length;i++)
         arr3->A[k++]=arr1->A[i];

      arr3->length=k;
      arr3->size=10;

      return arr3;
}

void sorted_SetMembership(struct Array * arr1,struct Array * arr2)
{
    int i,j,flag,count_length;
    i=0,j=0;
    count_length=0;

    if(arr1->length <= arr2->length)
    {  
       while(i<arr1->length)
       {
          if(arr1->A[i]<arr2->A[j])
          {
             i++;
          }
          else if(arr2->A[j]<arr1->A[i])
          {
             j++;
          }
          else if(arr1->A[i]==arr2->A[j])
          {
             count_length++;
             i++,j++;
          }
       }
    }
    else
    {
        printf("Array1 is not a subset of Array2");
        return ;
    }

    if(count_length==arr1->length)
    {
        printf("Array1 is a subset of Array2");
    }
    else
    {
        printf("Array1 is not a subset of Array2");
    }

}

int main()
{
    struct Array arr1={{3,5,10},10,3};
    struct Array arr2={{3,5,10,12,20,23},10,6};
    struct Array * arr3;

    sorted_SetMembership(&arr1,&arr2);

    //display(*arr3);
}