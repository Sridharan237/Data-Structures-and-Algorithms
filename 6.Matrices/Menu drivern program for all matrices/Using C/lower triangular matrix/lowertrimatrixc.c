//Menu driven c program for diagonal matrix

#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int * A;
    int n;              //no. of elements in the array
};

int* Create(int n)
{
    int * A, x;

    A = (int*)malloc(n*(n+1)/2*sizeof(int));

    printf("Enter the Elements :\n");

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d", &x);

            if(i >= j)
            {
                A[n*(j-1) -(j-2)*(j-1)/2 + (i-j)] = x;
            }
        }
    }

    return A;
}

void Set(struct Matrix * ltm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i >= j)
    {
        ltm->A[ltm->n*(j-1) -(j-2)*(j-1)/2 + (i-j)] = x;
    }
}

int Get(struct Matrix ltm, int i, int j)
{
    if(i >= j)
        return ltm.A[ltm.n*(j-1) -(j-2)*(j-1)/2 + (i-j)];
    else 
        return 0;
}

void Display(struct Matrix ltm)
{
    int i, j;

    for(i=1;i<=ltm.n;i++)
    {
        for(j=1;j<=ltm.n;j++)
        {
            if(i >= j)
                printf("%d ", ltm.A[ltm.n*(j-1) -(j-2)*(j-1)/2 + (i-j)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void main()
{
    struct Matrix ltm;

    int choice, i, j, x;

    do
    {
        //Display Menu
        printf("\nxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("x\tMenu          x\n");
        printf("xxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("\t1.Create\n");
        printf("\t2.Set\n");
        printf("\t3.Get\n");
        printf("\t4.Display\n");
        printf("\t5.Exit\n");
        printf("xxxxxxxxxxxxxxxxxxxxxxx\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1://create
                printf("Enter the dimension : ");
                scanf("%d", &ltm.n);
                
                ltm.A = Create(ltm.n);
                
                break;

            case 2://set

                printf("Enter the row number, column number, element : ");
                scanf("%d %d %d", &i, &j, &x);

                Set(&ltm, i, j, x);
                
                break;
            
            case 3://get

                printf("Enter the row number, column number : ");
                scanf("%d %d", &i, &j);

                printf("Element : %d\n", Get(ltm, i, j));
                printf("\n");

                break;

            case 4://display
                Display(ltm);

                break;
        }

        // important :- break will only break the switch case otherwise it will check every other cases also, but it will not break the do while loop
    }while(choice<5);
}