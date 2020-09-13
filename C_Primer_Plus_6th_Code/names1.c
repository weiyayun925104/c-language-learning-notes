/* names1.c -- 使用指向结构的指针 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct namect
{
    char fname[STRLEN];
    char lname[STRLEN];
    int letters;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void getinfo (struct namect *);
void makeinfo (struct namect *);
void showinfo (const struct namect *);

int main(int argc, char **argv)
{
    struct namect person;

    getinfo (&person);
    makeinfo (&person);
    showinfo (&person);

    return 0;
}
void getinfo (struct namect * pst)
{
    int len;

    printf ("Please enter your first name: ");
    len = read_line_file(pst->fname, 80, stdin);
    printf ("Please enter your last name: ");
    len = read_line_file(pst->lname, 80, stdin);
}
void makeinfo (struct namect * pst)
{
    pst->letters = strlen (pst->fname) + strlen (pst->lname);
}
void showinfo (const struct namect * pst)
{
    printf ("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
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
