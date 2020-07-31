#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

void display(int n, ...);

int main(int argc, char **argv)
{
    display(4, "Special", "Agent", "Dale", "Cooper");

    return 0;
}

void display(int n, ...)
{
    va_list ap;
    int i;
    char *p;

    va_start(ap, n);

    for (i = 0; i < n; i++)
    {
        p = va_arg(ap, char *);
        while (*p)
        {
            putchar(*p);
            p++;
        }
        if (i < n - 1)
        {
            putchar(' ');
        }
    }
    putchar('\n');
    va_end(ap);
}
