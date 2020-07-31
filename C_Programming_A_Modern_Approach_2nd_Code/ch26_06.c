#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

char *max_pair(int num_pairs, ...);

int main(int argc, char **argv)
{
    char *str;

    str = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners", 210, "All in the Family", 86, "The Sopranos");
    printf("%s\n", str);

    return 0;
}

char *max_pair(int num_pairs, ...)
{
    va_list ap;
    int i, current, largest_i, largest;
    char *s;

    va_start(ap, num_pairs);
    largest = va_arg(ap, int);
    largest_i = 0;
    va_arg(ap, char *);

    for (i = 1; i < num_pairs; i++)
    {
        if ( ( current = va_arg(ap, int) ) > largest )
        {
            largest = current;
            largest_i = i;
        }
        va_arg(ap, char *);
    }
    va_end(ap);
    va_start(ap, num_pairs);

    for (i = 0; i < largest_i; i++)
    {
        va_arg(ap, int);
        va_arg(ap, char *);
    }
    va_arg(ap, int);
    s = va_arg(ap, char *);
    va_end(ap);
    return s;
}
