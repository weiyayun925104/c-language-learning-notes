#include <stdio.h>

unsigned int reverse_bits(unsigned int n)
{
    int i;
    int len = ( sizeof(unsigned int) * 8 );
    for (i = 0; i < (len / 2); i++)
    {
        if ( ( ( n >> ( len - 1 - i ) ) & 1) != ( (n >> i) & 1 ) )
        {
            n ^= ( ( 1 << ( len - 1 - i ) ) | ( 1 << i ) );
        }
    }
    return n;
}

int main(int argc, char **argv)
{
    unsigned int i = 0x017f;
    printf("%.8X\n", reverse_bits(i) );
    return 0;
}

