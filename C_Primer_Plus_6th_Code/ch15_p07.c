
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define ID_MASK     0xFFUL
#define SIZE_MASK   0x7F00UL
#define LEFT        0x00000UL
#define CENTER      0x08000UL
#define RIGHT       0x10000UL
#define ALIGN_MASK  0x18000UL
#define REGULAR     0x00000UL
#define BOLD        0x20000UL
#define ITALIC      0x40000UL
#define UNDERLINE   0x80000UL
#define STYLE_MASK  0xE0000UL
#define SIZE_SHIFT  8

typedef unsigned long font;

int do_menu(font *f);
int get_choice(const char *);
void show_menu(void);
void show_font(font f);
void eatline(void);
void get_id(font *f);
void get_size(font *f);
void get_align(font *f);

int main(int argc, char **argv)
{
    font sample = 1UL | (12UL << SIZE_SHIFT) | LEFT | REGULAR;

    while (do_menu(&sample) != 'q')
    {
        continue;
    }
    printf ("Done.\n");

    return 0;
}

int do_menu(font *f)
{
    int response;

    show_font(*f);
    show_menu();
    response = get_choice("fsabiuq");
    switch (response)
    {
    case 'f' :
        get_id(f);
        break;
    case 's' :
        get_size(f);
        break;
    case 'a' :
        get_align(f);
        break;
    case 'b' :
        *f ^= BOLD;
        break;
    case 'i' :
        *f ^= ITALIC;
        break;
    case 'u' :
        *f ^= UNDERLINE;
        break;
    case 'q' :
        break;
    default  :
        fprintf(stderr, "response %c unknown\n", response);
        break;
    }

    return response;
}

int get_choice(const char *str)
{
    int ch;

    ch = getchar();
    ch = tolower(ch);
    eatline();
    while (strchr(str, ch) == NULL)
    {
        printf("Please enter one of the following: %s\n", str);
        ch = getchar();
        ch = tolower(ch);
        eatline();
    }

    return ch;
}

void eatline(void)
{
    while ( getchar() != '\n' )
    {
        continue;
    }
}

void show_menu(void)
{
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
}

void show_font(font f)
{
    printf("%4s %4s %9s %3s %3s %3s\n",
           "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
    switch (f & ALIGN_MASK)
    {
    case LEFT   :
        printf("%7s", "left");
        break;
    case RIGHT  :
        printf("%7s", "right");
        break;
    case CENTER :
        printf("%7s", "center");
        break;
    default     :
        printf("%7s", "unknown");
        break;
    }
    printf("%8s %3s %3s\n", (f & BOLD) == BOLD ? "on" : "off",
           (f & ITALIC) == ITALIC ? "on" : "off",
           (f & UNDERLINE) == UNDERLINE ? "on" : "off");
}

void get_id(font *f)
{
    unsigned long id;

    printf("Enter font ID (0-255): ");
    scanf("%lu", &id);
    eatline();
    id = id & ID_MASK;
    *f &= ~ID_MASK;
    *f |= id;

}

void get_size(font *f)
{
    unsigned long size;

    printf("Enter font size (0-127): ");
    scanf("%lu", &size);
    eatline();
    *f &= ~SIZE_MASK;
    *f |= (size << SIZE_SHIFT) & SIZE_MASK;
}

void get_align(font *f)
{
    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    switch (get_choice("lcr"))
    {
    case 'l' :
        *f &= ~ALIGN_MASK;
        *f |= LEFT;
        break;
    case 'c' :
        *f &= ~ALIGN_MASK;
        *f |= CENTER;
        break;
    case 'r' :
        *f &= ~ALIGN_MASK;
        *f |= RIGHT;
        break;
    default  :
        fprintf(stderr, "alignment unknown\n");
        break;
    }
}
