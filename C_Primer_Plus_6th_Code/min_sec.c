// min_sec.c -- ������ת���ɷֺ���

#include <stdio.h>

#define SEC_PER_MIN 60

int main(int argc, char **argv)
{
    int sec, min, left;
    printf ("Convert seconds to minutes and seconds!\n");
    printf ("Enter the number of seconds (<=0 to quit): ");
    scanf ("%d", &sec);
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;
        left = sec % SEC_PER_MIN;
        printf ("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
        printf ("Enter the number of seconds (<=0 to quit): ");
        scanf ("%d", &sec);
    }
    printf ("Done!\n");

    return 0;
}
