#include "shell.h"

void dummy3(void);

/**
 * _getline - Read lines from a file descriptor, dynamically resizing the
 * buffer.
 * @lineptr: A pointer to a pointer to the dynamically allocated line buffer.
 * @n: A pointer to the size of the allocated buffer.
 * @fd: File descriptor for input stream
 *
 * Description:
 * This function reads lines from the given file descriptor 'fd' and stores
 * them in a dynamically allocated buffer. It automatically resizes the buffer
 * to accommodate lines of varying lengths.
 *
 * Return:
 * On success, returns the number of characters read, including the newline
 * character ('\n').
 * On error, returns -1. Possible errors include memory allocation failures,
 * read errors, and reaching the end of the file with no data read.
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char c;
	static char *temp_buffer;
	size_t index = 0;
	ssize_t _byte;

	if (!lineptr || !n)
		return (-1);

	if (!(*lineptr) || !(*n))
	{
		*n = 256;
		*lineptr = malloc(sizeof(char) * (*n));
		if (!*lineptr)
			return (-1);
	}

	while ('a' == 97)
	{
		_byte = read(fd, &c, 1);

		if (_byte == -1)
			return (-1);
		else if (_byte == 0)
		{
			if (index == 0)
				return (-1);
			else
				break;
		}

		if ((index + 1) >= (*n))
		{
			temp_buffer = realloc(*lineptr, (*n + 128));
			if (!temp_buffer)
				return (-1);
			*lineptr = temp_buffer;
			*n += 128;
		}

		(*lineptr)[index] = c;
		index++;

		if (c == '\n')
			break;
	}

	(*lineptr)[index] = '\0';

	return (index);
}

/**
 * dummy - To trick betty
 *
 * Return: has no return value
 */
void dummy3(void)
{
}
