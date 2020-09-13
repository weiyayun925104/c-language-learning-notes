#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node
{
    Item data;
    struct node *next;
};

struct stack_type {
struct node *top;
int len;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack stack_create (void)
{
    Stack s = malloc ( sizeof(struct stack_type) );
    if (s == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }
    s->top = NULL;
    s->len = 0;
    return s;
}

void stack_destroy(Stack s)
{
    stack_make_empty(s);
    free(s);
}

void stack_make_empty(Stack s)
{
    while ( !stack_is_empty(s) )
    {
        stack_pop(s);
    }
}

bool stack_is_empty(Stack s)
{
    return s->top == NULL;
}

bool stack_is_full(Stack s)
{
    return false;
}

void stack_push(Stack s, Item i)
{
    struct node *new_node = malloc( sizeof(struct node) );
    if (new_node == NULL)
    {
        terminate("Error in push: stack is full.");
    }
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
    s->len++;
}

Item stack_pop(Stack s)
{
    struct node *old_top;
    Item i;

    if ( stack_is_empty(s) )
    {
        terminate("Error in pop: stack is empty.");
    }

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    s->len--;

    return i;
}

Item stack_peek(Stack s)
{
    if ( stack_is_empty(s) )
    {
        terminate("Error in peek: stack is empty.");
    }
    return s->top->data;
}

int stack_length(Stack s)
{
    return s->len;
}
