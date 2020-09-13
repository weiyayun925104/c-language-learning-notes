#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN         128
#define FLIGHTS      4
#define FLIGHTS_CHOICES   5
#define CHOICES    7
#define SEATS       12
#define EMPTY        0
#define TAKEN        1
#define CONFIRM      1
#define UNCONFIRMED  0
#define CONTINUE     1
#define DONE         0

struct planestats {
    int seat_id;
    int status;
    int confirmation;
    char last[STRLEN];
    char first[STRLEN];
};

struct flightstats {
    struct planestats plane_1[SEATS];
    struct planestats * ps[SEATS];
    int flight_id;
};

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

int topmenu(void);
int getmenu(void);
int getlet(const char *);
int openings(const struct planestats [], int);
void show_empties(const struct planestats [], int);
void list_assign(struct planestats *[], int);
void assign_seat(struct planestats [], int);
void delete_seat(struct planestats [], int);
void show_seats(const struct planestats [], int);
void sort(struct planestats *[], int);
void makelist(const struct planestats [], char *, int);
void confirm_seat(struct planestats [], int);

int main(int argc, char **argv)
{
    struct flightstats flights[FLIGHTS];
    int flight_choice;
    int choice;
    int i, j;
    FILE *fp;
    size_t size = sizeof(struct planestats);

    for (j = 0; j < FLIGHTS; j++)
    {
        for (i = 0; i < SEATS; i++)
        {
            flights[j].ps[i] = & (flights[j].plane_1[i]);
        }
    }
    if ( ( fp = fopen("air.dat", "r+b") ) == NULL )
    {
        for (j = 0; j < FLIGHTS; j++)
        {
            for (i = 0; i < SEATS; i++)
            {
                flights[j].plane_1[i].status = EMPTY;
                flights[j].plane_1[i].confirmation = UNCONFIRMED;
                flights[j].plane_1[i].seat_id = i + 1;
            }
        }
    }
    else
    {
        for (j = 0; j < FLIGHTS; j++)
        {
            fread(flights[j].plane_1, size, SEATS, fp);
        }
        fclose(fp);
    }
    while ( ( flight_choice = topmenu() ) != 'q' )
    {
        int index;
        switch (flight_choice)
        {
            case '1': index = 0;    break;
            case '3': index = 1;    break;
            case '4': index = 2;    break;
            case '5': index = 3;    break;
            default : printf ("flight_choice = %c\n", flight_choice); index = 0; break;
        }
        while ( ( choice = getmenu() ) != 'q' )
        {
            switch (choice)
            {
                case 'o': printf("There are %d empty seats.\n", openings(flights[index].plane_1, SEATS) );
                          break;
                case 'e': show_empties(flights[index].plane_1, SEATS);
                          break;
                case 'l': if (openings(flights[index].plane_1, SEATS) == SEATS)
                           {
                               puts("All seats are empty.");
                           }
                          else
                          {
                              list_assign(flights[index].ps, SEATS);
                          }
                          break;
                case 'a': assign_seat(flights[index].plane_1, SEATS);
                          break;
                case 'd': delete_seat(flights[index].plane_1, SEATS);
                          break;
                case 'c': confirm_seat(flights[index].plane_1, SEATS);
                          break;
                default : break;
            }
        }
    }
    if ( ( fp = fopen("air.dat", "w+b") ) == NULL )
    {
        fprintf(stderr, "Can not open air.dat for output\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (j = 0; j < FLIGHTS; j++)
        {
            fwrite(flights[j].plane_1, size, SEATS, fp);
        }
        fclose(fp);
    }
    puts("Bye from Colossus Airlines!");

    return 0;
}
int topmenu(void)
{
    const char *descript[FLIGHTS_CHOICES] = {
        "102",
        "311",
        "444",
        "519",
        "Quit"
    };
    const char labels[FLIGHTS_CHOICES + 1] = "1345q";
    int i;

    puts("To choose a flight, enter its letter label");
    for (i = 0; i < FLIGHTS_CHOICES; i++)
    {
        printf("%c) %s\n", labels[i], descript[i]);
    }

    return getlet(labels);
}
int getmenu(void)
{
    const char *descript[CHOICES] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seat assignments",
        "Assign a customer to a seat",
        "Delete a seat assignment",
        "Confirm a seat assignment",
        "Exit to the top-level menu"
    };
    const char labels[CHOICES + 1] = "oeladcq";
    int i;

    puts("To choose a function, enter its letter label");
    for (i = 0; i < CHOICES; i++)
    {
        printf("%c) %s\n", labels[i], descript[i]);
    }

    return getlet(labels);
}
int getlet (const char * s)
{
    int c;

    c= getchar();
    while (strchr(s, c) == NULL)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        printf("Enter a character in the list %s\n", s);
        c = getchar();
    }
    while (getchar() != '\n')
    {
        continue;
    }

    return c;
}
int openings(const struct planestats pl[], int n)
{
    int count = 0;
    int seat;

    for (seat = 0; seat < n; seat++)
    {
        if ( pl[seat].status == EMPTY )
        {
            count++;
        }
    }

    return count;
}
void show_empties(const struct planestats pl[], int n)
{
    char seating[16 * SEATS];

    if (openings(pl, n) == 0)
    {
        puts("All seats are assigned");
    }
    else
    {
        puts("The following seats are available:");
        makelist(pl, seating, EMPTY);
        puts(seating);
    }
}
void makelist(const struct planestats pl[], char * str, int kind)
{
    int seat;
    char temp[STRLEN] = {0};

    str[0] = '\0';
    for (seat = 0; seat < SEATS; seat++)
    {
        if (pl[seat].status == kind)
        {
            sprintf(temp, " %d", pl[seat].seat_id);
            strcat(str, temp);
        }
    }
}
void list_assign(struct planestats *ps[], int n)
{
    int i;

    sort(ps, n);
    for (i = 0; i < SEATS; i++)
    {
        if (ps[i]->status == TAKEN)
        {
            printf("Seat %d: %s, %s   ", ps[i]->seat_id, ps[i]->last, ps[i]->first);
            if (ps[i]->confirmation == CONFIRM)
            {
                printf ("confirmed\n");
            }
            else
            {
                printf ("unconfirmed\n");
            }
        }
    }
}
void assign_seat(struct planestats pl[], int n)
{
    char list[16 * SEATS];
    int seat, loop;
    int i;
    int  len;

    if (openings(pl, n) == 0)
    {
        puts("All seats are assigned.");
    }
    else
    {
        makelist(pl, list, EMPTY);
        puts("Which seat do you want? Choose from this list:");
        puts(list);
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                while (getchar() != '\n')
                {
                    continue;
                }
                puts("Enter a number from this list:");
                puts(list);
            }
            while (getchar() != '\n')
            {
                continue;
            }
            for (i = 0; i < SEATS; i++)
            {
                if(pl[i].seat_id == seat && pl[i].status == EMPTY)
                {
                    break;
                }
            }
            if (i >= SEATS)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
            {
                loop = DONE;
            }
        } while (loop == CONTINUE);
        puts("Enter first name:");
        len = read_line_file(pl[i].first, 80, stdin);
        puts("Enter last name:");
        len = read_line_file(pl[i].last, 80, stdin);
        printf("%s, %s assigned to seat %d.\n", pl[i].last, pl[i].first, seat);

        puts("Enter a to accept assignment, c to cancel it.");
        if (getlet("ac") == 'a')
        {
            pl[i].status = TAKEN;
            puts("Passenger assigned to seat.");
        }
        else
        {
            puts("Passenger not assigned.");
        }
    }
}
void delete_seat(struct planestats pl[], int n)
{
    int seat, loop;
    int i;
    char list[16 * SEATS];

    if (openings(pl, n) == SEATS)
    {
        puts("All seats already are empty.");
    }
    else
    {
        show_seats(pl, n);
        makelist(pl, list, TAKEN);
        puts("Which seat do you want to be cancelled? Choose from this list:");
        puts(list);
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                while (getchar() != '\n')
                {
                    continue;
                }
                puts("Enter a number from this list:");
                puts(list);
            }
            while (getchar() != '\n')
            {
                continue;
            }
            for (i = 0; i < SEATS; i++)
            {
                if(pl[i].seat_id == seat && pl[i].status == TAKEN)
                {
                    break;
                }
            }
            if (i >= SEATS)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
            {
                loop = DONE;
            }
        } while (loop == CONTINUE);
        printf("%s, %s to be cancelled for seat %d.\n", pl[i].last, pl[i].first, seat);
        puts("Enter d to delete assignment, a to abort.");
        if (getlet("da") == 'd')
        {
            pl[i].status = EMPTY;
            puts("Passenger dropped.");
        }
        else
        {
            puts("Passenger retained.");
        }
    }
}
void show_seats(const struct planestats pl[], int n)
{
    int i;

    puts("Seats currently taken:");
    for (i = 0; i < SEATS; i++)
    {
        if (pl[i].status == TAKEN)
        {
            printf("Seat %d: %s, %s   ", pl[i].seat_id, pl[i].last, pl[i].first);
            if (pl[i].confirmation == CONFIRM)
            {
                printf ("confirmed\n");
            }
            else
            {
                printf ("unconfirmed\n");
            }
        }
    }
}
void sort(struct planestats *array[], int limit)
{
    int top, search;
    struct planestats * temp;

    for (top = 0; top < limit - 1; top++)
    {
        for (search = top + 1; search < limit; search++)
        {
            if (strcmp(array[top]->last, array[search]->last) > 0)
            {
                temp = array[search];
                array[search] = array[top];
                array[top] = temp;
            }
        }
    }
}
void confirm_seat(struct planestats pl[], int n)
{
    int seat, loop;
    int i;
    char list[16 * SEATS];

    if (openings(pl, n) == SEATS)
    {
        puts("All seats already are empty.");
    }
    else
    {
        show_seats(pl, n);
        makelist(pl, list, TAKEN);
        puts("Which seat do you want to be confirmed? Choose from this list:");
        puts(list);
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                while (getchar() != '\n')
                {
                    continue;
                }
                puts("Enter a number from this list:");
                puts(list);
            }
            while (getchar() != '\n')
            {
                continue;
            }
            for (i = 0; i < SEATS; i++)
            {
                if(pl[i].seat_id == seat && pl[i].status == TAKEN)
                {
                    break;
                }
            }
            if (i >= SEATS)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
            {
                loop = DONE;
            }
        } while (loop == CONTINUE);
        printf("%s, %s to be confirmed for seat %d.\n", pl[i].last, pl[i].first, seat);
        puts("Enter c to delete assignment, a to abort.");
        if (getlet("ca") == 'c')
        {
            pl[i].confirmation = CONFIRM;
            puts("Passenger confirmed to seat.");
        }
        else
        {
            puts("Passenger not confirmed.");
        }
    }
}
int read_char (FILE *fp)
{
    int ch = getc(fp);
    if (ch == '\n' || ch == '\t')
    {
        return ' ';
    }
    return ch;
}
int read_word(char *word, int len, FILE *fp)
{
    int ch, pos = 0;
    while ( ( ch = read_char(fp) ) == ' ')
        ;
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
        {
            word[pos++] = ch;
        }
        ch = read_char(fp);
    }
    word[pos] = '\0';
    return pos;
}
int read_line_file(char str[], int n, FILE *fp)
{
    int ch, i = 0;

    while ( isspace ( ch = getc(fp) ) )
        ;
    while ( ch != '\n' && ch != EOF)
    {
        if (i < n)
        {
            str[i++] = ch;
        }
        ch = getc(fp);
    }
    str[i] = '\0';
    return i;
}
