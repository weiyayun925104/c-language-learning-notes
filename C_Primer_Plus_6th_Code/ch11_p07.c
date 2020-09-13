#include <stdio.h>
#include <string.h>

char *mystrncpy(char *s1, char *s2, int n);

int main(int argc, char **argv)
{
    char s1[128] = "Hello, world!";
    char s2[128] = "ABCdefGH";

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    mystrncpy(s1, s2, 4);

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    mystrncpy(s1, s2, 10);

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    return 0;
}

char *mystrncpy(char *s1, char *s2, int n)
{
    if (strlen(s2) >= n)
    {
        for (int i = 0; i < n; i++)
        {
            s1[i] = s2[i];
        }
    }
    else
    {
        for (int j = 0; j < strlen(s2); j++)
        {
            s1[j] = s2[j];
        }
        for (int k = strlen(s2); k < n; k++)
        {
            s1[k] = '\0';
        }
    }

    return s1;
}
