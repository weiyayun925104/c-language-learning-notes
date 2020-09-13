/* complit.c -- ¸´ºÏ×ÖÃæÁ¿ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct book
{
    char title[STRLEN];
    char author[STRLEN];
    double value;
};

int main(int argc, char **argv)
{
    struct book readfirst;
    int score;

    printf ("Enter test score: ");
    scanf ("%d", &score);
    if (score >= 84)
    {
        readfirst = ( struct book ) {"Crime and Punishment", "Fyodor Dostoyevsky", 11.25};
    }
    else
    {
        readfirst = ( struct book ) {"Mr.Bouncy's Nice Hat", "Fred Winsome", 5.99};
    }
    printf ("Your assigned reading:\n");
    printf ("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

    return 0;
}
