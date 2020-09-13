#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct player {
    int number;
    char first_name[128];
    char last_name[128];
    int at_bats;
    int hits;
    int walks;
    int RBIs;
    float batting_average;
};

int main(int argc, char **argv)
{
    FILE * fp;

    if ( ( fp = fopen("ch14_p06.txt", "r") ) == NULL)
    {
        fprintf(stderr, "Could not open data file.\n");
        exit(EXIT_FAILURE);
    }

    struct player team[20];
    for (int m = 0; m < 20; m++)
    {
        team[m].number = -1;
        team[m].at_bats = 0;
        team[m].hits = 0;
        team[m].walks = 0;
        team[m].RBIs = 0;
    }

    int j = 0;
    int number;
    int exist;
    char first_name[128] = {0};
    char last_name[128] = {0};
    int at_bats;
    int hits;
    int walks;
    int RBIs;

    while (fscanf(fp, "%d %s %s %d %d %d %d",
                        &number,
                        first_name,
                        last_name,
                        &at_bats,
                        &hits,
                        &walks,
                        &RBIs) == 7)
    {
        exist = 0;
        for (int i = 0; i < 20; i++)
        {
            if (team[i].number == number)
            {
                exist = 1;
                team[i].at_bats += at_bats;
                team[i].hits += hits;
                team[i].walks += walks;
                team[i].RBIs += RBIs;
                break;
            }
        }

        if (exist == 0)
        {
            team[j].number = number;
            strcpy(team[j].first_name, first_name);
            strcpy(team[j].last_name, last_name);
            team[j].at_bats += at_bats;
            team[j].hits += hits;
            team[j].walks += walks;
            team[j].RBIs += RBIs;
            j++;
        }
    }

    int total_at_bats = 0;
    int total_hits = 0;
    int total_walks = 0;
    int total_RBIs = 0;

    for (int k = 0; k < j; k++)
    {
        team[k].batting_average = (float) (team[k].hits) / (float) (team[k].at_bats);
        printf("%d %s %s %d %d %d %d %f\n",
            team[k].number,
            team[k].first_name,
            team[k].last_name,
            team[k].at_bats,
            team[k].hits,
            team[k].walks,
            team[k].RBIs,
           team[k].batting_average);
        total_at_bats += team[k].at_bats;
        total_hits += team[k].hits;
        total_walks += team[k].walks;
        total_RBIs += team[k].RBIs;
    }

    printf("%d %d %d %d %f\n",
            total_at_bats,
            total_hits,
            total_walks,
            total_RBIs,
            (double) total_hits / total_at_bats);

    return 0;
}
