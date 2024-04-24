// c program to evaluate a postfix expression using stack 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stackLL.h"     // including custom header file - stack (int) - using linked list

// function to check whether the given character is operand or not
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else 
        return 1;
}

// function to evaluate a postfix expression
int evaluate(char *postfix)
{
    int i = 0, x1, x2, result;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2 = pop();
            x1 = pop();

            switch(postfix[i])
            {
                case '+':   result = x1 + x2; push(result); break;
                case '-':   result = x1 - x2; push(result); break;
                case '*':   result = x1 * x2; push(result); break;
                case '/':   result = x1 / x2; push(result); break;
            }
        }
    }

    return pop(); 
}

int main()
{
    char postfix[] = "35*62/+";

    printf("Evaluated : %d\n", evaluate(postfix));
}