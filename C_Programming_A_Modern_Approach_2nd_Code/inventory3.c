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
};

struct part *inventory = NULL;

int max_parts = 10;
int num_parts = 0;

void quicksort(struct part a[], int low, int high);
int split(struct part a[], int low, int high);

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void change_price(void);
void quit (void);

int main(int argc, char **argv)
{
    char code;
    if ( (inventory = malloc(max_parts * sizeof(struct part) ) ) == NULL )
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

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
int find_part(int number)
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
void insert(void)
{
    int part_number;

    if (num_parts == max_parts)
    {
        struct part *newinventory = NULL;
        int max = (max_parts * 2);
        if ( ( newinventory = realloc( inventory, sizeof(struct part) * max ) ) == NULL )
        {
            printf("Error: realloc failed\n");
            exit(EXIT_FAILURE);
        }
        inventory = newinventory;
        max_parts = max;
    }

    printf ("Enter part number: ");
    scanf (" %d", &part_number);
    if (find_part (part_number) >= 0)
    {
        printf ("Part already exists.\n");
        return;
    }
    inventory[num_parts].number = part_number;
    printf ("Enter part name: ");
    read_line (inventory[num_parts].name, NAME_LEN);
    printf ("Enter quantity on hand: ");
    scanf (" %d", &inventory[num_parts].on_hand);
    printf ("Enter price: ");
    scanf(" %lf", &inventory[num_parts].price);

    num_parts++;
}
void search(void)
{
    int i, number;

    printf ("Enter part number: ");
    scanf (" %d", &number);
    i = find_part (number);
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
void update(void)
{
    int i, number, change;

    printf ("Enter part number: ");
    scanf (" %d", &number);
    i = find_part (number);
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
void change_price (void)
{
    int i, number;
    printf ("Enter part number: ");
    scanf (" %d", &number);
    i = find_part (number);
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
void print (void)
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
void quit (void)
{
    if (inventory != NULL)
    {
        free (inventory);
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
