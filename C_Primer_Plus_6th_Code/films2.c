/* films2.c -- 使用结构链表 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TSIZE 128

struct film
{
    char title[TSIZE];
    int rating;
    struct film * next;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    struct film * head = NULL;
    struct film * prev;
    struct film * current;
    struct film * next;
    int len;
    char input[TSIZE];

    puts ("Enter the movie title:");
    while ( ( len = read_line_file(input, 80, stdin) ) > 0 )
    {
        current = (struct film *) malloc ( sizeof (struct film) );
        current->next = NULL;
        strcpy (current->title, input);
        puts ("Enter your rating <0-10>:");
        scanf ("%d", & (current->rating) );
        while ( getchar() != '\n' )
        {
            continue;
        }
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prev->next = current;
        }
        prev = current;
        puts ("Enter the movie title:");
    }
    if (head == NULL)
    {
        printf ("No data entered.\n");
    }
    else
    {
        printf ("Here is the movie list:\n");
        current = head;
        while (current != NULL)
        {
            printf ("Movie: %s Rating: %d\n", current->title, current->rating);
            current = current->next;
        }
        current = head;
        while (current != NULL)
        {
            next = current->next;
            free (current);
            current = next;
        }
    }
    printf ("Done.\n");

    return 0;
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
