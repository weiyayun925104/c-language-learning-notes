/* queue.c -- Queue类型的实现 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode (Item item, Node * pnode);
static void CopyToItem (Node * pnode, Item * pitem);

void InitializeQueue (Queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}
bool QueueIsFull (const Queue * pq)
{
    return pq->items == MAXQUEUE;
}
bool QueueIsEmpty (const Queue * pq)
{
    return pq->items == 0;
}
int QueueItemCount (const Queue * pq)
{
    return pq->items;
}
bool EnQueue (Item item, Queue * pq)
{
    Node * pnew;

    if ( QueueIsFull (pq) )
    {
        fprintf (stderr, "Error, queue is full.\n");
        return false;
    }
    pnew = (Node *) malloc ( sizeof (Node) );
    if (pnew == NULL)
    {
        fprintf (stderr, "Error, memory allocation failed.\n");
        return false;
    }
    CopyToNode (item, pnew);
    pnew->next = NULL;
    if ( QueueIsEmpty(pq) )
    {
        pq->front = pnew;
        pq->rear = pnew;
        pq->items = 1;
    }
    else
    {
        pq->rear->next = pnew;
        pq->rear = pnew;
        pq->items++;
    }

    return true;
}
bool DeQueue (Item * pitem, Queue * pq)
{
    Node * temp;

    if ( QueueIsEmpty (pq) )
    {
        return false;
    }
    CopyToItem (pq->front, pitem);
    temp = pq->front;
    pq->front = pq->front->next;
    free (temp);
    pq->items--;
    if (pq->items == 0)
    {
        pq->front = NULL;
        pq->rear = NULL;
    }

    return true;
}
void EmptyTheQueue (Queue * pq)
{
    Item dummy;
    while ( !QueueIsEmpty (pq) )
    {
        DeQueue (&dummy, pq);
    }
}
static void CopyToNode (Item item, Node * pnode)
{
    pnode->item = item;
}
static void CopyToItem (Node * pnode, Item * pitem)
{
    *pitem = pnode->item;
}
