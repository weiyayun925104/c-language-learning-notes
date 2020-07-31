#ifndef LINE_H
#define LINE_H

void clear_line(void);

void add_word (const char *word, FILE *fpin, FILE *fpout);

int space_remaining(void);

void write_line(FILE *fp);

void flush_line(FILE *fp);

#endif
