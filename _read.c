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
	int len = 0;
	ssize_t bytes_read = 0;
	int fd = 0;

	bytes_read = _getline(&line, &len, fd);
	if (bytes_read == -1)
	{
		free(line);
		free_list();
		exit(get_status());
	}
	set_line_no();
	return (line);
}
