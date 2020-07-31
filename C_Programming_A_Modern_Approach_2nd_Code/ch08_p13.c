#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    char c, initial, last[20] = {0};

    printf("Enter a first and last name: ");

    while ((c = getchar()) == ' ')
        ;
    initial = c;
    while ( (c = getchar()) != ' ' )
        ;
    while ((c = getchar()) == ' ')
        ;
    last[0] = c;
    for (i = 1; (c = getchar()) != '\n' && c != ' '; i++)
    {
        last[i] = c;
    }

    printf("You entered the name: ");
    for (i = 0; last[i] != '\0'; i++)
    {
        putchar(last[i]);
    }

    printf(", %c.\n", initial);

    return 0;
}
