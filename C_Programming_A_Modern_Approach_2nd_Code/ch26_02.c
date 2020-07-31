#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

void my_printf(char *s, ...);

int main(int argc, char **argv)
{
    int i = 3, j = 6;
    my_printf ("%d + %d = %d\n", i, j, i + j);
    i = -3;
    j = -6;
    my_printf ("%d + %d = %d\n", i, j, i + j);
    my_printf ("%%d + %%d = %%d\n", i, j, i + j);

    return 0;
}

void my_printf(char *s, ...)
{
    va_list ap;
    bool percent = false;
    int digit, i, power, temp;

    va_start(ap, s);

    while (*s)
    {
        if (percent)
        {
            if (*s == 'd')
            {
                i = va_arg(ap, int);
                if (i < 0)
                {
                    i = -i;
                    putchar('-');
                }
                if(i > 0)
                {
                    temp = i;
                    power = 1;
                    while (temp > 9)
                    {
                        temp /= 10;
                        power *= 10;
                    }

                    do
                    {
                        digit = i / power;
                        putchar(digit + '0');
                        i -= digit * power;
                        power /= 10;
                    }
                    while (i > 0);
                }
                else
                {
                    putchar('0');
                }
                percent = false;
            }
            else
            {
                percent = false;
                if (*s == '%')
                {
                    percent = true;
                }
            }
        }
        else
        {
            if (*s == '%')
            {
                percent = true;
            }
            else
            {
                putchar(*s);
            }
        }
        s++;
    }

    va_end(ap);
}
