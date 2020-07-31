#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "stack.h"

int main(int argc, char **argv)
{
    char c;
    int op1, op2;

    while(true)
    {
        printf("Enter an RPN expression: ");

        while ( (c = getchar()) != '\n' )
        {
            if (isdigit(c))
            {
                push( (c - '0') );
            }
            else
            {
                switch(c)
                {
                case '+':
                    push( ( pop() + pop() ) );
                    break;
                case '-':
                    op2 = pop();
                    op1 = pop();
                    push( (op1 - op2) );
                    break;
                case '*':
                    push( ( pop() * pop() ) );
                    break;
                case '/':
                    op2 = pop();
                    op1 = pop();
                    push( (op1 / op2) );
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop());
                    break;
                case ' ':
                    break;
                default:
                    exit(EXIT_FAILURE);
                    break;
                }
            }
        }
    }
}
