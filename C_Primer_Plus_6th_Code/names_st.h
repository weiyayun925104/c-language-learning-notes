// names_st.h -- names_st结构的头文件

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 128

struct names_st
{
    char first[STRLEN];
    char last[STRLEN];
};

typedef struct names_st names;

int read_char (FILE *fp);
int read_word(char *word, int len, FILE *fp);
int read_line_file(char str[], int n, FILE *fp);

void get_names (names *);
void show_names (const names *);
