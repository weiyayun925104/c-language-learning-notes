#include <stdio.h>

int count_ones_1 (unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    return count_ones_1(n & n - 1) + 1;
}

int count_ones_2 (unsigned int n)
{
    int ones = 0;
    while (n > 0)
    {
        ones += ( 1 & n);
        n >>= 1;
    }
    return ones;
}

int main(int argc, char **argv)
{
    unsigned int i = 0x017f;
    printf("%d, %d\n", count_ones_1(i), count_ones_2(i) );
    return 0;
}
