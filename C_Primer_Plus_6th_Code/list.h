/* list.h -- 简单链表类型的头文件 */

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#define TSIZE 128

struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct list
{
    Node * head;
    int size;
} List;

void InitializeList (List * plist);
bool ListIsEmpty (const List * plist);
bool ListIsFull (const List * plist);
int ListItemCount (const List * plist);
bool AddItem (Item item, List * plist);
void Traverse (const List * plist, void (*pfun) (Item item) );
void EmptyTheList (List * plist);

#endif
