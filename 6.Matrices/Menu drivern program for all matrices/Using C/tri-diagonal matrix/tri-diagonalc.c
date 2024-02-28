//Menu driven c program for tri-diagonal matrix

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

            if(i - j == 1)
            {
            A[i-2] = x;
            }
            else if(i - j == 0)
            {
            A[n-1+i-1] = x;
            }
            else if(i - j == -1)
            {
                A[n-1+n+i-1] = x;
            }
        }
    }

    return A;
}

void Set(struct Matrix * tdm, int i, int j, int x)   // i - row number, j - column number, x - element
{
    if(i - j == 1)
    {
        tdm->A[i-2] = x;
    }
    else if(i - j == 0)
    {
        tdm->A[tdm->n-1+i-1] = x;
    }
    else if(i - j == -1)
    {
        tdm->A[tdm->n-1+tdm->n+i-1] = x;
    }
}

int Get(struct Matrix tdm, int i, int j)
{
    if(i - j == 1)
    {
        return tdm.A[i-2];
    }
    else if(i - j == 0)
    {
        return tdm.A[tdm.n-1+i-1];
    }
    else if(i - j == -1)
    {
        return tdm.A[tdm.n-1+tdm.n+i-1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix tdm)
{
    int i, j;

    for(i=1;i<=tdm.n;i++)
    {
        for(j=1;j<=tdm.n;j++)
        {
            if(i - j == 1)
            {
                printf("%d ", tdm.A[i-2]);
            }   
            else if(i - j == 0)
            {
                printf("%d ", tdm.A[tdm.n-1+i-1]);
            }
            else if(i - j == -1)
            {
                printf("%d ", tdm.A[tdm.n-1+tdm.n+i-1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void main()
{
    struct Matrix tdm;

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
                scanf("%d", &tdm.n);
                
                tdm.A = Create(tdm.n);
                
                break;

            case 2://set

                printf("Enter the row number, column number, element : ");
                scanf("%d %d %d", &i, &j, &x);

                Set(&tdm, i, j, x);
                
                break;
            
            case 3://get

                printf("Enter the row number, column number : ");
                scanf("%d %d", &i, &j);

                printf("Element : %d\n", Get(tdm, i, j));
                printf("\n");

                break;

            case 4://display
                Display(tdm);

                break;
        }

        // important :- break will only break the switch case otherwise it will check every other cases also, but it will not break the do while loop
    }while(choice<5);
}