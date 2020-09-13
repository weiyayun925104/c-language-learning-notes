// names3.c -- 使用指针和malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct namect
{
    char * fname;
    char * lname;
    int letters;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void getinfo (struct namect *);
void makeinfo (struct namect *);
void showinfo (const struct namect *);
void cleanup (struct namect *);

int main(int argc, char **argv)
{
    struct namect person;

    getinfo (&person);
    makeinfo (&person);
    showinfo (&person);
    cleanup (&person);

    return 0;
}
void getinfo (struct namect * pst)
{
    int len;
    char temp[STRLEN];

    printf ("Please enter your first name: ");
    len = read_line_file(temp, 80, stdin);
    pst->fname = malloc (len + 1);
    strcpy (pst->fname, temp);
    printf ("Please enter your last name: ");
    len = read_line_file(temp, 80, stdin);
    pst->lname = malloc (len + 1);
    strcpy (pst->lname, temp);
}
void makeinfo (struct namect * pst)
{
    pst->letters = strlen (pst->fname) + strlen (pst->lname);
}
void showinfo (const struct namect * pst)
{
    printf ("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}
void cleanup (struct namect * pst)
{
    free (pst->fname);
    free (pst->lname);
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
