#include "shell.h"

/**
 * _read_fn - Read a line of input from standard input.
 *
 * Return: A pointer to the read line (including the newline character),
 *         or NULL on failure or end of file.
 *
 * This function reads a line of input from the standard input (stdin).
 * It dynamically allocates memory to store the input line and automatically
 * resizes it as needed.
 * The function returns a pointer to the read line, including the newline
 * character at the end. If an error occurs or the end of file is reached,
 * it returns NULL and may exit the program with an error code.
 */

char *_read_fn(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;

	bytes_read = _getline(&line, &len, 0);
	if (bytes_read == -1)
	{
		free(line);
		exit(1);
	}
	line_no += 1;
	return (line);
}
