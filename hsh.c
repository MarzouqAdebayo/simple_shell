#include "shell.h"

/**
 * main - Entry point of a simple Unix shell program.
 * @argc: The argument count (unused).
 * @argv: The argument vector (unused).
 *
 * Description:
 * - This function serves as the entry point for a basic Unix shell program.
 * - It repeatedly reads user input, parses commands, and executes them.
 * - When running in an interactive terminal, it displays a shell prompt.
 *
 * Return:
 * - Always returns 0, indicating successful execution (unused argc/argv
 * convention).
 *
 * Usage:
 * - Compile and run the program to start the Unix shell.
 * - Users can input commands, which will be parsed and executed.
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *line, **cmd_args;
	char *shell_name;
	
	if (argc > 0)
	{
		shell_name = malloc(sizeof(argv[0]));
		_strncpy(shell_name, argv[0], _strlen(argv[0]));
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		/** Read */
		line = _read_fn();
		/** Parse */
		cmd_args = _parse(line);
		/** Execute */
		_execute(cmd_args);
		free2DArray(cmd_args);
	}
	if (shell_name)
		free(shell_name);
	return (0);
}
