/* booksave.c -- 在文件中保存结构中的内容 */

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

int main(int argc, char **argv)
{
    struct book library[MAXBOOKS];
    int count = 0;
    int index;
    int filecount;
    int len;
    int ret;
    int size;
    FILE * fpbook;

    if ( ( fpbook = fopen ("book.dat", "a+b") ) == NULL )
    {
        fprintf(stderr, "Can not open book.dat\n");
        exit(EXIT_FAILURE);
    }

    size = sizeof (struct book);
    rewind (fpbook);
    while ( count < MAXBOOKS && ( ret = fread(&library[count], size, 1, fpbook) ) == 1 )
    {
        if (count == 0)
        {
            puts ("Current contents of book.dat:");
        }
        printf ("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count >= MAXBOOKS)
    {
        fclose (fpbook);
        fprintf(stderr, "book.dat is full.\n");
        exit(EXIT_FAILURE);
    }
    puts ("Please add new book titles.");
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
        fwrite (&library[filecount], size, count - filecount, fpbook);
    }
    else
    {
        printf ("No books.\n");
    }
    printf ("Done.\n");
    fclose (fpbook);

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
