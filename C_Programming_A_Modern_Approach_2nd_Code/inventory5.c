/* Maintains a parts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
    struct part *next;
};
struct part *inventory = NULL;

struct part *find_part (int number);
void insert (void);
void search (void);
void update (void);
void print (void);
void change_price (void);
void quit (void);
void erase(void);

int main(int argc, char **argv)
{
    char code;
    for (; ; )
    {
        printf ("Enter operation code: ");
        scanf (" %c", &code);
        while ( getchar() != '\n')
            ;
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'e':
            erase();
            break;
        case 'c':
            change_price();
            break;
        case 'q':
            quit ();
            return 0;
            break;
        default:
            printf ("Illegal code\n") ;
            break;
        }
        printf("\n") ;
    }
    return 0;
}
struct part *(find_part) (int number)
{
    struct part *p;
    for (p = inventory; p != NULL && p->number < number; p = p->next)
        ;
    if (p != NULL && p->number == number)
    {
        return p;
    }
    return NULL;
}
void insert (void)
{
    struct part *cur, *prev, *new_node;
    int part_number;
    printf ("Enter part number: ");
    scanf (" %d", &part_number);
    for (cur = inventory, prev = NULL; cur != NULL && cur->number < part_number; prev = cur, cur = cur->next)
        ;
    if (cur != NULL && cur->number == part_number)
    {
        printf ("Part already exists.\n");
        return;
    }
    new_node = malloc ( sizeof(struct part) );
    if (new_node == NULL)
    {
        printf ("Database is full; can't add more parts.\n");
        return;
    }
    new_node->number = part_number;
    printf ("Enter part name: ");
    read_line (new_node->name, NAME_LEN);
    printf ("Enter quantity on hand: ");
    scanf (" %d", &new_node->on_hand);
    printf ("Enter price: ");
    scanf(" %lf", &new_node->price);

    new_node->next = cur;
    if (prev == NULL)
    {
        inventory = new_node;
    }
    else
    {
        prev->next = new_node;
    }
}
void erase(void)
{
    struct part **list = &inventory;
    struct part *item = inventory;
    int part_number;
    printf ("Enter part number: ");
    scanf (" %d", &part_number);

    while (item != NULL)
    {
        if (item->number == part_number)
        {
            *list = item->next;
            free(item);
            return;
        }
        list = &(item->next);
        item = item->next;
    }

    printf("Part %d not found.\n", part_number);
}
void search (void)
{
    int number;
    struct part *p;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    p = find_part (number);
    if (p != NULL)
    {
        printf ("Part nane: %s\n", p->name);
        printf ("Quantity on hand: %d\n", p->on_hand);
        printf("Price: $%.2f\n", p->price);
    }
    else
    {
        printf ("Part not found.\n");
    }
}
void update (void)
{
    int number, change;
    struct part *p;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    p = find_part (number);
    if (p != NULL)
    {
        printf ("Enter change in quantity on hand: ");
        scanf (" %d", &change);
        p->on_hand += change;
    }
    else
    {
        printf ("Part not found.\n");
    }
}
void change_price (void)
{
    int number;
    struct part *p;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    p = find_part (number);
    if (p != NULL)
    {
        printf("Enter new price: ");
        scanf(" %lf", &(p->price) );
    }
    else
    {
        printf ("Part not found.\n");
    }
}
void quit (void)
{
    struct part *p, *q;
    printf("Part Number   Part Name                  Quantity on Hand   Price\n");
    p = inventory;
    while (p != NULL)
    {
        q = p->next;
        printf("%7d       %-25s%11d          $%7.2f\n", p->number,
               p->name, p->on_hand, p->price);
        free (p);
        p = q;
    }
}
void print (void)
{
    struct part *p;
    printf("Part Number   Part Name                  Quantity on Hand   Price\n");
    for (p = inventory; p != NULL; p = p->next)
    {
        printf("%7d       %-25s%11d          $%7.2f\n", p->number,
               p->name, p->on_hand, p->price);
    }
}
