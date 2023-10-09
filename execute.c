#include "shell.h"

/**
 * _execute - Execute a command specified in the args array.
 * @args: An array of strings containing the command and its arguments.
 *
 * This function attempts to execute a command specified in the 'args' array.
 * It first checks if the command is executable by looking for it in the
 * current directory or in the directories listed in the PATH environment
 * variable. If the command is found and executable, it is executed using the
 * 'run_command' function.
 *
 * If 'args' is NULL or 'args[0]' is NULL, an error message is printed, and the
 * function returns without further action.
 *
 * If the command is found but not executable, an error message is printed, and
 * the function returns without executing the command.
 *
 * If the PATH environment variable is not set or if it does not contain valid
 * directory paths, an error message is printed, and the function returns after
 * freeing any allocated memory.
 *
 * If the command is not found in any of the directories listed in PATH, an
 * error message is printed, and the function returns after freeing any
 * allocated memory.
 *
 * Parameters:
 *   args: An array of strings containing the command and its arguments.
 *
 * Return: None.
 */

void _execute(char **args)
{
	char *path, *token, *full_path = NULL;
	struct stat info;

	if (!args || !args[0])
	{
		perror("No argument passed");
		return;
	}

	/** Check current directory first then check those listed in path */
	if (args[0] && args[0][0] == '/')
	{
		if (stat(args[0], &info) == 0 && access(args[0], X_OK) == 0)
			run_command(args[0], args, environ);
	}
	else if (args[0] && args[0][0] == '.')
		{
			if (stat(args[0], &info) == 0 && access(args[0], X_OK) == 0)
				run_command(args[0], args, environ);
		}
	else
	{
		path = _getenv("PATH");
		if (!path)
		{
			free(path);
			perror("Environment variable Path does not exist: ");
			return;
		}
		token = strtok(path, ":");
		while (token)
		{
			if (build_path(&full_path, token, args[0]) == 0 && stat(full_path, &info) == 0 && access(full_path, X_OK) == 0)
			{
				if (run_command(full_path, args, environ) == 0)
				{
					free(full_path);
					free(path);
					return;
				}
				free(full_path);
			}
			token = strtok(NULL, ":");
		}
		if (path_with_current(path) && build_path(&full_path, "./", args[0]) == 0 && stat(full_path, &info) == 0 && access(full_path, X_OK) == 0)
		{
			if (run_command(full_path, args, environ) == 0)
			{
				free(full_path);
				return;
			}
			free(full_path);
		}
		print_error(1, args[0], "not found");
		free(path);
	}
}
