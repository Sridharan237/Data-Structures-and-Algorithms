// c program to create, display, evaluate a polynomial using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Node structure for Polynomial
struct Node
{
    int coeff;  // coeff - coefficient 
    int exp;    // exp - exponent
    struct Node *next;
};

// function to create to create a polynomial using linked list
struct Node* Create()
{
    struct Node * poly;     // poly - Head (or) first pointer of polynomial linked list

    struct Node *t, *last;  // last - last pointer of polynomial linked list

    int i, n;  // n - no. of terms

    printf("Enter the no. of terms : ");
    scanf("%d", &n);

    printf("Enter Each term's \'Coefficient\' and \'Exponent\' : \n");

    for(i=0;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d %d", &t->coeff, &t->exp);

        t->next = NULL;

        if(poly == NULL)
            poly = last = t;
        else
        {
            last->next = t;
            last = t;
        }
    }

    return poly;
}

// function to display a polynomial
void Display(struct Node *p)
{
    printf("p(x) = ");
    while(p != NULL)
    {
        if(p ->next == NULL)
            printf("%d*x^%d\n", p->coeff, p->exp);
        else
            printf("%d*x^%d + ", p->coeff, p->exp);
            
        p = p->next;
    }
}

// function to evaluate a polynomial 
long Evaluate(struct Node *p, int x)
{
    long sum = 0.0;

    while(p != NULL)
    {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }

    return sum;
}

int main()
{
    struct Node* poly = Create();

    Display(poly);

    printf("Evaluate : p(%d) = %ld", 1, Evaluate(poly, 1));
}