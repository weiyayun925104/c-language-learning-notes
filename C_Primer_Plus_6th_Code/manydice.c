/* manydice.c -- 多次掷骰子的模拟程序 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(int argc, char **argv)
{
    int dice, roll;
    int sides;
    int ret;
    int status;

    srand ( (unsigned int) time (NULL) );
    printf ("Enter the number of sides per dice, 0 to stop.\n");
    while ( ( ret = scanf ("%d", &sides) ) == 1 && sides > 0 )
    {
        printf ("How many dice?\n");
        if ( ( status = scanf ("%d", &dice) ) != 1 )
        {
            if (status == EOF)
            {
                break;
            }
            else
            {
                while ( getchar() != '\n')
                {
                    continue;
                }
                printf ("You should have entered an integer.");
                printf ("Let's begin again.\n");
                printf ("Enter the number of sides per dice, 0 to stop.\n");
                continue;
            }
        }
        roll = roll_n_dice (dice, sides);
        printf ("You have rolled a %d using %d %d-side dice.\n", roll, dice, sides);
        printf ("Enter the number of sides per dice, 0 to stop.\n");
    }
    printf ("The rollem function was called %d times.\n", roll_count);
    printf ("Done.\n");

    return 0;
}
