#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STRLEN 128
#define LIM 10

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void function1(int cnt, char *s[]);
void function2(int cnt, char *s[]);
void function3(int cnt, char *s[]);
void function4(int cnt, char *s[]);

int main(int argc, char **argv)
{
    char s[LIM][STRLEN];
    char *strptr[LIM];
    int len;
    int cnt = 0;

    for (int i = 0; i < LIM; i++)
    {
        strptr[i] = s[i];
    }

    printf ("Enter up to %d strings:\n", LIM);
    while ( cnt < LIM && ( len = read_line_file(s[cnt], 80, stdin) ) > 0 )
    {
        cnt++;
    }
    if(cnt == 0)
    {
        printf ("Enter 0 strings.\n");
        return 0;
    }

    while(true)
    {
        puts("1. print the original list of strings");
        puts("2. print the strings in ASCII collating sequence");
        puts("3. print the strings in order of increasing length");
        puts("4. print the strings in order of the length of the first word in the string");
        puts("5. quit");
        printf("Please make a choice: ");
        char ch = getchar();
        while (getchar() != '\n')
        {
            continue;
        }
        switch(ch)
        {
        case '1':
            function1(cnt, strptr);
            break;
        case '2':
            function2(cnt, strptr);
            break;
        case '3':
            function3(cnt, strptr);
            break;
        case '4':
            function4(cnt, strptr);
            break;
        case '5':
            puts("Done.");
            return 0;
        default :
            puts("Error!");
            return 0;
        }
    }

    puts("Done.");

    return 0;
}

void function1(int cnt, char *s[])
{
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n",  s[i]);
    }
    printf("\n");
}

void function2(int cnt, char *s[])
{
    char *temp;

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (strcmp(s[i], s[j]) > 0)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n",  s[i]);
    }
    printf("\n");
}

void function3(int cnt, char *s[])
{
    char *temp;

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if ( strlen( s[i] ) > strlen( s[j] ) )
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n",  s[i]);
    }
    printf("\n");
}

void function4(int cnt, char *s[])
{
    char *temp;

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            int first_word_si = -1, first_word_sj = -1;
            int k = 0, l = 0;
            char chi, chj;
            do
            {
                chi = s[i][k];
                k++;
                first_word_si++;
            }
            while(chi != '\0' &&  !isspace(chi) );

            do
            {
                chj = s[j][l];
                l++;
                first_word_sj++;
            }
            while(chj != '\0' && !isspace(chj) );

            if (first_word_si > first_word_sj)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n",  s[i]);
    }
    printf("\n");
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
