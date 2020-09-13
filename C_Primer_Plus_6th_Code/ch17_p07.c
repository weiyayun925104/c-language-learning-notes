#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);
int getlet (const char * s);
void uppercase (char * str);

int menu (void);
void showwords (const Tree * ptree);
void findword (const Tree * ptree);
void printitem (Item item);

int main(int argc, char **argv)
{
    Tree wordcount;
    int choice;
    int len;
    FILE * fp;
    char filename[STRLEN];
    char word[STRLEN];
    Item entry;

    printf("Enter name of file to be processed: \n");
    len = read_line_file(filename, 80, stdin);
    if ( ( fp = fopen (filename, "r") ) == NULL )
    {
        fprintf(stderr, "Can not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    InitializeTree (&wordcount);

    while ( ( len = read_word(word, 80, fp) ) > 0 && !TreeIsFull (&wordcount) )
    {
        strcpy(entry.word, word);
        AddItem(&entry, &wordcount);
    }
    fclose(fp);

    while ( ( choice = menu() ) != 'q' )
    {
        switch (choice)
        {
            case 'l': showwords (&wordcount); break;
            case 'f': findword (&wordcount); break;
            default : printf ("Error, choice = %c.\n", choice); break;
        }
    }
    DeleteAll (&wordcount);
    printf ("Done.\n");

    return 0;
}
int menu (void)
{
    int ch;

    puts ("Word counting program");
    puts ("Enter the letter corresponding to your choice:");
    puts ("f) find a pet                  l) show list of words");
    puts ("q) quit");
    while ( ( ch = getchar() ) != EOF )
    {
        while ( getchar() != '\n')
        {
            continue;
        }
        ch = tolower (ch);
        if ( strchr ("lfq", ch) == NULL )
        {
            puts ("Please enter a letter l, f, or q:");
        }
        else
        {
            break;
        }
    }
    if (ch == EOF)
    {
        ch = 'q';
    }

    return ch;
}
void showwords (const Tree * ptree)
{
    if ( TreeIsEmpty (ptree) )
    {
        puts ("No entries!");
    }
    else
    {
        Traverse (ptree, printitem);
    }
}
void printitem (Item item)
{
    printf ("%6d: %s\n", item.count, item.word);
}
void findword (const Tree * ptree)
{
    Item temp;
    Item * pitem;
    int len;

    if ( TreeIsEmpty (ptree) )
    {
        puts ("No entries!");
        return;
    }
    puts ("Please enter the word you wish to find:");
    len = read_line_file(temp.word, 80, stdin);
    if ( ( pitem = FindItem (&temp, ptree) ) != NULL )
    {
        printf ("%s appears %d times.\n", temp.word, pitem->count);
    }
    else
    {
        printf ("%s is not in the list.\n", temp.word);
    }
}
void uppercase (char * str)
{
    while (*str)
    {
        *str = toupper (*str);
        str++;
    }
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
