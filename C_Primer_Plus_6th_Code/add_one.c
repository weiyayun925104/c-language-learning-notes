/* add_one.c --����: ǰ׺�ͺ�׺ */

#include <stdio.h>

int main(int argc, char **argv)
{
    int ultra = 0, super = 0;

    while (super < 5)
    {
        super++;
        ++ultra;
        printf ("super = %d, ultra = %d\n", super, ultra);
    }

    return 0;
}
