//program to find multiple missing elements in an unsorted array (using hashing - simple hashing)
#include<stdio.h>
#include<stdlib.h>

struct Array         // Array - structure 
{
    int * A;        //A - pointer to the array
    int n;          //n - size of the array
    int *H;
};

int minElement(int A[], int size)               //--->     int[] A (or)   int A[]     (or)    int * A
{
    int min = A[0];

    for(int i=1;i<size;i++)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }

    return min;
}

int maxElement(int A[], int size)               //--->     int[] A (or)   int A[]     (or)    int * A
{
    int max = A[0];

    for(int i=1;i<size;i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }

    return max;
}

void findMultipleMissUnsortedArray(struct Array s1, int low, int high)
{
     for(int i=0;i<s1.n;i++)           // making the elements which are found as 1
     {
        s1.H[s1.A[i]] = 1;
     }

     for(int i=low;i<high;i++)
     {
        if(s1.H[i] == 0)
        {
            printf("Missing element : %d", i);     // here, i - index is the element which is not found
        }
     }
}

int main()
{
    struct Array s;

    printf("Enter the number of the elements of the array : ");
    scanf("%d", &s.n);
    
    s.A = (int *)malloc(s.n * sizeof(int));
    
    printf("Enter the elements of the array : ");
    
    for(int i=0;i<s.n;i++)
    {
        scanf("%d", &s.A[i]);
    }
    
    int l,h;
                                                         
    l = minElement(s.A, s.n);                         //l - low (minimum value)
    h = maxElement(s.A, s.n);                         //h - high (maximum value)

    s.H = (int *)malloc(h * sizeof(int));             // Hashing Array (or) Hash Array (or) Simple Hash Table
 
    s.H[0] = 0;                                       // intializing all the values in the hash table (hash array) as 0

    findMultipleMissUnsortedArray(s, l, h);
    
    return 0;
}