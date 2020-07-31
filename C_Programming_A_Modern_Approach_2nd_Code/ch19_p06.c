#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q1, q2;
    int n;

    q1 = queue_create(8);
    q2 = queue_create(8);

    queue_append_tail(q1, 4);
    queue_append_tail(q1, 8);

    n = queue_get_first(q1);
    queue_remove_head(q1);
    printf("Popped %d from q1\n", n);
    queue_append_tail(q2, n);
    n = queue_get_first(q1);
    queue_remove_head(q1);
    printf("Popped %d from q1\n", n);
    queue_append_tail(q2, n);

    queue_destroy(q1);

    while (!queue_is_empty(q2))
    {
        printf("Popped %d from q2\n", queue_get_first(q2));
        queue_remove_head(q2);
    }

    queue_append_tail(q2, 15);
    if (queue_is_empty(q2))
    {
        printf("q2 is empty\n");
    }
    else
    {
        printf("q2 is not empty\n");
    }

    queue_destroy(q2);

    return 0;
}
