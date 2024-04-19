// c program to create, display a stack and perform various operations on a stack like push, pop, stackTop, isEmpty, isFull
#include<stdio.h>
#include<stdlib.h>

struct Stack 
{
    int size;
    int top;
    int *array;
};

void create(struct Stack *st)
{
    printf("Enter the size of stack : ");
    scanf("%d", &st->size);

    st->top = -1;

    st->array = (int *)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
    int i;

    for(i=st.top;i>=0;i--)
    {
        printf("%d ", st.array[i]);
    }
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size-1)
        printf("\nstack overflow\n");
    else
    {
        st->top++;

        st->array[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if(st->top == -1)
        printf("stack underflow");
    else
    {
        x = st->array[st->top];

        st->top--;
    }

    return x;
}

int stackTop(struct Stack st)
{
    int x = -1;

    if(st.top == -1)
        printf("\nstack underflow\n");
    else
        x = st.array[st.top];
    
    return x;
}

int isEmpty(struct Stack st)    // specifying the condition in the return statement will return 1 (or) 0 based on the condition is true (or) false respectively
{
    return st.top == -1;
}

int isFull(struct Stack st)
{
    return st.top == st.size-1;
}

int main()
{
    struct Stack st;

    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    
    printf("Popped element : %d\n", pop(&st));

    printf("Stack Top element : %d\n", stackTop(st));

    printf("isEmpty : %d\n", isEmpty(st));

    printf("isFull : %d\n", isFull(st));

    display(st);
}