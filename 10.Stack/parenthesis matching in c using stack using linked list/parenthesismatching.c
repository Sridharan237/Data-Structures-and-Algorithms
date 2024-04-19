// c program to perform parenthesis matching on an expression but it can match all kinds of brackets like {}, [], ()
#include<stdio.h>
#include<string.h>
#include "stackLL.h"    // including custom header file stack using linked list in c

int isBalanced(char *exp)
{
    int i;

    char x;

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='{' || exp[i] == '[' || exp[i] == '(')
            push(exp[i]);
        else if(exp[i]-1==stackTop() || exp[i]-2==stackTop())  
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
    char *exp = "{[(a+b)*(c-d)]/e";

    printf("IsBalanced : %d\n", isBalanced(exp));
}