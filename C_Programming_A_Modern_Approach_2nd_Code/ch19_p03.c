#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv)
{
    Stack s1, s2;
    int n;

    s1 = stack_create();
    s2 = stack_create();

    stack_push(s1, 1);
    printf("stack s1 length: %d\n", stack_length(s1) );
    stack_push(s1, 2);
    printf("stack s1 length: %d\n", stack_length(s1) );

    n = stack_pop(s1);
    printf ("popped %d from s1\n", n);
    printf("stack s1 length: %d\n", stack_length(s1) );
    stack_push(s2, n);
    printf("stack s2 length: %d\n", stack_length(s2) );
    n = stack_pop(s1);
    printf("popped %d from s1\n", n);
    printf("stack s1 length: %d\n", stack_length(s1) );
    stack_push(s2, n);
    printf("stack s2 length: %d\n", stack_length(s2) );


    stack_destroy(s1);

    while ( !stack_is_empty(s2) )
    {
        printf("Popped %d from s2\n", stack_pop(s2) );
        printf("stack s2 length: %d\n", stack_length(s2) );

    }
    stack_push(s2, 3);
    printf("stack s2 length: %d\n", stack_length(s2) );
    stack_make_empty(s2);
    printf("stack s2 length: %d\n", stack_length(s2) );
    if ( stack_is_empty(s2) )
    {
        printf ("s2 is empty\n");
    }
    else
    {
        printf ("s2 is not empty\n");
    }

    stack_destroy(s2);

    return 0;
}
