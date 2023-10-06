#include "shell.h"

/**
 * main - contains the main function of the program
 * @argc: Arguments passed into the CLI
 * @argv: Pointer to arguments string
 *
 * Description: A simple UNIX shell
 * Return: Always 0
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *line, **cmd_args;
	/** Read */
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		line = _read();
		cmd_args = _parse(line);
		free(line);
		free2DArray(cmd_args);
	}
	/** Parse */
	/** Execute */
	return (0);
}
