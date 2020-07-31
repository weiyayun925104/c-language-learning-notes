#include <stdio.h>

unsigned int f(unsigned int i, int m, int n)
{
    return ( i >> (m + 1 - n) ) & ~(~0 << n);
}

int main(int argc, char **argv)
{
    unsigned int i = 0x017f;
    printf("%x\n", f(i, 8, 5) );
    return 0;
}
