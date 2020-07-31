#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv)
{
    Stack s1, s2;
    char * str;

    s1 = stack_create();
    s2 = stack_create();

    stack_push(s1, "foo");
    printf("stack s1 length: %d\n", stack_length(s1) );
    stack_push(s1, "bar");
    printf("stack s1 length: %d\n", stack_length(s1) );

    str = stack_pop(s1);
    printf ("popped %s from s1\n", str);
    printf("stack s1 length: %d\n", stack_length(s1) );
    stack_push(s2, str);
    printf("stack s2 length: %d\n", stack_length(s2) );
    str = stack_pop(s1);
    printf("popped %s from s1\n", str);
    printf("stack s1 length: %d\n", stack_length(s1) );
    stack_push(s2, str);
    printf("stack s2 length: %d\n", stack_length(s2) );


    stack_destroy(s1);

    while ( !stack_is_empty(s2) )
    {
        printf("Popped %s from s2\n", stack_pop(s2) );
        printf("stack s2 length: %d\n", stack_length(s2) );

    }
    stack_push(s2, "baz");
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
