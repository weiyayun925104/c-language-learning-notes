#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv)
{
    char c, d;
    Stack s = stack_create (8);

    printf("Enter parentheses and/or braces: ");

    while ( (c = getchar()) != '\n' )
    {
        if (c == '}' && stack_pop(s) != '{')
        {
            printf("Parentheses/braces are not nested properly\n");
            return 0;
        }
        else if (c == ')' && stack_pop(s) != '(')
        {
            printf("Parentheses/braces are not nested properly\n");
            return 0;
        }
        else if (c == '(' || c == '{')
        {
            stack_push(s, c);
        }
    }

    if ( !stack_is_empty(s) )
    {
        printf("Parentheses/braces are not nested properly\n");
        stack_destroy(s);
        return 0;
    }

    printf("Parentheses/braces are nested properly\n");
    stack_destroy(s);
    return 0;
}
