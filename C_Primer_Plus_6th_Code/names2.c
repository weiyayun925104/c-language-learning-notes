/* names2.c -- 传递并返回结构 */

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

struct namect getinfo (void);
struct namect makeinfo (struct namect);
void showinfo (struct namect);

int main(int argc, char **argv)
{
    struct namect person;

    person = getinfo();
    person = makeinfo (person);
    showinfo (person);

    return 0;
}
struct namect getinfo (void)
{
    int len;
    struct namect temp;

    printf ("Please enter your first name: ");
    len = read_line_file(temp.fname, 80, stdin);
    printf ("Please enter your last name: ");
    len = read_line_file(temp.lname, 80, stdin);

    return temp;
}
struct namect makeinfo (struct namect info)
{
    info. letters = strlen(info. fname) + strlen(info.lname);

    return info;
}
void showinfo (struct namect info)
{
    printf ("%s %s, your name contains %d letters.\n", info. fname, info. lname, info. letters);
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
