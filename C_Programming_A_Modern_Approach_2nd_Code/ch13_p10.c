#include <stdio.h>

void reverse_name(char *name);
int read_line (char str[], int n);

int main(int argc, char **argv)
{
    char name[81];

    printf("Enter a first and last name: ");
    read_line (name, 80);
    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name, initial;

    while (*p == ' ')
    {
        p++;
    }
    if(*p == '\0')
    {
        return;
    }
    initial = *p++;

    while (*p && *p != ' ')
    {
        p++;
    }
    if(*p == '\0')
    {
        return;
    }
    p++;

    while (*p == ' ')
    {
        p++;
    }
    if(*p == '\0')
    {
        return;
    }
    while (*p && *p != '\n' && *p != ' ')
    {
        putchar(*p++);
    }
    printf(", %c.\n", initial);
}
int read_line (char str[], int n)
{
    int ch, i = 0;
    while ( (ch = getchar() ) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
