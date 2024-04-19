// c program to perform parenthesis matching on an expression
#include<stdio.h>
#include<string.h>
#include "stackLL.h"    // including custom header file stack using linked list in c

int isBalanced(char *exp)
{
    int i;

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            if(isEmpty())
                return 0;
            pop();
        }
    }

    if(isEmpty())
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "((a+b)*(c-d))";

    printf("IsBalanced : %d\n", isBalanced(exp));
}