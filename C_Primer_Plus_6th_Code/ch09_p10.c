#include <stdio.h>

void to_base_n(unsigned long n, unsigned long base);

int main(int argc, char **argv)
{
    unsigned long number, base;
    int status, input;

    printf("Enter an integer (q to quit):\n");
    while ( scanf ("%lu", &number) == 1)
    {
        printf("Please enter an integer (2-10): ");
        while ( ( status = scanf ("%lu", &base) ) != 1 || (base < 2 || base > 10) )
        {
            if (status != 1)
            {
                while ( ( input = getchar() ) != '\n' )
                {
                    putchar(input);
                }
                printf(" is not an integer.\n");
                printf("Please enter an integer: ");
            }
            else
            {
                while ( getchar() != '\n' )
                {
                    continue;
                }
                printf("Please enter an integer from 2 to 10: ");
            }
        }
        while ( getchar() != '\n' )
        {
            continue;
        }
        printf("Base-%u equivalent: ", base);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}
void to_base_n(unsigned long n, unsigned long base)
{
    int r;
    r = n % base;
    if (n >= base)
    {
        to_base_n(n / base, base);
    }
    putchar('0' + r);

    return;
}
