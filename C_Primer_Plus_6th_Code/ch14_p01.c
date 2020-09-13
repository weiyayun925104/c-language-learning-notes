#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month
{
    char name[12];
    char abbrev[4];
    int days;
    int monumb;
};

const struct month months[12] = 
{
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int days(char * m);

int main(int argc, char **argv)
{
    char input[128];
    int daytotal;
    int len;

    printf("Enter the name of a month (q to quit): ");
    while ( ( len = read_line_file(input, 80, stdin) ) > 0 && input[0] != 'q')
    {
        daytotal = days(input);
        if (daytotal > 0)
        {
            printf("There are %d days through %s.\n", daytotal, input);
        }
        else
        {
            printf("%s is not valid input.\n", input);
        }
        printf("Enter the name of a month (q to quit): ");
    }
    printf ("Done.\n");

    return 0;
}
int days(char * m)
{
    int total = 0;
    int mon_num = 0;
    int i;
    m[0] = toupper(m[0]);
    for (i = 1; m[i] != '\0'; i++)
    {
        m[i] = tolower(m[i]);
    }
    for (i = 0; i < 12; i++)
    {
        if (strcmp(m, months[i].name) == 0)
        {
            mon_num = months[i].monumb;
            break;
        }
    }
    if (mon_num == 0)
    {
        total = -1;
    }
    else
    {
        for (i = 0; i < mon_num; i++)
        {
            total += months[i].days;
        }
    }

    return total;
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
