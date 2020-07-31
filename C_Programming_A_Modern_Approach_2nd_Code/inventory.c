/* Maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

void quicksort(struct part a[], int low, int high);
int split(struct part a[], int low, int high);

int find_part(const struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(const struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);
void change_price(struct part inventory[], int num_parts);

int main(int argc, char **argv)
{
    int num_parts = 0;
    struct part inventory[MAX_PARTS];
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
            insert(inventory, &num_parts);
            break;
        case 's':
            search(inventory, num_parts);
            break;
        case 'u':
            update(inventory, num_parts);
            break;
        case 'p':
            print(inventory, num_parts);
            break;
        case 'c':
            change_price(inventory, num_parts);
            break;
        case 'q':
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

int find_part (const struct part inventory[], int num_parts, int number)
{
    int i;
    for (i = 0; i < num_parts; i++)
    {
        if (inventory[i].number == number)
        {
            return i;
        }
    }
    return -1;
}

void insert (struct part inventory[], int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS)
    {
        printf ("Database is full; can't add more parts.\n");
        return;
    }
    printf ("Enter part number: ");
    scanf (" %d", &part_number);
    if (find_part (inventory, *num_parts, part_number) >= 0)
    {
        printf ("Part already exists.\n");
        return;
    }
    inventory[*num_parts].number = part_number;
    printf ("Enter part name: ");
    read_line (inventory[*num_parts].name, NAME_LEN);
    printf ("Enter quantity on hand: ");
    scanf (" %d", &inventory[*num_parts].on_hand);
    printf ("Enter price: ");
    scanf(" %lf", &inventory[*num_parts].price);

    (*num_parts)++;
}
void search (const struct part inventory[], int num_parts)
{
    int i, number;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    i = find_part (inventory, num_parts, number);
    if (i >= 0)
    {
        printf ("Part nane: %s\n", inventory[i].name);
        printf ("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: $%.2f\n", inventory[i].price);
    }
    else
    {
        printf ("Part not found.\n");
    }
}
void update (struct part inventory[], int num_parts)
{
    int i, number, change;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    i = find_part (inventory, num_parts, number);
    if(i >= 0)
    {
        printf ("Enter change in quantity on hand: ");
        scanf (" %d", &change);
        inventory[i].on_hand += change;
    }
    else
    {
        printf ("Part not found.\n");
    }
}
void change_price (struct part inventory[], int num_parts)
{
    int i, number;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    i = find_part (inventory, num_parts, number);
    if (i >= 0)
    {
        printf("Enter new price: ");
        scanf(" %lf", &inventory[i].price);
    }
    else
    {
        printf ("Part not found.\n");
    }
}
void print (struct part inventory[], int num_parts)
{
    int i;
    quicksort(inventory, 0, num_parts - 1);
    printf("Part Number   Part Name                  Quantity on Hand   Price\n");
    for (i = 0; i < num_parts; i++)
    {
        printf("%7d       %-25s%11d          $%7.2f\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand, inventory[i].price);
    }
}

void quicksort(struct part a[], int low, int high)
{
    int middle;

    if (low >= high)
    {
        return;
    }
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(struct part a[], int low, int high)
{
    struct part part_element = a[low];

    for (; ; )
    {
        while (low < high && part_element.number <= a[high].number)
        {
            high--;
        }
        if (low >= high)
        {
            break;
        }
        a[low++] = a[high];

        while (low < high && a[low].number <= part_element.number)
        {
            low++;
        }
        if (low >= high)
        {
            break;
        }
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}
