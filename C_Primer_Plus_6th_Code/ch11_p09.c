#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *s);

int main(int argc, char **argv)
{
    char s[128] = "Hello, world!";
    char s1[128] = "ABCdefGH";

    reverse(s);
    reverse(s1);

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(s1); i++)
    {
        printf("%c", s1[i]);
    }
    printf("\n");

    return 0;
}
void reverse(char *s)
{
    char *begin;
    char *end;
    char temp;

    begin = s;
    end = s + strlen(s) - 1;

    while (begin < end)
    {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}
