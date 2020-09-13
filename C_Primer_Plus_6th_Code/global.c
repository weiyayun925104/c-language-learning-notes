/* global.c -- 使用外部变量 */

#include <stdio.h>

int units = 0;

void critic (void);

int main(int argc, char **argv)
{
    extern int units;

    printf ("How many pounds to a firkin of butter?\n");
    scanf ("%d", &units);
    while ( units !=56)
    {
        critic();
    }
    printf ("You must have looked it up!\n");

    return 0;
}
void critic (void)
{
    printf ("No luck, my friend. Try again.\n");
    scanf ("%d", &units);
}
