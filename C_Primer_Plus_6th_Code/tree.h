/* tree.h -- ¶þ²æ²éÕÒÊ÷ */

#ifndef TREE_H_
#define TREE_H_

#include <stdbool.h>

#define STRLEN 128

typedef struct item
{
    char word[STRLEN];
    int count;
} Item;

#define MAXITEMS 100000

typedef struct trnode
{
    Item item;
    struct trnode * left;
    struct trnode * right;
} Trnode;

typedef struct tree
{
    Trnode * root;
    int size;
} Tree;

void InitializeTree (Tree * ptree);
bool TreeIsEmpty (const Tree * ptree);
bool TreeIsFull (const Tree * ptree);
int TreeItemCount (const Tree * ptree);
bool AddItem (const Item * pitem, Tree * ptree);
bool InTree (const Item * pitem, const Tree * ptree);
bool DeleteItem (const Item *pitem, Tree * ptree);
void Traverse (const Tree * ptree, void (*pfun) (Item item) );
void DeleteAll (Tree * ptree);
Item * FindItem (const Item * pitem, const Tree * ptree);

#endif
