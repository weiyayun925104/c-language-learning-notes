#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollem(int sides);

int main(int argc, char **argv)
{
    int dice, count, roll;
    int sides;
    int set, sets;
    int ret, status;

    srand( (unsigned int) time(NULL) );

    printf("Enter the number of sets; enter q to stop: ");
    while ( ( ret = scanf("%d", &sets) ) == 1 )
    {
        printf("How many sides and how many dice? ");
        if ( ( status = scanf("%d %d", &sides, &dice) ) != 2 )
        {
            puts("not integers -- terminating input loop.");
            break;
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (set = 0; set < sets; set++)
        {
            for (roll = 0, count = 0; count < dice; count++)
            {
                roll += rollem(sides);
            }
            printf("%4d ", roll);
            if (set % 15 == 14)
            {
                putchar('\n');
            }
        }
        if (set % 15 != 0)
        {
            putchar('\n');
        }
        printf("How many sets? Enter q to stop: ");
    }
    printf("Done.\n");

    return 0;
}
int rollem (int sides)
{
    int roll;

    roll = ( rand() % sides ) + 1;

    return roll;
}
