#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void random_pick(int ar[], int arsize, int picks);

#define SPOTS 51
#define PICKS 6

int main(int argc, char **argv)
{
    int lotto[SPOTS];
    int i;
    int ch;

    for (i = 0; i < SPOTS; i++)
    {
        lotto[i] = i + 1;
    }

    do
    {
        random_pick(lotto, SPOTS, PICKS);
        printf("Again? <y/n> ");
        ch = getchar();
        while (getchar() != '\n')
        {
            continue;
        }
    } while (ch == 'y' || ch == 'Y');
    printf ("Done.\n");

    return 0;
}

void random_pick(int ar[], int arsize, int picks)
{
    int i, index, temp;
    int arrayTemp[arsize];

    memcpy(arrayTemp, ar, arsize * sizeof (int) );
    srand ( (unsigned int) time (NULL) );
    if (picks > arsize)
    {
        fprintf (stderr, "Number of picks > array size\n");
        fprintf (stderr, "Setting picks = array size\n");
        picks = arsize;
    }
    for (i = 0; i < picks; i++)
    {
        if(arsize > 1)
        {
            index = rand() % (arsize - 1);
        }
        else
        {
            index = 0;
        }
        temp = arrayTemp[index];
        printf("%d ", temp);
        if (i % 20 == 19)
        {
            putchar('\n');
        }
        if(arsize > 1)
        {
            arrayTemp[index] = arrayTemp[arsize - 1];
            arrayTemp[arsize - 1] = temp;
        }
        arsize--;
    }
    if (i % 20 != 0)
    {
        putchar('\n');
    }
}
