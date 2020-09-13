/* petclub.c -- 使用二叉查找树 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);
int getlet (const char * s);
void uppercase (char * str);

int menu (void);
void addpet (Tree *ptree);
void droppet (Tree * ptree);
void showpets (const Tree * ptree);
void findpet (const Tree * ptree);
void printitem (Item item);

int main(int argc, char **argv)
{
    Tree pets;
    int choice;

    InitializeTree (&pets);
    while ( ( choice = menu() ) != 'q' )
    {
        switch (choice)
        {
            case 'a': addpet (&pets); break;
            case 'l': showpets (&pets); break;
            case 'f': findpet (&pets); break;
            case 'n': printf ("%d pets in club.\n", TreeItemCount ( &pets ) ); break;
            case 'd': droppet (&pets); break;
            default : printf ("Error, choice = %c.\n", choice); break;
        }
    }
    DeleteAll (&pets);
    printf ("Done.\n");

    return 0;
}
int menu (void)
{
    int ch;

    puts ("Nerfville Pet Club Membership Program");
    puts ("Enter the letter corresponding to your choice:");
    puts ("a) add a pet                  l) show list of pets");
    puts ("n) number of pets        f) find pets");
    puts ("d) delete a pet              q) quit");
    while ( ( ch = getchar() ) != EOF )
    {
        while ( getchar() != '\n')
        {
            continue;
        }
        ch = tolower (ch);
        if ( strchr ("alfndq", ch) == NULL )
        {
            puts ("Please enter an a, l, f, n, d, or q:");
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
void addpet (Tree * ptree)
{
    Item temp;
    int len;

    if ( TreeIsFull (ptree) )
    {
        puts ("No room in the club!");
    }
    else
    {
        puts ("Please enter name of pet:");
        len = read_line_file(temp.petname, 80, stdin);
        puts ("Please enter pet kind:");
        len = read_line_file(temp.petkind, 80, stdin);
        uppercase (temp.petname);
        uppercase (temp.petkind);
        AddItem (&temp, ptree);
    }
}
void showpets (const Tree * ptree)
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
    printf ("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}
void findpet (const Tree * ptree)
{
    Item temp;
    int len;

    if ( TreeIsEmpty (ptree) )
    {
        puts ("No entries!");
        return;
    }
    puts ("Please enter name of pet you wish to find:");
    len = read_line_file(temp.petname, 80, stdin);
    puts ("Please enter pet kind:");
    len = read_line_file(temp.petkind, 80, stdin);
    uppercase (temp.petname);
    uppercase (temp.petkind);
    printf ("%s the %s ", temp.petname, temp.petkind);
    if ( InTree (&temp, ptree) )
    {
        printf ("is a member.\n");
    }
    else
    {
        printf ("is not a member.\n");
    }
}
void droppet (Tree * ptree)
{
    Item temp;
    int len;

    if ( TreeIsEmpty (ptree) )
    {
        puts ("No entries!");
        return;
    }
    puts ("Please enter name of pet you wish to delete:");
    len = read_line_file(temp.petname, 80, stdin);
    puts ("Please enter pet kind:");
    len = read_line_file(temp.petkind, 80, stdin);
    uppercase (temp.petname);
    uppercase (temp.petkind);
    printf ("%s the %s ", temp.petname, temp.petkind);
    if ( DeleteItem (&temp, ptree) )
    {
        printf ("is dropped from the club.\n");
    }
    else
    {
        printf ("is not a member.\n");
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
