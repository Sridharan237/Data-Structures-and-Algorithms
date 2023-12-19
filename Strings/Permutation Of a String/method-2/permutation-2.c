//permutation of a string using method - 1
#include<stdio.h>

void swap(char *, char *);              //function for swapping in their respective addresses
void permutate(char [], int, int);          // function header (or) signature (or) prototype (or) declaration

void main()
{
    char s[] = "ABC";
    
    int size;
    size = sizeof(s)/sizeof(s[0]);

    printf("size of the string \"%s\" is : %d bytes\n", s, size);
    printf("Permutations of the string \"%s\" is : \n", s);
    permutate(s, 0, size-2);
}

void swap(char * p1, char * p2)
{
    char temp;
    
    temp = *p1;
    *p1  = *p2;
    *p2 = temp;
}

void permutate(char s[], int l, int h)         // l - low (minimum index), h - high (maximum index)
{
    if(l == h)
    {
        printf("%s\n", s);
    }
    else
    {
        int i;

        for(i=l;i<=h;i++)
        {
            swap(&s[l], &s[i]);
            permutate(s, l+1, h);
            swap(&s[l], &s[i]);
        }
    }
}