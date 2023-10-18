#include "shell.h"

static char shell_name[30];
static int line_no;

/**
 * get_shell_name - This function gets the shell name
 *
 * Return: The shell_name string
*/

char *get_shell_name(void)
{
	return (shell_name);
}

/**
 * set_shell_name - This function sets the shell name
 * @name: Name of the file
*/

void set_shell_name(char *name)
{
	_strncpy(shell_name, name, _strlen(name));
}

/**
 * get_line_no - This function gets the command line number
 *
 * Return: The command line number
*/

int get_line_no(void)
{
	return (line_no);
}

/**
 * set_line_no - This function sets the command line number
*/

void set_line_no(void)
{
	line_no++;
}
