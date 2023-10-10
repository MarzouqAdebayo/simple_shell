#include "shell.h"

/**
 * check_builtin - check built ins
 * @command: command to executer
 *
 * Return: 1, 0 or -1
*/

int check_builtin(char *command)
{
	if (!command)
		return (-1);

	/** use 2D array and function pointers if list gets long */
	if (_strncmp("env", command, 3) == 0)
	{
		print_env();
		return (1);
	}

	if (strncmp("exit", command, 4) == 0)
	{
		_exit_(command);
		return (1);
	}

	return (0);
}
