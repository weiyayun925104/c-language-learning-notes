#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 60

int line_len = 0;
int num_words = 0;
bool more_space_toggle = false;

struct node
{
    struct node *next;
    char word[];
};
struct node *line = NULL;

void clear_line(void)
{
    struct node *p, *q;
    p = line;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    line = NULL;
    line_len = 0;
    num_words = 0;
    more_space_toggle = false;
}

void add_word(const char *word, FILE *fpin, FILE *fpout)
{
    struct node *new_word, **list, *item;
    if ( ( new_word = malloc( sizeof(struct node) + strlen(word) + 1) ) == NULL )
    {
        printf("Error: malloc failed\n");
        fclose(fpin);
        fclose(fpout);
        exit(EXIT_FAILURE);
    }
    strcpy(new_word->word, word);
    new_word->next = NULL;

    list = &line;
    item = line;
    while (item != NULL)
    {
        list = &(item->next);
        item = item->next;
    }
    *list = new_word;
    line_len += strlen(word);
    if (num_words > 0)
    {
        line_len++;
    }
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(FILE *fp)
{
    int extra_spaces, spaces_to_insert, i;
    int char_count = 0;
    struct node *entry = line;
    more_space_toggle = !more_space_toggle;
    extra_spaces = MAX_LINE_LEN - line_len;

    while (char_count < line_len && entry != NULL)
    {
        fprintf(fp, "%s", entry->word);
        if (num_words > 1)
        {
            spaces_to_insert = extra_spaces / (num_words - 1);
            if (more_space_toggle && extra_spaces > 0 && (spaces_to_insert + 1) < extra_spaces)
            {
                spaces_to_insert++;
                more_space_toggle = !more_space_toggle;
            }
            for (i = 1; i <= spaces_to_insert + 1; i++)
            {
                putc(' ', fp);
            }
            extra_spaces -= spaces_to_insert;
        }
        char_count += strlen(entry->word) + 1;
        num_words--;
        entry = entry->next;
    }
    putc('\n', fp);
}

void flush_line(FILE *fp)
{
    struct node *entry;
    if (line_len > 0)
    {
        for (entry = line; entry != NULL; entry = entry->next)
        {
            fprintf(fp, "%s", entry->word);
            if (entry->next != NULL)
            {
                putc(' ', fp);
            }
        }
    }
    fprintf(fp, "\n");
    clear_line();
}
