// sizeof.c -- 使用sizeof运算符
// 使用C99新增的%zu转换说明 -- 如果编译器不支持%zu，请将其改成%u或%lu

#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 0;
    size_t intsize;

    intsize = sizeof(int);
    printf ("n = %d, n has %zu bytes; all ints have %zu bytes.\n", n, sizeof(n), intsize);

    return 0;
}
