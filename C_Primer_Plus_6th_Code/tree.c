/* tree.c -- 树的支持函数 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

typedef struct pair
{
    Trnode * parent;
    Trnode * child;
} Pair;

static Trnode * MakeNode(const Item * pitem);
static bool ToLeft (const Item * item1, const Item * item2);
static bool ToRight (const Item * item1, const Item * item2);
static void AddNode (Trnode * new_node, Trnode * root);
static void InOrder (const Trnode * root, void (*pfun) (Item item) );
static Pair SeekItem (const Item * pitem, const Tree * ptree);
static void DeleteNode (Trnode ** ptr);
static void DeleteAllNodes (Trnode * root);

void InitializeTree (Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}
bool TreeIsEmpty (const Tree * ptree)
{
    if (ptree->size <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool TreeIsFull (const Tree * ptree)
{
    if (ptree->size >= MAXITEMS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int TreeItemCount (const Tree * ptree)
{
    return ptree->size;
}
bool AddItem (const Item * pitem, Tree * ptree)
{
    Trnode * new_node;
    Pair look;

    if ( TreeIsFull (ptree) )
    {
        fprintf (stderr, "Tree is full.\n");
        return false;
    }
    if ( ( look = SeekItem(pitem, ptree) ).child != NULL )
    {
        look.child->item.count++;
        return true;
    }
    new_node = MakeNode (pitem);
    if (new_node == NULL)
    {
        fprintf (stderr, "Couldn't create node.\n");
        return false;
    }
    ptree->size++;
    if (ptree->root == NULL)
    {
        ptree->root = new_node;
    }
    else
    {
        AddNode (new_node, ptree->root);
    }

    return true;
}
bool InTree (const Item * pitem, const Tree * ptree)
{
    return ( SeekItem (pitem, ptree).child == NULL) ? false : true;
}
Item * FindItem (const Item * pitem, const Tree * ptree)
{
    Pair look;

    look = SeekItem (pitem, ptree);
    if (look.child == NULL)
    {
        fprintf (stderr, "Can not find item.\n");
        return NULL;
    }
    
    return & (look.child->item);
}
bool DeleteItem (const Item * pitem, Tree * ptree)
{
    Pair look;

    look = SeekItem (pitem, ptree);
    if (look.child == NULL)
    {
        fprintf (stderr, "Can not find item to delete.\n");
        return false;
    }
    if (look.parent == NULL)
    {
        DeleteNode ( & (ptree->root) );
    }
    else if (look.parent->left == look.child)
    {
        DeleteNode ( & (look.parent->left) );
    }
    else
    {
        DeleteNode ( & (look.parent->right) );
    }
    ptree->size--;

    return true;
}
void Traverse (const Tree * ptree, void (*pfun) (Item item) )
{
    if (ptree != NULL)
    {
        InOrder (ptree->root, pfun);
    }
}
void DeleteAll (Tree * ptree)
{
    if (ptree != NULL)
    {
        DeleteAllNodes (ptree->root);
        ptree->root = NULL;
        ptree->size = 0;
    }
}
static void InOrder (const Trnode * root, void (*pfun) (Item item) )
{
    if (root != NULL)
    {
        InOrder (root->left, pfun);
        (*pfun) (root->item);
        InOrder (root->right, pfun);
    }
}
static void DeleteAllNodes (Trnode * root)
{
    Trnode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes (root->left);
        free (root);
        DeleteAllNodes (pright);
    }
}
static void AddNode (Trnode * new_node, Trnode * root)
{
    if ( ToLeft ( &(new_node->item), &(root->item) ) )
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            AddNode (new_node, root->left);
        }
    }
    else if ( ToRight (&(new_node->item), &(root->item) ) )
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            AddNode (new_node, root->right);
        }
    }
    else
    {
        fprintf (stderr, "Error, add duplicate item in AddNode.\n");
        return;
    }
}
static bool ToLeft (const Item * item1, const Item * item2)
{
    int comp1;

    if ( ( comp1 = strcmp (item1->word, item2->word) ) < 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
static bool ToRight (const Item * item1, const Item * item2)
{
    int comp1;

    if ( ( comp1 = strcmp (item1->word, item2->word) ) > 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
static Trnode * MakeNode(const Item * pitem)
{
    Trnode * new_node;

    new_node = (Trnode *) malloc ( sizeof (Trnode) );
    if (new_node != NULL)
    {
        new_node->item = *pitem;
        new_node->item.count = 1;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}
static Pair SeekItem (const Item * pitem, const Tree * ptree)
{
    Pair look;

    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL)
    {
        return look;
    }
    while (look.child != NULL)
    {
        if ( ToLeft (pitem, & (look.child->item) ) )
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if ( ToRight (pitem, & (look.child->item) ) )
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
        {
            break;
        }
    }

    return look;
}
static void DeleteNode (Trnode ** ptr)
{
    Trnode * temp;
    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free (temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free (temp);
    }
    else
    {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
        {
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free (temp);
    }
}
