// sizeof.c -- ʹ��sizeof�����
// ʹ��C99������%zuת��˵�� -- �����������֧��%zu���뽫��ĳ�%u��%lu

#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 0;
    size_t intsize;

    intsize = sizeof(int);
    printf ("n = %d, n has %zu bytes; all ints have %zu bytes.\n", n, sizeof(n), intsize);

    return 0;
}
