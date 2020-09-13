/* films1.c -- 使用一个结构数组 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TSIZE 128
#define FMAX 5

struct film
{
    char title[TSIZE];
    int rating;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    struct film movies[FMAX];
    int i = 0;
    int j;
    int len;

    puts ("Enter the movie title:");
    while ( i < FMAX &&  ( len = read_line_file(movies[i].title, 80, stdin) ) > 0 )
    {
        puts ("Enter your rating <0-10>:");
        scanf ("%d", & (movies[i].rating) );
        while ( getchar() != '\n' )
        {
            continue;
        }
        i++;
        puts ("Enter the movie title:");
    }
    if (i == 0)
    {
        printf ("No data entered.\n");
    }
    else
    {
        printf ("Here is the movie list:\n");
        for (j = 0; j < i; j++)
        {
            printf ("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
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
