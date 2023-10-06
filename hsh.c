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
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;
	/** Read */
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			free(line);
			exit(1);
		}
		printf("%s\n", line);
	}
	/** Parse */
	/** Execute */
	return (0);
}
