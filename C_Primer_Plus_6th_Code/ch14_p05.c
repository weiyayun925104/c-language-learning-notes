#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 128
#define CSIZE 4
#define SCORES 3

struct name {
    char first[LEN];
    char last[LEN];
};
struct student {
    struct name person;
    float scores[SCORES];
    float mean;
};

void get_scores(struct student ar[], int lim);
void find_means(struct student ar[], int lim);
void show_class(const struct student ar[], int lim);
void show_ave(const struct student ar[], int lim);

int main(int argc, char **argv)
{
    struct student class[CSIZE] = 
    {
        [0] = { { "Flip", "Snide"} },
        [1] = { { "Clare", "Voyans"} },
        [2] = { { "Bingo", "Higgs"} },
        [3] = { { "Fawn", "Hunter"} }
    };

    get_scores(class, CSIZE);
    find_means(class, CSIZE);
    show_class(class, CSIZE);
    show_ave(class, CSIZE);

    return 0;
}

void get_scores(struct student ar[], int lim)
{
    int i, j;

    for (i = 0; i < lim; i++)
    {
        printf("Please enter %d scores for %s %s\n", SCORES, ar[i].person.first, ar[i].person.last);
        for (j = 0; j < SCORES; j++)
        {
            printf("Please enter score %d (numeric input) : ", j);
            while ( scanf("%f", & (ar[i].scores[j]) ) != 1 )
            {
                while ( getchar() != '\n' )
                {
                    continue;
                }
                printf("Please enter score %d (numeric input) : ", j);
            }
        }
    }
}

void find_means(struct student ar[], int lim)
{
    int i, j;
    float sum;

    for (i = 0; i < lim; i++)
    {
        for (sum = 0.0f, j = 0; j < SCORES; j++)
        {
            sum += ar[i].scores[j];
        }
        ar[i].mean = sum / SCORES;
    }
}

void show_class(const struct student ar[], int lim)
{
    int i, j;
    char wholename[2*LEN];

    for (i = 0; i < lim; i++)
    {
        strcpy(wholename, ar[i].person.first);
        strcat(wholename, " ");
        strcat(wholename, ar[i].person.last);
        printf("%27s: ", wholename);
        for (j = 0; j < SCORES; j++)
        {
            printf("%6.2f ", ar[i].scores[j]);
        }
        printf("\nAverage = %6.2f\n", ar[i].mean);
    }
}

void show_ave(const struct student ar[], int lim)
{
    int i, j;
    float total;

    printf("\n%27s: ", "QUIZ AVERAGES");
    for (j = 0; j < SCORES; j++)
    {
        for (total = 0.0f, i = 0; i < lim; i++)
        {
            total += ar[i].scores[j];
        }
        printf("%6.2f ", total / lim);
    }
    for (total = 0.0f, i = 0; i < lim; i++)
    {
        total += ar[i].mean;
    }
    printf("\n     All = %6.2f\n", total / lim);
}
