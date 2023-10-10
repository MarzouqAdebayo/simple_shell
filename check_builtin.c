#include "shell.h"

/**
 * check_builtin - check built ins
 * @command: command to executer
 *
 * Return: 1, 0 or -1
 */

int check_builtin(char *command)
{
	char *cmd;

	if (!command)
		return (-1);
	/** Cleanup string */
	cmd = collapse_whitespace(command);
	/** use 2D array and function pointers if list gets long */
	if (strncmp(cmd, "env", 3) == 0)
	{
		print_env();
		free(cmd);
		return (1);
	}

	if (strncmp(cmd, "exit", 4) == 0)
	{
		_exit_(cmd);
		free(cmd);
		return (1);
	}
	free(cmd);

	return (0);
}
