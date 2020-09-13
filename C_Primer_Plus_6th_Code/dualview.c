/* dualview.c -- 位字段和按位运算符 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2


#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)


#define OPAQUE 0x1U
#define FILL_BLUE 0x8U
#define FILL_GREEN 0x4U
#define EILL_RED 0x2U
#define FILL_MASK 0xEU
#define BORDER 0x100U
#define BORDER_BLUE 0x800U
#define BORDER_GREEN 0x400U
#define BORDER_RED 0x200U
#define BORDER_MASK 0xE00U
#define B_SOLID 0x0000U
#define B_DOTTED 0x1000U
#define B_DASHED 0x2000U
#define STYLE_MASK 0x3000U

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct box_props
{
    unsigned int opaque : 1;
    unsigned int fill_color : 3;
    unsigned int : 4;
    unsigned int show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int : 2;
};

union Views
{
    struct box_props st_view;
    unsigned short us_view;
};

void show_settings (const struct box_props * pb);
void show_settings1 (unsigned short);

char * itobs (unsigned long, char *);
void show_bstr (const char *);

int main(int argc, char **argv)
{
    union Views box = { {1, YELLOW, 1, GREEN, DASHED} };
    char bin_str[ CHAR_BIT * sizeof(unsigned long) + 1] = {0};
    unsigned long number;

    printf ("Original box settings:\n");
    show_settings ( & (box.st_view) );
    printf ("\nBox settings using unsigned short view:\n");
    show_settings1 (box.us_view);
    number = box.us_view;
    printf ("Binary equivalent:\n");
    itobs (number, bin_str);
    show_bstr(bin_str);
    putchar ('\n');
    box.us_view &= ~FILL_MASK;
    box.us_view |= (FILL_BLUE | FILL_GREEN);
    box.us_view ^= OPAQUE;
    box.us_view |= BORDER_RED;
    box.us_view &= ~STYLE_MASK;
    box.us_view |= B_DOTTED;
    printf ("\nModified box settings:\n");
    show_settings ( & (box.st_view) );
    printf ("\nBox settings using unsigned short view:\n");
    show_settings1 (box.us_view);
    number = box.us_view;
    printf ("Binary equivalent:\n");
    itobs (number, bin_str);
    show_bstr(bin_str);
    putchar ('\n');

    return 0;
}
void show_settings (const struct box_props * pb)
{
    printf ("Box is %s.\n", pb->opaque == 1 ? "opaque" : "transparent");
    printf ("The fill color is %s.\n", colors[pb->fill_color] );
    printf ("Border %s.\n", pb->show_border == 1 ? "shown" : "not shown" );
    printf ("The border color is %s.\n", colors[pb->border_color] );
    printf ("The border style is ");
    switch (pb->border_style)
    {
        case SOLID : printf ("solid.\n"); break; 
        case DOTTED : printf ("dotted.\n"); break; 
        case DASHED : printf ("dashed.\n"); break; 
        default : printf ("unknown type.\n"); break; 
    }
}
void show_settings1 (unsigned short us)
{
    printf ("Box is %s.\n", (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
    printf ("The fill color is %s.\n", colors[ (us >> 1) & 7U ] );
    printf ("Border %s.\n", (us & BORDER) == BORDER ? "shown" : "not shown");
    printf ("The border color is %s.\n", colors[ (us >> 9) & 7U ] );
    printf ("The border style is ");
    switch ( us & STYLE_MASK )
    {
        case B_SOLID: printf ("solid.\n"); break; 
        case B_DOTTED: printf ("dotted.\n"); break; 
        case B_DASHED: printf ("dashed.\n"); break; 
        default : printf ("unknown type.\n"); break; 
    }
}
char * itobs (unsigned long n, char * ps)
{
    int i;
    static const int size = CHAR_BIT * sizeof (unsigned long);

    for (i = size - 1; i >=0; i--, n>>=1)
    {
        ps[i] = ( 1UL & n) + '0';
    }
    ps[size] = '\0';

    return ps;
}
void show_bstr (const char * str)
{
    int i= 0;

    while ( str[i] )
    {
        putchar ( str[i] );
        if (i % 4 == 3 && str[i+1] )
        {
            putchar (' ');
        }
        i++;
    }
}
