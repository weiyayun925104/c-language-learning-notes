/* menuette.c -- ²Ëµ¥³ÌÐò */

#include <stdio.h>
#include <ctype.h>

int get_first (void);
int get_choice (void);
int get_int (void);
void count (void);

int main(int argc, char **argv)
{
    int choice;

    while ( ( choice = get_choice() ) != 'q')
    {
        switch (choice)
        {
            case 'a' : printf ("Buy low, sell high.\n"); break;
            case 'b' : putchar ('\a'); break;
            case 'c' : count(); break;
            default : printf ("%c error!\n", choice); break;
        }
    }
    printf("Done.\n");

    return 0;
}
int get_first (void)
{
    int ch;

    while ( isspace( ch = getchar() ) )
    {
        continue;
    }
    while ( getchar() != '\n' )
    {
        continue;
    }

    return ch;
}
int get_choice (void)
{
    int ch;

    printf ("Enter the letter of your choice: \n");
    printf ("a. advice         b. bell\n");
    printf ("c. count          q. quit\n");
    ch = get_first();
    while ( ( ch < 'a' || ch > 'c' ) && ch != 'q' )
    {
        printf ("Please respond with a or b or c or q.\n");
        ch = get_first();
    }

    return ch;
}
int get_int (void)
{
    int input;
    char ch;

    while ( scanf ("%d", &input) != 1)
    {
        while ( (ch = getchar() ) != '\n' && ch != EOF)
        {
            putchar(ch);
        }
        printf (" is not an integer.\nPlease enter an integer: ");
    }

    return input;
}
void count (void)
{
    int n, i;

    printf ("Count how far? Enter an integer: \n");
    n = get_int();
    for (i = 1; i <= n; i++)
    {
        printf ("%8d ", i);
        if ( i % 8 == 0 )
        {
            printf("\n");
        }
    }
    printf("\n");
    while ( getchar() != '\n' )
    {
        continue;
    }
}
