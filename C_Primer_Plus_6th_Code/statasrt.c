// statasrt.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

_Static_assert (CHAR_BIT == 16, "16-bit char falsely assumed");

int main(int argc, char **argv)
{
    puts ("char is 16 bits.");

    return 0;
}
