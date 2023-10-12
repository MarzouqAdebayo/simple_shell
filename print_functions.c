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

/**
 * print_positive_number - Body of the function
 * @n: The argument n to be printed
 *
 * Description: Prints numbers using putchar
 * Return: has no return value
 */

void print_positive_number(int n)
{
	if (n < 1)
		return;

	print_positive_number(n / 10);
	_putchar(48 + (n % 10));
}

/**
 * print_number - Body of the function
 * @n: The argument n to be printed
 *
 * Description: Prints numbers using putchar
 * Return: has no return value
 */
void print_number(int n)
{
	if (n == 0)
	{
		_putchar(48);
		return;
	}

	if (n < 0)
	{
		n = n * -1;
		_putchar('-');
	}
	print_positive_number(n);
}

/**
 *
 */

void print_error(char *cmd, char *msg, int *code)
{
	if (!msg)
	{
		msg = " not found";
	}
	_puts(shell_name);
	_puts(": ");
	print_number(line_no);
	_puts(": ");
	_puts(cmd);
	_puts(": ");
	_puts(msg);
	if (code)
	{
		_puts(": ");
		print_number(*code);
	}
	_putchar('\n');
}
