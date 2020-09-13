#include <stdio.h>
#include <string.h>

char *strchr1(char *s, int c);

int main(int argc, char **argv)
{
    char s[20];
    char c;

    printf("Enter the string and the character: ");

    while (scanf("%s %c", s, &c) == 2)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        char *check = strchr1(s, c);
        if (check == NULL)
        {
            printf("The character %c is not found in the string.\n", c);
        }
        else
        {
            printf("The character %c is found!\n", *check);
        }
        printf("Enter the string and the character: ");
    }

    return 0;
}

char *strchr1(char *s, int c)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
        {
            return &s[i];
        }
    }

    return NULL;
}
