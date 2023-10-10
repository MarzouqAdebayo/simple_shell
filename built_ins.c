#include "shell.h"

/**
 * print_env - prints enviroment variables
 *
 * Return: has no return value
 */

void print_env()
{
	int i;

	_puts("Printing env...");
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

	strtok(str, " ");
	token = strtok(NULL, " ");
	if (token)
		status = atoi(token);
	free(str);

	printf("Exiting hsh with status %d...", status);
	exit(status);
}
