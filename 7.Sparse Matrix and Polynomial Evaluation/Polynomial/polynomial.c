//C program for creating, displaying and adding polynomials

#include<stdio.h>
#include<stdlib.h>

struct Term
{
    int coefficient;
    int exponent;
};

struct Polynomial 
{
    int n;  //n-no. of terms
    struct Term * terms;    //to allocate memory in heap and point to it
};

void create(struct Polynomial* p)
{
    int i;

    printf("Enter the no. of terms : ");
    scanf("%d", &p->n);

    p->terms = (struct Term *)malloc(p->n*sizeof(struct Term));

    printf("Enter all the terms of the polynomial : \n");

    for(i=0;i<p->n;i++)
    {
        scanf("%d%d", &p->terms[i].coefficient, &p->terms[i].exponent);
    }
}

struct Polynomial* add(struct Polynomial * p1, struct Polynomial* p2)
{
    struct Polynomial* sum;

    sum = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    
    int i, j, k;

    i=j=k=0;

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exponent > p2->terms[j].exponent)
            sum->terms[k++] = p1->terms[i++];
        else if(p2->terms[j].exponent > p1->terms[i].exponent)
            sum->terms[k++] = p2->terms[j++];
        else 
        {
            sum->terms[k] = p1->terms[i];
            sum->terms[k++].coefficient = p1->terms[i++].coefficient + p2->terms[j++].coefficient;
        }
    }

    for(;i<p1->n;i++) sum->terms[k++] = p1->terms[i];
    for(;j<p2->n;j++) sum->terms[k++] = p2->terms[j];

    sum->n = k;

    return sum;
}

void display(struct Polynomial p)
{
    int i;

    printf("Polynomial is : \n");

    for(i=0;i<p.n;i++)
    {
        if(i==0)
            printf("%dx%d", p.terms[i].coefficient, p.terms[i].exponent);
        else
            printf(" + %dx%d", p.terms[i].coefficient, p.terms[i].exponent);
    }
}

int main()
{
    struct Polynomial p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    display(*p3);
}