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

void prompt(char *sym);
char *_read_fn(void);
char **_parse(char *str);
void _execute(char **args);
int run_command(char *command, char **args, char **env_vars);

/** String util functions */
int iswhitespace(char s);
char *collapse_whitespace(char *old);
char **split_str(char *src, const char delimiter);
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strtok(char *str, const char *delim);
int _atoi(char *s);

/** Memory util functions */
void free2DArray(char **arr);

/** Print util functions */
int _putchar(char c);
void _puts(char *str);
void print_positive_number(int n);
void print_number(int n);
void print_error(int line_no, char *cmd, char *msg, int *code);

/** Env utils */
char *_getenv(const char *name);
int *_setenv(void);
char *path_with_current(char *path);
int use_path(char *cmd_path);

/** Read utils */
ssize_t _getline(char **lineptr, size_t *n, int fd);

/**  */
int build_path(char **new_str, char *path, char *name);

/** Built-ins */
int check_builtin(char *command);
void print_env();
void _exit_(char *str);

#endif