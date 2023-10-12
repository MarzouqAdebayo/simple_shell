#include "shell.h"

/**
 * print_env - prints enviroment variables
 *
 * Return: has no return value
 */

void print_env()
{
	int i;

	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}

/**
 *
 */
void _exit_(char *str)
{
	int status = 0;
	char *token;

	_strtok(str, " ");
	token = _strtok(NULL, " ");
	if (token)
		status = atoi(token);
	free(str);
	exit(status);
}
