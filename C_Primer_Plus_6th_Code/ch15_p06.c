#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define LEFT        0
#define CENTER      1
#define RIGHT       2
#define ID_MASK     0xFF
#define SIZE_MASK   0x7F

struct Font
{
    unsigned int id         : 8;
    unsigned int size       : 7;
    unsigned int            : 1;
    unsigned int alignment  : 2;
    unsigned int bold               : 1;
    unsigned int italic             : 1;
    unsigned int underline          : 1;
    unsigned int            : 3;
};

int main(int argc, char **argv)
{
    struct Font font = {.id = 1, .size = 12, .alignment = LEFT, .bold = 0, .italic = 0, .underline = 0};

    puts(" ID SIZE ALIGNMENT   B   I   U");
    printf("%3d %4d", font.id, font.size);
    if (font.alignment == 0)
    {
        printf("   left    ");
    }
    else if (font.alignment == 1)
    {
        printf(" center    ");
    }
    else
    {
        printf("  right    ");
    }
    if (font.bold)
    {
        printf("  on");
    }
    else
    {
        printf(" off");
    }
    if (font.italic)
    {
        printf("  on");
    }
    else
    {
        printf(" off");
    }
    if (font.underline)
    {
        printf("  on");
    }
    else
    {
        printf(" off");
    }
    putchar('\n');
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");

    char choice;
    choice = getchar();
    while ( getchar() != '\n' )
    {
        continue;
    }
    while (choice != 'q')
    {
        switch(choice)
        {
        case 'f':
            printf("Enter font id (0-255): ");
            int input_id;
            scanf("%d", &input_id);
            while ( getchar() != '\n' )
            {
                continue;
            }
            font.id = input_id & ID_MASK;
            break;
        case 's':
            printf("Enter font size (0-127): ");
            int input_size;
            scanf("%d", &input_size);
            while ( getchar() != '\n' )
            {
                continue;
            }
            font.size = input_size & SIZE_MASK;
            break;
        case 'a':
            puts("Select alignment:");
            puts("l)left   c)center   r)right");
            char input_alignment;
            input_alignment = getchar();
            while ( getchar() != '\n' )
            {
                continue;
            }
            if (input_alignment == 'l')
            {
                font.alignment = 0;
            }
            else if (input_alignment == 'c')
            {
                font.alignment = 1;
            }
            else
            {
                font.alignment = 2;
            }
            break;
        case 'b':
            font.bold = !font.bold;
            break;
        case 'i':
            font.italic = !font.italic;
            break;
        case 'u':
            font.underline = !font.underline;
            break;
        }

        puts(" ID SIZE ALIGNMENT   B   I   U");
        printf("%3d %4d", font.id, font.size);
        if (font.alignment == 0)
        {
            printf("   left    ");
        }
        else if (font.alignment == 1)
        {
            printf(" center    ");
        }
        else
        {
            printf("  right    ");
        }
        if (font.bold)
        {
            printf("  on");
        }
        else
        {
            printf(" off");
        }
        if (font.italic)
        {
            printf("  on");
        }
        else
        {
            printf(" off");
        }
        if (font.underline)
        {
            printf("  on");
        }
        else
        {
            printf(" off");
        }
        putchar('\n');
        puts("f)change font    s)change size    a)change alignment");
        puts("b)toggle bold    i)toggle italic  u)toggle underline");
        puts("q)quit");

        choice = getchar();
        while ( getchar() != '\n' )
        {
            continue;
        }
    }
    printf ("Done.\n");

    return 0;
}
