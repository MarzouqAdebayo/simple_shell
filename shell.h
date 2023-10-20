#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct list_s - singly linked list to hold environment variables
 * @var: environment variable string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *var;
	struct list_s *next;
} list_t;

/** linked_list utils */
void initialize_env(void);
list_t **get_head(void);
void free_list(void);
list_t *add_node(list_t **head, const char *var);
list_t *add_node_end(list_t **head, const char *var);
int print_list(void);
int list_len(void);
int delete_node(list_t **head, char *name);
char *get_node_var(const char *name);
char **build_env_array();

/** getters and setters */
char *get_shell_name(void);
void set_shell_name(char *shell_name);
int get_line_no(void);
void set_line_no(void);
int get_status(void);
void set_status(int status);

/** Main shell functions */
char *_read_fn(void);
char **_parse(char *str);
void _execute(char **args);
int run_command(char *command, char **args);
int check_builtin(char *command);

/** Read util functions */
ssize_t _getline(char **lineptr, int *n, int fd);

/** Parse util functions */
int iswhitespace(char s);
char *collapse_whitespace(char *old);
char **split_str(char *src, const char delimiter);

/** Stream util functions */
void prompt(char *sym);

/** String util functions */
int _strlen(const char *str);
char *_strncpy(char *dest, const char *src, int n);
char *_strtok(char *str, const char *delim);
int _atoi(char *s);
int _strncmp(const char *s1, const char *s2, int n);
char *_strdup(const char *s);

/** Memory util functions */
void free_2d_array(char **arr);
void *_realloc(void *ptr, int old_size, int new_size);

/** Print util functions */
int _putchar(char c);
void _puts(char *str);

/** Error util functions */
int _putchar_err(char c);
void _puts_err(char *str);
void print_positive_number_err(int n);
void print_number_err(int n);
void print_error(char *cmd, char *msg, int *code);

/** Environment util functions */
char *_getenv(const char *name);
char **dup_2d_array(char **src);
char *join_env_var(char *str1, char *str2, char *str3);

/** Path util functions */
int join_path(char **new_str, char *path, char *name);
char *path_with_current(char *path);
int use_path(char *cmd_path);

/** Built-ins commands functions */
void print_env(void);
void _exit_(char *str);

#endif