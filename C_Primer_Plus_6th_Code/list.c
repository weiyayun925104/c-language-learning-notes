/* list.c -- 支持链表操作的函数 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode (Item item, Node * pnode);

void InitializeList (List * plist)
{
    plist->head = NULL;
    plist->size = 0;
}
bool ListIsEmpty (const List * plist)
{
    if (plist->head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ListIsFull (const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *) malloc ( sizeof (Node) );
    if (pt == NULL)
    {
        full = true;
    }
    else
    {
        full = false;
        free (pt);
    }

    return full;
}
int ListItemCount (const List * plist)
{
    return plist->size;
}
bool AddItem (Item item, List * plist)
{
    Node * pnew;
    Node * scan = plist->head;

    pnew = (Node *) malloc ( sizeof (Node) );
    if (pnew == NULL)
    {
        return false;
    }
    CopyToNode (item, pnew);
    pnew->next = NULL;
    if (scan == NULL)
    {
        plist->head = pnew;
        plist->size = 1;
    }
    else
    {
        while (scan->next != NULL)
        {
            scan = scan->next;
        }
        scan->next = pnew;
        plist->size++;
    }

    return true;
}
void Traverse (const List * plist, void (*pfun) (Item item) )
{
    Node * pnode = plist->head;

    while (pnode != NULL)
    {
        (*pfun) (pnode->item);
        pnode = pnode->next;
    }
}
void EmptyTheList (List * plist)
{
    Node * next;
    Node * scan = plist->head;

    while ( scan != NULL )
    {
        next = scan->next;
        free (scan);
        scan = next;
    }
    plist->head = NULL;
    plist->size = 0;
}
static void CopyToNode (Item item, Node * pnode)
{
    pnode->item = item;
}
