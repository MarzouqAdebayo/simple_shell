#include "shell.h"

/**
 * check_builtin - check built ins
 * @command: command to executer
 *
 * Return: 1, 0 or -1
 */

int check_builtin(char *command)
{
	char *cmd, **cmd_args;

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
		_exit_(command);
		return (1);
	}

	if (_strncmp(cmd, "setenv", 6) == 0)
	{
		cmd_args = split_str(cmd, ' ');
		if (cmd)
		{
			if (_setenv(cmd_args[1], cmd_args[2]) == 0)
			{
				free(cmd);
				free2DArray(cmd);
				return (1);
			}
			else
				perror("Usage: setenv <name> <value>\n");
		}
	}

	if (_strncmp(cmd, "unsetenv", 8) == 0)
	{
		if (cmd)
		{
			cmd_args = split_str(cmd, ' ');
			if (_unsetenv(cmd_args[1]) == 0)
			{
				free(cmd);
				free2DArray(cmd_args);
				return (1);
			}
			else
				perror("Environment variable not found");
		}
	}

	free(cmd);

	return (0);
}
