#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STRLEN 128
#define MAXBOOKS 100
#define CONTINUE  0
#define DONE      1

struct book
{
    char title[STRLEN];
    char author[STRLEN];
    double value;
};

struct pack {
    struct book book;
    bool delete_me;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int getlet (const char * s);
int getbook (struct pack * pb);
void update (struct pack * pb);

int main(int argc, char **argv)
{
    struct pack library[MAXBOOKS];
    int count = 0;
    int deleted = 0;
    int index;
    int filecount;
    int open;
    int len;
    int ret;
    int size;
    FILE * fpbook;

    if ( ( fpbook = fopen ("book.dat", "r+b") ) == NULL )
    {
        fprintf(stderr, "Can not open book.dat\n");
        exit(EXIT_FAILURE);
    }

    size = sizeof (struct book);
    rewind (fpbook);
    while ( count < MAXBOOKS && ( ret = fread(&(library[count].book), size, 1, fpbook) ) == 1 )
    {
        library[count].delete_me = false;
        if (count == 0)
        {
            puts ("Current contents of book.dat:");
        }
        printf ("%s by %s: $%.2f\n", library[count].book.title, library[count].book.author, library[count].book.value);
        printf("Do you want to change or delete this entry?<y/n> ");
        if (getlet("yn") == 'y')
        {
            printf("Enter c to change, d to delete entry: ");
            if (getlet("cd") == 'd')
            {
                library[count].delete_me = true;
                deleted++;
                puts("Entry marked for deletion.");
            }
            else
            {
                update(&library[count]);
            }
        }
        count++;
    }
    fclose (fpbook);
    filecount = count - deleted;
    if (filecount >= MAXBOOKS)
    {
        fprintf(stderr, "book.dat is full.\n");
        exit(EXIT_FAILURE);
    }
    open = 0;
    puts ("Please add new book titles.");
    while (filecount < MAXBOOKS)
    {
        if (filecount < count)
        {
            while (library[open].delete_me == false)
            {
                open++;
            }
            if (getbook(&library[open]) == DONE)
            {
                break;
            }
        }
        else if (getbook(&library[filecount]) == DONE)
        {
            break;
        }
        filecount++;
        if (filecount < MAXBOOKS)
        {
            printf ("Please enter the book title.\n");
        }
    }
    if (filecount > 0)
    {
        printf ("Here is the list of your books:\n");
        int loopcount;
        if (filecount < count)
        {
            loopcount = count;
        }
        else
        {
            loopcount = filecount;
        }
        for (index = 0; index < loopcount; index++)
        {
            if (library[index].delete_me == false)
            {
                printf ("%s by %s: $%.2f\n", library[index].book.title, library[index].book.author, library[index].book.value);
            }
        }
        if ( ( fpbook = fopen ("book.dat", "w+b") ) == NULL )
        {
            fprintf(stderr, "Can not open book.dat for output\n");
            exit(EXIT_FAILURE);
        }
        for (index = 0; index < loopcount; index++)
        {
            if (library[index].delete_me == false)
            {
                fwrite (& (library[index].book), size, 1, fpbook);
            }
        }
        fclose (fpbook);
    }
    else
    {
        printf ("No books.\n");
    }
    printf ("Done.\n");

    return 0;
}
int getlet (const char * s)
{
    int c;

    c= getchar();
    while (strchr(s, c) == NULL)
    {
        printf("Enter a character in the list %s\n", s);
        while (getchar() != '\n')
        {
            continue;
        }
        c = getchar();
    }
    while (getchar() != '\n')
    {
        continue;
    }

    return c;
}
int getbook(struct pack * pb)
{
    int status = CONTINUE;
    int len;

    len = read_line_file(pb->book.title, 80, stdin);
    if (len <= 0)
    {
        status = DONE;
    }
    else
    {
        printf ("Now enter the author.\n");
        len = read_line_file(pb->book.author, 80, stdin);
        printf ("Now enter the value (numeric input).\n");
        while ( scanf("%lf", & (pb->book.value) ) != 1)
        {
            while (getchar() != '\n')
            {
                continue;
            }
            printf("Please enter the value (numeric input).\n");
        }
        while (getchar() != '\n')
        {
            continue;
        }
        pb->delete_me = false;
    }
    return status;
}
void update(struct pack * pb)
{
    struct book copy;
    int c;
    int len;

    copy = pb->book;
    puts("Enter the letter that indicates your choice:");
    puts("t) modify title       a) modify author");
    puts("v) modify value       s) quit, saving changes");
    puts("q) quit, ignore changes");
    while ( ( c = getlet("tavsq") ) != 's' && c != 'q' )
    {
        switch (c)
        {
            case 't': puts("Enter new title: ");
                      len = read_line_file(copy.title, 80, stdin);
                      break;
            case 'a': puts("Enter new author: ");
                      len = read_line_file(copy.author, 80, stdin);
                      break;
            case 'v': puts("Enter new value: ");
                      while (scanf("%lf", & (copy.value) ) != 1)
                      {
                          while (getchar() != '\n')
                          {
                              continue;
                          }
                          puts("Enter a numeric value: ");
                      }
                      while (getchar() != '\n')
                      {
                          continue;
                      }
                      break;
            default: break;
        }
        puts("t) modify title       a) modify author");
        puts("v) modify value       s) quit, saving changes");
        puts("q) quit, ignore changes");
    }
    if (c == 's')
    {
        pb->book = copy;
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
