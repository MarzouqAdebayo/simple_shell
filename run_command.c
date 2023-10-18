#include "shell.h"

/**
 * run_command - Execute a given command with arguments in a child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 * @env_vars: An array of environment variables (unused in this implementation)
 *
 * Description:
 * - This function creates a child process using fork() and executes a command
 *   in the child process using execve().
 * - The parent process waits for the child process to complete.
 *
 * @command: The path to the executable command or program.
 * @args: An array of strings representing the arguments to pass to the
 *        command.
 * @env_vars: An array of environment variables, which is not used in this
 *            implementation but is provided for compatibility.
 *
 * Return:
 * - Returns 0 on successful execution of the command.
 * - Returns -1 if an error occurs during fork().
 *
 * Note:
 * - This function is designed to be used in a Unix-like shell program to
 * execute user-entered commands.
 */

int run_command(char *command, char **args, char **env_vars)
{
	pid_t child_pid;
	int status;

	if (!command)
		return (-1);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Could not fork child process");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(command, args, env_vars) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
	return (EXIT_SUCCESS);
}
