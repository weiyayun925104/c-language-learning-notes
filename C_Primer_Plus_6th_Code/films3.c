/* films3.c -- 使用抽象数据类型（ADT）风格的链表 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

void showmovies (Item item);

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    List movies;
    Item temp;
    int len;

    InitializeList (&movies);
    if ( ListIsFull (&movies) )
    {
        fprintf (stderr, "List is full.\n");
        exit (EXIT_FAILURE);
    }

    puts ("Enter the movie title:");
    while ( ( len = read_line_file(temp.title, 80, stdin) ) > 0 )
    {
        puts ("Enter your rating <0-10>:");
        scanf ("%d", & (temp.rating) );
        while ( getchar() != '\n' )
        {
            continue;
        }
        if (AddItem (temp, &movies) == false)
        {
            fprintf (stderr, "Error, can not AddItem.\n");
            break;
        }
        if ( ListIsFull (&movies) )
        {
            puts ("The list is now full.");
            break;
        }
        puts ("Enter the movie title:");
    }
    if ( ListIsEmpty (&movies) )
    {
        printf ("No data entered.\n");
    }
    else
    {
        printf ("Here is the movie list:\n");
        Traverse (&movies, showmovies);
        printf ("You entered %d movies.\n", ListItemCount (&movies) );
    }
    EmptyTheList (&movies);
    printf ("Done.\n");

    return 0;
}
void showmovies (Item item)
{
    printf ("Movie: %s Rating: %d\n", item.title, item.rating);
}
int read_char (FILE *fp)
{
    int ch = getc(fp);
    if (ch == '\n' || ch == '\t')
    {
        return ' ';
    }
    return ch;
}
int read_word(char *word, int len, FILE *fp)
{
    int ch, pos = 0;
    while ( ( ch = read_char(fp) ) == ' ')
        ;
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
        {
            word[pos++] = ch;
        }
        ch = read_char(fp);
    }
    word[pos] = '\0';
    return pos;
}
int read_line_file(char str[], int n, FILE *fp)
{
    int ch, i = 0;

    while ( isspace ( ch = getc(fp) ) )
        ;
    while ( ch != '\n' && ch != EOF)
    {
        if (i < n)
        {
            str[i++] = ch;
        }
        ch = getc(fp);
    }
    str[i] = '\0';
    return i;
}
