/* use_q.c -- 驱动程序测试Queue接口 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

int getlet (const char * s);

int main(int argc, char **argv)
{
    Queue line;
    Item temp;
    int ch;

    InitializeQueue (&line);
    puts ("Testing the Queue interface. Type a to add a value, ");
    puts ("type d to delete a value, and type q to quit.");
    while ( ( ch = getlet("adq") ) != 'q' )
    {
        if (ch == 'a')
        {
            printf ("Integer to add: ");
            scanf ("%d", &temp);
            while ( getchar() != '\n' )
            {
                continue;
            }
            if ( !QueueIsFull (&line) )
            {
                printf ("Putting %d into queue.\n", temp);
                EnQueue (temp, &line);
            }
            else
            {
                puts ("Error, Queue is full.");
            }
        }
        else
        {
            if ( QueueIsEmpty (&line) )
            {
                puts ("Error, Queue is empty.");
            }
            else
            {
                DeQueue (&temp, &line);
                printf ("Removing %d from queue.\n", temp);
            }
        }
        printf ("%d items in queue.\n", QueueItemCount (&line) );
        puts ("Type a to add, d to delete, q to quit:");
    }
    EmptyTheQueue (&line);
    printf ("Done.\n");

    return 0;
}
int getlet (const char * s)
{
    int c;

    c= getchar();
    while (strchr(s, c) == NULL)
    {
        printf("Enter a character in the list %s\n", s);
        while (getchar() != '\n')
        {
            continue;
        }
        c = getchar();
    }
    while (getchar() != '\n')
    {
        continue;
    }

    return c;
}
