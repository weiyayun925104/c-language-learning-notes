#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack stack_create(void);
void stack_destroy(Stack s);
void stack_make_empty(Stack s);
bool stack_is_empty(Stack s);
bool stack_is_full(Stack s);
void stack_push(Stack s, Item i);
Item stack_pop(Stack s);
Item stack_peek(Stack s);
int stack_length(Stack s);

#endif
