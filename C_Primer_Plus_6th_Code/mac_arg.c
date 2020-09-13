/* mac_arg.c -- 带参数的宏 */

#include <stdio.h>
#define SQUARE(X) ( (X) * (X) )
#define PR(X) printf ("The result is %d.\n", (X))

int main(int argc, char **argv)
{
    int x = 5;
    int z;

    printf ("x = %d\n", x);
    z = SQUARE(x);
    printf ("Evaluating SQUARE(x):\n");
    PR(z);
    z = SQUARE(2);
    printf ("Evaluating SQUARE(2):\n");
    PR(z);
    printf ("Evaluating SQUARE(x+2):\n");
    PR(SQUARE(x+2));
    printf ("Evaluating 100/SQUARE(2):\n");
    PR(100/SQUARE(2));
    printf ("x is %d.\n", x);
    printf ("Evaluating SQUARE(++x):\n");
    PR(SQUARE(++x));
    printf ("After incrementing, x is %d.\n", x);

    return 0;
}
