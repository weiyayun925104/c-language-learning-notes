#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue queue_create(void);
void queue_destroy(Queue q);
void queue_make_empty(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);

void queue_append_tail(Queue q, Item i);
void queue_remove_head(Queue q);
Item queue_get_first(Queue q);
Item queue_get_last(Queue q);

#endif
