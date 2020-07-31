/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line (char str[], int n);
int read_line_two (char str[], int n);

int main(int argc, char **argv)
{
    char reminders[MAX_REMIND][2 + MSG_LEN + 1];
    char day_str[2 + 1], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;
    for (; ; )
    {
        if (num_remind == MAX_REMIND)
        {
            printf ("-- No space left --\n");
            break;
        }
        printf ("Enter day and reminder: ");
        i = scanf ("%2d", &day);
        if (i == 0 || day == 0)
        {
            break;
        }
        sprintf (day_str, "%2d", day);
        read_line_two (msg_str, MSG_LEN);
        for (i = 0; i < num_remind; i++)
        {
            if (strcmp (day_str, reminders[i]) < 0)
            {
                break;
            }
        }
        for (j = num_remind; j > i; j--)
        {
            strcpy (reminders[j], reminders[j - 1]);
        }
        strcpy (reminders[i], day_str);
        strcat (reminders[i], msg_str);
        num_remind++;
    }
    printf ("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
    {
        printf ("%s\n", reminders[i]);
    }
    return 0;
}
int read_line (char str[], int n)
{
    int ch, i = 0;
    while ( (ch = getchar() ) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
int read_line_two(char str[], int n)
{
    int ch, i = 0;

    while ( isspace( ( ch = getchar() ) ) )
        ;
    if( i < n && ch != '\n' && !isspace(ch) )
    {
        str[i++] = ch;
    }
    while (i < n && ( ch = getchar() ) != '\n' && !isspace(ch) )
    {
        str[i++] = ch;
    }
    if (ch == '\n' && i < n)
    {
        str[i++] = '\n';
    }
    str[i] = '\0';
    return i;
}
