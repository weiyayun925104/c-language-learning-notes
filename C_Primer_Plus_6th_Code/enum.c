/* enum.c -- 使用枚举类型的值 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define STRLEN 128

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

enum spectrum { red, orange, yellow, green, blue, violet };
const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

int main(int argc, char **argv)
{
    int len;
    char choice[STRLEN];
    enum spectrum color;
    bool color_is_found = false;

    printf ("Enter a color: ");
    while ( ( len = read_line_file(choice, 80, stdin) ) > 0 )
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp (choice, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
        {
            switch (color)
            {
                case red: puts ("Roses are red."); break; 
                case orange: puts ("Poppies are orange."); break; 
                case yellow: puts ("Sunflowers are yellow."); break; 
                case green: puts ("Grass is green."); break; 
                case blue: puts ("Bluebells are blue."); break; 
                case violet: puts ("Violets are violet."); break; 
                default: break; 
            }
        }
        else
        {
            printf ("I don't know about the color %s.\n", choice);
        }
        color_is_found = false;
        printf ("Enter a color: ");
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
