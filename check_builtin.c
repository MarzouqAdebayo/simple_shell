#include "shell.h"

/**
 * check_builtin - check built ins
 * @command: command to executer
 *
 * Return: 1, 0 or -1
 */

int check_builtin(char *command)
{
	char *cmd, **args;
	int i;

	if (!command)
		return (-1);
	/** Cleanup string */
	cmd = collapse_whitespace(command);
	/** use 2D array and function pointers if list gets long */
	if (_strncmp(cmd, "env", 3) == 0)
	{
		print_env();
		free(cmd);
		return (1);
	}

	if (_strncmp(cmd, "exit", 4) == 0)
	{
		free(cmd);
		free_list();
		_exit_(command);
		return (1);
	}

	if (_strncmp(cmd, "setenv", 6) == 0)
	{
		args = split_str(cmd, ' ');
		for (i = 0; args[i]; i++)
			;
		if (i == 3)
			_setenv(args[1], args[2]);
		return (1);
	}

	if (_strncmp(cmd, "unsetenv", 8) == 0)
	{
		return (1);
	}

	free(cmd);

	return (0);
}
