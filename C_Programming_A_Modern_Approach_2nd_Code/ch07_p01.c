/* Prints a table of squares using a for statement */

#include <stdio.h>

int main(int argc, char **argv)
{
    short i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("%20hd%20hd\n", i, i * i);
    }

    return 0;
}
