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
		perror("No argument passed:");
		return;
	}

	if (stat(args[0], &info) == 0)
	{
		if (access(args[0], X_OK) == 0)
			run_command(args[0], args, environ);
		else
		{
			perror("1. File exists but is not executable: ");
			return;
		}
	}
	else
	{
		path = _getenv("PATH");
		if (!path)
		{
			free(path);
			perror("Path Does not exist: ");
			return;
		}
		token = strtok(path, ":");
		while (token)
		{
			build_path(&full_path, token, args[0]);
			printf("%s\n", full_path)
			if (stat(full_path, &info) == 0)
			{
				if (access(full_path, X_OK) == 0)
				{
					printf("72. Can run program\n")
				}
				else
					perror("75. ");
			}
			free(full_path);
			token = strtok(NULL, ":");
			printf("-------------------------------\n")
		}
		print_error(1, args[0], "not found");
		free(path);
	}
}
