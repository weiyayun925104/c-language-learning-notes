/* skiptwo.c -- 跳过输入中的前两个整数 */

#include <stdio.h>

int main(int argc, char **argv)
{
    int n;
    printf ("Please enter three integers: ");
    scanf ("%*d %*d %d", &n);
    printf ("The last integer was %d\n", n);

    return 0;
}
