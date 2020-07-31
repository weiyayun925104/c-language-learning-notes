#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000

int compare_intnums (const void *p, const void *q);

int main(int argc, char **argv)
{
    FILE *fp;
    int nums[MAX_NUMS];
    int amount = 0, median;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( ( fp = fopen(argv[1], "r") ) == NULL )
    {
        fprintf(stderr, "Error: file %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (amount < MAX_NUMS)
    {
        if ( fscanf(fp, " %d", &nums[amount]) != 1)
        {
            if ( ferror (fp) )
            {
                break;
            }
            if ( feof(fp) )
            {
                break;
            }
            fscanf (fp, "%*[^\n]");
        }
        else
        {
            amount++;
        }
    }
    fclose(fp);

    qsort(nums, amount, sizeof(int), compare_intnums);

    if (amount % 2 == 0)
    {
        median = (nums[(amount - 1) / 2] + nums[(amount - 1) / 2 + 1]) / 2;
    }
    else
    {
        median = nums[(amount - 1) / 2];
    }

    printf("Maximum: %d\nMinimum: %d\nMedian: %d\n", nums[amount - 1], nums[0], median);

    exit(EXIT_SUCCESS);
}

int compare_intnums (const void *p, const void *q)
{
    if ( *( (int *)p) < * ( (int *)q) )
    {
        return -1;
    }
    else if ( *( (int *)p) == *( (int *)q) )
    {
        return 0;
    }

    return 1;
}
