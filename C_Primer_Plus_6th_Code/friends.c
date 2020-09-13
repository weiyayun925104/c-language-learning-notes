/* friends.c -- 使用指向结构的指针 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct names {
char first[STRLEN];
char last[STRLEN];
};

struct guy
{
    struct names handle;
    char favfood[STRLEN];
    char job[STRLEN];
    double income;
};

int main(int argc, char **argv)
{
    struct guy fellow[2] = 
    {
        { 
            { "Ewen", "Villard"}, 
            "grilled salmon", 
            "personality coach", 
            68112.00
        }, 
        { 
            { "Rodney", "Swillbelly" }, 
            "tripe", 
            "tabloid editor", 
            432400.00
        }
    };
    struct guy * him;

    printf ("address #1: %p\naddress #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf ("pointer #1: %p\npointer #2: %p\n", him, him + 1);
    printf ("him->income is $%.2f; (*him).income is $%.2f\n", him->income, (*him).income);
    him++;
    printf ("him->favfood is %s; him->handle.last is %s\n", him->favfood, him->handle.last);

    return 0;
}
