// func_ptr.c -- 使用函数指针

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int showmenu (void);
void eatline (void);
void show (void (*fp) (char *), char * str);
void ToUpper (char *);
void ToLower (char *);
void Transpose (char *);
void Dummy (char *);

int main(int argc, char **argv)
{
    char line[STRLEN];
    char copy[STRLEN];
    int choice;
    int len;
    void (*pfun) (char *);

    printf ("Enter a string: ");
    while ( ( len = read_line_file(line, 80, stdin) ) > 0 )
    {
        while ( ( choice = showmenu() ) != 'n' )
        {
            pfun = NULL;
            switch (choice)
            {
                case 'u': pfun = ToUpper; break; 
                case 'l': pfun = ToLower; break; 
                case 't': pfun = Transpose; break; 
                case 'o': pfun = Dummy; break;
                default: break; 
            }
            if (pfun != NULL)
            {
                strcpy (copy, line);
                show (pfun, copy);
            }
        }
        printf ("Enter a string: ");
    }
    printf ("Done.\n");

    return 0;
}
int showmenu (void)
{
    int ch;

    puts ("Enter menu choice:");
    puts ("u) uppercase         l) lowercase");
    puts ("t) transposed case o) original case");
    puts ("n) next string");
    ch = getchar();
    ch = tolower (ch);
    eatline();
    while ( strchr("ulton", ch) == NULL )
    {
        puts ("Please enter a, u, l, t, o, n:");
        ch = getchar();
        ch = tolower (ch);
        eatline();
    }

    return ch;
}
void eatline (void)
{
    while ( getchar() != '\n' )
    {
        continue;
    }
}
void ToUpper (char * str)
{
    while (*str)
    {
        *str = toupper (*str);
        str++;
    }
}
void ToLower (char * str)
{
    while (*str)
    {
        *str = tolower (*str);
        str++;
    }
}
void Transpose (char * str)
{
    while (*str)
    {
        if ( islower (*str) )
        {
            *str = toupper (*str);
        }
        else if ( isupper (*str) )
        {
            *str = tolower (*str);
        }
        str++;
    }
}
void Dummy (char * str)
{
    
}
void show (void (*fp) (char *), char * str)
{
    (*fp) (str);
    puts (str);
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
