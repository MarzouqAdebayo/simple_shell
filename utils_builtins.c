#include "shell.h"

/**
 * print_env - prints enviroment variables
 *
 * Return: has no return value
 */

void print_env(void)
{
	int i;
	
	i = print_list();
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

	_strtok(str, " ");
	token = _strtok(NULL, " ");
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
	free_list();
	exit(status ? status : get_status());
}
