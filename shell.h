#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
extern char shell_name[30];
extern int line_no;

char *_read_fn(void);
char **_parse(char *str);
void _execute(char **args);
int run_command(char *command, char **args, char **env_vars);
int check_builtin(char *command);

/** Read util functions */
ssize_t _getline(char **lineptr, size_t *n, int fd);

/** Parse util functions */
int iswhitespace(char s);
char *collapse_whitespace(char *old);
char **split_str(char *src, const char delimiter);

/** Stream util functions */
void prompt(char *sym);

/** String util functions */
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strtok(char *str, const char *delim);
int _atoi(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);

/** Memory util functions */
void free2DArray(char **arr);

/** Print util functions */
int _putchar(char c);
void _puts(char *str);
void print_positive_number(int n);
void print_number(int n);
void print_error(char *cmd, char *msg, int *code);

/** Environment util functions */
char *_getenv(const char *name);
int *_setenv(void);

/** Path util functions */
int join_path(char **new_str, char *path, char *name);
char *path_with_current(char *path);
int use_path(char *cmd_path);

/** Built-ins commands functions */
void print_env(void);
void _exit_(char *str);

#endif