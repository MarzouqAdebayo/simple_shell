#include "shell.h"

/**
 * sig_handler - prints prompt on signal
 * @sigval: the signal number
 */

void sig_handler(__attribute__((unused)) int sigval)
{
	if (sigval == SIGTSTP)
	{
		return;
	}
	else if (sigval == SIGINT)
		prompt("\n($) ");
}

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

	signal(SIGTSTP, sig_handler);
	signal(SIGINT, sig_handler);

	initialize_env();

	if (argc > 0)
		set_shell_name(argv[0]);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		/** Read */
		line = _read_fn();
		/** Check if it a built in */
		if (check_builtin(line) == 1)
		{
			free(line);
			continue;
		}
		/** Parse */
		cmd_args = _parse(line);
		/** Execute */
		if (cmd_args)
		{
			_execute(cmd_args);
			free_2d_array(cmd_args);
		}
	}
	return (0);
}
