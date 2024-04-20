// c program to convert an expression from infix to postfix using stack method-1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stackchararray.h"     // including custom header file - stack - character

// function to check whether the given character is operand or not
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else 
        return 1;
}

// function to find the precedence of the given operator
int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

// function to convert infix expression to postfix expression
char* convert(char *infix)
{
    char *postfix;

    int len = strlen(infix);

    postfix = (char *)malloc((len+1)*sizeof(char));

    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(isEmpty())
                push(infix[i++]);
            else if(precedence(infix[i]) > precedence(stackTop()))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }

    while(!isEmpty())
        postfix[j++] = pop();
    
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "a+b*c";

    char *postfix = convert(infix);

    printf("Postfix : %s\n", postfix);
}