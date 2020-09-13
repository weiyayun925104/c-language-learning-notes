/* join_chk.c -- 拼接两个字符串，检查第1个数组的大小 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int main(int argc, char **argv)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char bug[SIZE];
    int available;

    puts ("What is your favorite flower?");
    if ( read_line_file(flower, 80, stdin) > 0 )
    {
        if ( (strlen(addon) + strlen(flower) + 1) <= SIZE)
        {
            strcat (flower, addon);
        }
        puts (flower);
    }
    puts ("What is your favorite bug?");
    if ( read_line_file(bug, 80, stdin) > 0 )
    {
        available = SIZE - strlen(bug) - 1;
        strncat (bug, addon, available);
        puts (bug);
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
