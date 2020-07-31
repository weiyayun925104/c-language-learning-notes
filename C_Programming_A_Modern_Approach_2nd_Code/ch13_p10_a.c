#include <stdio.h>

void reverse_name(char *name);

int main(int argc, char **argv)
{
    char name[81];

    printf("Enter a first and last name: ");
    fgets(name, 80, stdin);
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
    if(*p == '\0' || *p == '\n')
    {
        return;
    }
    initial = *p++;

    while (*p && *p != ' ' && *p != '\n')
    {
        p++;
    }
    if(*p == '\0' || *p == '\n')
    {
        return;
    }
    p++;

    while (*p == ' ')
    {
        p++;
    }
    if(*p == '\0' || *p == '\n')
    {
        return;
    }
    while (*p && *p != '\n' && *p != ' ')
    {
        putchar(*p++);
    }
    printf(", %c.\n", initial);
}
