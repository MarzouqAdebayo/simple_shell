#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prompt(char *sym);
char *_read_fn(void);
char **_parse(char *str);

/** String util functions */
int iswhitespace(char s);
char *collapse_whitespace(char *old, char *new);
char **split_str(char *src, const char delimiter);
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t n);

/** Memory util functions */
void free2DArray(char **arr);

#endif