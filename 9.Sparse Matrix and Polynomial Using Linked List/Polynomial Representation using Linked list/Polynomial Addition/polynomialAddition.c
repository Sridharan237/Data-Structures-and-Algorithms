// c program to add two polynomials using Linked List Representation
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
struct Node* Create(struct Node* poly)  // poly - Head (or) first pointer of polynomial linked list
{
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
        if(p->next == NULL)
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

// function to add two polynomials
struct Node* addPolynomials(struct Node *p, struct Node *q)
{
    struct Node *sumPoly = NULL;   // pointer to the first (or) head node of the added polynomial linked list
    struct Node *t, *last = NULL;

    while(p != NULL && q != NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        
        t->next = NULL;

        if(p->exp == q->exp)
        {
            t->coeff = p->coeff + q->coeff;
            t->exp = p->exp;

            p = p->next;
            q = q->next;
        }
        else if(p->exp > q->exp)
        {
            t->coeff = p->coeff;
            t->exp = p->exp;

            p = p->next;
        }
        else if(q->exp > p->exp)    // q->exp will be greater than p->exp
        {
            t->coeff = q->coeff;
            t->exp = q->exp;

            q = q->next;
        }

        // Connecting the created node to the sumPoly the result
        if(sumPoly == NULL)
            sumPoly = last = t;
        else
        {
            last->next = t;
            last = t;
        }
    }

    if(p != NULL)
        last->next = p;
    else if(q != NULL)
        last->next = q;

    return sumPoly;
}

int main()
{
    struct Node* poly1 = Create(poly1);

    struct Node* poly2 = Create(poly2);

    // poly3 = poly1 + poly2
    struct Node* poly3 = addPolynomials(poly1, poly2);

    Display(poly3);
}