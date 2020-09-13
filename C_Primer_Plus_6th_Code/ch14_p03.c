#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128
#define MAXBOOKS 100

struct book
{
    char title[STRLEN];
    char author[STRLEN];
    double value;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void sortt(struct book * pb[], int n);
void sortv(struct book * pb[], int n);

int main(int argc, char **argv)
{
    struct book library[MAXBOOKS];
    struct book * pbk[MAXBOOKS];
    int count = 0;
    int index;
    int len;

    printf ("Please enter the book title.\n");
    while ( count < MAXBOOKS && ( len = read_line_file(library[count].title, 80, stdin) ) > 0 )
    {
        printf ("Now enter the author.\n");
        len = read_line_file(library[count].author, 80, stdin);
        printf ("Now enter the value.\n");
        scanf ("%lf", & (library[count].value) );
        while ( getchar() != '\n' )
        {
            continue;
        }
        pbk[count] = &library[count];
        count++;
        if ( count < MAXBOOKS )
        {
            printf ("Please enter the book title.\n");
        }
    }
    if (count > 0)
    {
        printf ("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
        {
            printf ("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        printf("Here is the list of your books sorted by title:\n");
        sortt(pbk, count);
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", pbk[index]->title, pbk[index]->author, pbk[index]->value);
        }
        printf("Here is the list of your books sorted by value:\n");
        sortv(pbk, count);
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", pbk[index]->title, pbk[index]->author, pbk[index]->value);
        }
    }
    else
    {
        printf ("No books.\n");
    }

    return 0;
}
void sortt(struct book * pb[], int n)
{
    int top, search;
    struct book * temp;

    for (top = 0; top < n - 1; top++)
    {
        for (search = top + 1; search < n; search++)
        {
            if (strcmp(pb[top]->title, pb[search]->title) > 0)
            {
                temp = pb[search];
                pb[search] = pb[top];
                pb[top] = temp;
            }
        }
    }
}
void sortv(struct book * pb[], int n)
{
    int top, search;
    struct book * temp;

    for (top = 0; top < n - 1; top++)
    {
        for (search = top + 1; search < n; search++)
        {
            if (pb[top]->value > pb[search]->value)
            {
                temp = pb[search];
                pb[search] = pb[top];
                pb[top] = temp;
            }
        }
    }
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
