#include "shell.h"

/**
 * print_env - prints enviroment variables
 *
 * Return: has no return value
 */

void print_env(void)
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
 * _exit_ - Exits the process and terminates shell
 * @str: Command argument
 *
 * Return: has not return value
 */

void _exit_(char *str)
{
	int status = 0;
	char *token;

	strtok(str, " ");
	token = strtok(NULL, " ");
	if (token)
	{
		status = _atoi(token);
		if (status < 0)
		{
			print_error("exit", "Illegal number", &status);
			return;
		}
	}
	free(str);
	exit(status);
}
