#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

const struct month months[12] = {
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

const struct month months_heap[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 29, 2},
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

int days(int d, char * m, int y);
int days_heap(int d, char * m, int y);

int main(int argc, char **argv)
{
    int day;
    char input[128];
    int len;
    int ret;
    int year;
    int daytotal;

    printf("Please enter the day (q to quit): ");
    while ( ( ret = scanf("%d", &day) ) == 1 && day >= 1 && day <= 31 )
    {
        while ( getchar() != '\n' )
        {
            continue;
        }
        printf("Please enter the month: ");
        len = read_line_file(input, 80, stdin);
        printf("Please enter the year: ");
        scanf("%d", &year);
        while ( getchar() != '\n' )
        {
            continue;
        }
        if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
        {
            daytotal = days_heap(day, input, year);
        }
        else
        {
            daytotal = days(day, input, year);
        }
        if (daytotal > 0)
        {
            printf("There are %d days through %s %d in year %d.\n", daytotal, input, day, year);
        }
        else
        {
            printf("%s is not valid input.\n", input);
        }
        printf("Please enter the day (q to quit): ");
    }
    printf ("Done.\n");

    return 0;
}
int days(int d, char * m, int y)
{
    int total = 0;
    int mon_num = 0;
    int i;
    if ( isalpha(*m) )
    {
        m[0] = toupper(m[0]);
        for (i = 1; m[i] != '\0'; i++)
        {
            m[i] = tolower(m[i]);
        }
    }
    for (i = 0; i < 12; i++)
    {
        if (strcmp(m, months[i].name) == 0 || strcmp(m, months[i].abbrev) == 0 || atoi(m) == months[i].monumb)
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
        for (i = 0; i < mon_num - 1; i++)
        {
            total += months[i].days;
        }
        if (d > months[i].days)
        {
            total += months[i].days;
        }
        else
        {
            total += d;
        }
    }

    return total;
}
int days_heap(int d, char * m, int y)
{
    int total = 0;
    int mon_num = 0;
    int i;
    if ( isalpha(*m) )
    {
        m[0] = toupper(m[0]);
        for (i = 1; m[i] != '\0'; i++)
        {
            m[i] = tolower(m[i]);
        }
    }
    for (i = 0; i < 12; i++)
    {
        if (strcmp(m, months_heap[i].name) == 0 || strcmp(m, months_heap[i].abbrev) == 0 || atoi(m) == months_heap[i].monumb)
        {
            mon_num = months_heap[i].monumb;
            break;
        }
    }
    if (mon_num == 0)
    {
        total = -1;
    }
    else
    {
        for (i = 0; i < mon_num - 1; i++)
        {
            total += months_heap[i].days;
        }
        if (d > months_heap[i].days)
        {
            total += months_heap[i].days;
        }
        else
        {
            total += d;
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
