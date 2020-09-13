#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 6

typedef struct names {
    char first[128];
    char last[128];
} NAME;

void showarray(const NAME ar[], int n);
int comp(const void * p1, const void * p2);

int main(int argc, char **argv)
{
    NAME staff[NUM] = 
    {
        {"YAYUN", "WEI"},
        {"World", "Hello"},
        {"Hello", "WEI"},
        {"World", "WEI"},
        {"YAYUN", "Hello"},
        {"Hello", "YAYUN"}
    };

    puts("Before sorted list:");
    showarray(staff, NUM);
    qsort(staff, NUM, sizeof(NAME), comp);
    puts("\nSorted list:");
    showarray(staff, NUM);

    return 0;
}

void showarray(const NAME ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%s %s\n", ar[index].first, ar[index].last);
    }
}
int comp (const void * p1, const void * p2)
{
    NAME * ps1 = (NAME *) p1;
    NAME * ps2 = (NAME *) p2;
    int res;

    res = strcmp (ps1->last, ps2->last);
    if (res != 0)
    {
        return res;
    }
    else
    {
        res = strcmp (ps1->first, ps2->first);
        return res;
    }
}
