/* loccheck.c -- 查看变量被储存在何处 */

#include <stdio.h>

void mikado (int bah);

int main(int argc, char **argv)
{
    int pooh = 2, bah = 5;

    printf ("In main, pooh =%d and &pooh = %p\n", pooh, &pooh);
    printf ("In main, bah = %d and &bah = %p\n", bah, &bah);
    mikado (bah);

    return 0;
}
void mikado (int bah)
{
    int pooh = 10;

    printf ("In mikado, pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf ("In mikado, bah = %d and &bah = %p\n", bah, &bah);
}
