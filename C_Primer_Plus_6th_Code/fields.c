/* fields.c -- 定义并使用字段 */

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

void show_settings (const struct box_props * pb);

int main(int argc, char **argv)
{
    struct box_props box = {1, YELLOW, 1, GREEN, DASHED};

    printf ("Original box settings:\n");
    show_settings (&box);
    box.opaque = 0;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf ("\nModified box settings:\n");
    show_settings (&box);

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
