#include "shell.h"

/**
 * _putchar - Writes a single character to the standard output.
 * @c: The character to be written.
 *
 * Return: On success, 1 is returned. On error, -1 is returned,
 * and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to the standard output.
 * @str: The string to be written.
 *
 * Description: This function writes each character of the input
 * string to the standard output until the null terminator
 * is encountered.
 */

void _puts(char *str)
{
	int i;
	char ch;

	i = 0;
	while (str[i] != '\0')
	{
		ch = str[i];
		_putchar(ch);
		++i;
	}
}
