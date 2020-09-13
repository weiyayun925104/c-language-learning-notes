/* post_pre.c -- ǰ׺�ͺ�׺ */

#include <stdio.h>

int main(int argc, char **argv)
{
    int a = 1, b = 1;
    int a_post, pre_b;

    a_post = a++;
    pre_b = ++b;
    printf ("a         a_post         b         pre__b\n");
    printf ("%9d %9d %9d %9d\n", a, a_post, b, pre_b);

    return 0;
}
