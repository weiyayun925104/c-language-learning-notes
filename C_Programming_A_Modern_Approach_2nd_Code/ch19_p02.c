#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main(int argc, char **argv)
{
    char c;
    int op1, op2;
    Stack s = stack_create (8);

    while(true)
    {
        printf("Enter an RPN expression: ");

        while ( (c = getchar()) != '\n' )
        {
            if (isdigit(c))
            {
                stack_push(s, (c - '0') );
            }
            else
            {
                switch(c)
                {
                case '+':
                    stack_push(s, ( stack_pop(s) + stack_pop(s) ) );
                    break;
                case '-':
                    op2 = stack_pop(s);
                    op1 = stack_pop(s);
                    stack_push(s, (op1 - op2) );
                    break;
                case '*':
                    stack_push(s, ( stack_pop(s) * stack_pop(s) ) );
                    break;
                case '/':
                    op2 = stack_pop(s);
                    op1 = stack_pop(s);
                    stack_push(s, (op1 / op2) );
                    break;
                case '=':
                    printf("Value of expression: %d\n", stack_pop(s));
                    break;
                case ' ':
                    break;
                default:
                    stack_destroy(s);
                    exit(EXIT_FAILURE);
                    break;
                }
            }
        }
        stack_make_empty(s);
    }
    stack_destroy(s);
}

