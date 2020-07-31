
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node
{
    Item data;
    struct node *next;
};

struct queue_type
{
    struct node *head;
    struct node *tail;
    int items;
};

static void queue_underflow(Queue q)
{
    printf("Error: queue empty\n");
    exit(EXIT_FAILURE);
}

static void queue_overflow(Queue q)
{
    printf("Error: queue full\n");
    exit(EXIT_FAILURE);
}

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(void)
{
    Queue q = malloc ( sizeof(struct queue_type) );
    if (q == NULL)
    {
        terminate("Error in create: queue could not be created.");
    }
    q->head = NULL;
    q->tail = NULL;
    q->items = 0;

    return q;
}

void queue_destroy(Queue q)
{
    queue_make_empty(q);
    free(q);
}

void queue_make_empty(Queue q)
{
    while ( !queue_is_empty(q) )
    {
        queue_remove_head(q);
    }
}

bool queue_is_empty(Queue q)
{
    return q->items == 0;
}

bool queue_is_full(Queue q)
{
    return false;
}

void queue_append_tail(Queue q, Item i)
{
    struct node *new_node = malloc( sizeof(struct node) );
    if (new_node == NULL)
    {
        terminate("Error in append tail: queue is full.");
    }
    new_node->data = i;
    new_node->next = NULL;

    if (q->items == 0)
    {
        q->head = q->tail = new_node;
    }
    else
    {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->items++;
}

void queue_remove_head(Queue q)
{
    struct node *old_head;

    if ( queue_is_empty(q) )
    {
        queue_underflow(q);
    }
    else
    {
        old_head = q->head;
        q->head = q->head->next;
        q->items--;
        if (q->items == 0)
        {
            q->head = q->tail = NULL;
        }
        free(old_head);
    }
}

Item queue_get_first(Queue q)
{
    if ( queue_is_empty(q) )
    {
        queue_underflow(q);
    }
    else
    {
        return q->head->data;
    }
}

Item queue_get_last(Queue q)
{
    if ( queue_is_empty(q) )
    {
        queue_underflow(q);
    }
    else
    {
        return q->tail->data;
    }
}
