#include <stdio.h>

void showmenu (void);
int getchoice (int low, int high);

int main(int argc, char **argv)
{
    int choice;

    showmenu();
    while ( ( choice = getchoice (1, 4) ) != 4)
    {
        printf ("choice %d.\n", choice);
        showmenu();
    }
    printf ("Done.\n");

    return 0;
}
void showmenu (void)
{
    printf ("Please choose one of the following: \n");
    printf ("1) copy files           2) move files\n");
    printf ("3) remove files       4) quit\n");
    printf ("Enter the number of your choice: \n");
}
int getchoice (int low, int high)
{
    int choice, status;
    int input;

    while ( ( status = scanf ("%d", &choice) ) != 1 || (choice < low || choice > high) )
    {
        if (status != 1)
        {
            while ( ( input = getchar() ) != '\n' )
            {
                putchar(input);
            }
            printf(" is not an integer.\n");
            choice = 4;
            return choice;
        }
        else
        {
            while ( getchar() != '\n' )
            {
                continue;
            }
            printf("Please enter an integer from %d to %d: ", low, high);
        }
    }
    while ( getchar() != '\n' )
    {
        continue;
    }

    return choice;
}
