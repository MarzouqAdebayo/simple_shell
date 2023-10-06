#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prompt(char *sym);
char *read(void);

/** String util functions */
int iswhitespace(char s);
char *collapse_whitespace(char *old, char *new);
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t n);

#endif