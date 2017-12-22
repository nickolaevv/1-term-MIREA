#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
int main(int argc, char **argv)
{
    SS *stack = (SS*)malloc(sizeof(SS));
    init(stack,argc);
    int i,j;
    i = 0;
    j = 0;

    for(i = 1; i < argc; ++i)
        {
            if(scanf(argv[i],"%f",&j) > 0)
                push(stack,atof(argv[i]));
            else
                {
                    if(*argv[i] == '+')
                        {
                            push(stack,pop(stack) + pop(stack));
                        }

                    else if(*argv[i] == '-')
                        {
                            j = pop(stack);
                            push(stack, pop(stack) - j);}
                    else if(*argv[i] == '*')
                        {
                            push(stack,pop(stack) * pop(stack));
                        }

                    else if(*argv[i] == '/')
                        {
                            j = pop(stack);
                            push(stack, pop(stack) / j);
                        }


                }
        }

    printf("%.3g\n",stack->massive[stack->top]);
    free(stack->massive);
    free(stack);

    return 0;
}
