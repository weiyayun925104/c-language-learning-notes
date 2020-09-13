// names_st.c -- 定义names_st.h中的函数

#include "names_st.h"

void get_names (names * pn)
{
    int len;

    printf ("Please enter your first name: ");
    len = read_line_file(pn->first, STRLEN - 1, stdin);
    printf ("Please enter your last name: ");
    len = read_line_file(pn->last, STRLEN - 1, stdin);
}
void show_names (const names * pn)
{
    printf ("%s %s", pn->first, pn->last);
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
