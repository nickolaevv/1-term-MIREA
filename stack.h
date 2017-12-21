#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *massive;
    int top;
    int size;
}
SS;

void init(SS *stack, int size)
{
    stack->top = -1;
    stack->size = size;
    stack->massive = (int*) malloc(sizeof(int) * size);

    if( stack->massive == NULL)
        {
            printf("Error\n");
            exit(EXIT_FAILURE);
        }
}

int pop(SS *stack)
{
    if(stack->top < 0)
        printf("Empty \n");
    int num =  stack->massive[stack->top];
    stack->top--;
    return num;
}

void push(SS *stack, int index)
{
    if(stack->top >= stack->size - 1)
        printf("Full\n");
    stack->top++;
    stack->massive[stack->top] = index;
}

