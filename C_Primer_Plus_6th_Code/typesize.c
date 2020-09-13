/* typesize.c -- 打印类型大小 */

#include <stdio.h>

int main(int argc, char **argv)
{
    printf ("Type char has a size of %zu bytes.\n", sizeof(char) );
    printf ("Type short has a size of %zu bytes.\n", sizeof(short) );
    printf ("Type int has a size of %zu bytes.\n", sizeof(int) );
    printf ("Type long has a size of %zu bytes.\n", sizeof(long) );
    printf ("Type long long has a size of %zu bytes.\n", sizeof(long long) );
    printf ("Type float has a size of %zu bytes.\n", sizeof(float) );
    printf ("Type double has a size of %zu bytes.\n", sizeof(double) );
    printf ("Type long double has a size of %zu bytes.\n", sizeof(long double) );

    return 0;
}
