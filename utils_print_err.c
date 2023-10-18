#include "shell.h"

/**
 * _putchar_err - Writes a single character to the standard error.
 * @c: The character to be written.
 *
 * Return: On success, 1 is returned. On error, -1 is returned,
 * and errno is set appropriately.
 */

int _putchar_err(char c)
{
	return (write(stderr, &c, 1));
}

/**
 * _puts_err - Writes a string to the standard error.
 * @str: The string to be written.
 *
 * Description: This function writes each character of the input
 * string to the standard output until the null terminator
 * is encountered.
 */

void _puts_err(char *str)
{
	int i;
	char ch;

	i = 0;
	while (str[i] != '\0')
	{
		ch = str[i];
		_putchar_err(ch);
		++i;
	}
}

/**
 * print_positive_number_err - Body of the function
 * @n: The argument n to be printed
 *
 * Description: Prints numbers using putchar
 * Return: has no return value
 */

void print_positive_number_err(int n)
{
	if (n < 1)
		return;

	print_positive_number_err(n / 10);
	_putchar_err(48 + (n % 10));
}

/**
 * print_number - Body of the function
 *
 * @n: The argument n to be printed
 *
 * Description: Prints numbers using putchar
 * Return: has no return value
 */
void print_number_err(int n)
{
	if (n == 0)
	{
		_putchar_err(48);
		return;
	}
_err
	if (n < 0)
	{
		n = n * -1;
		_putchar_err('-');
	}
	print_positive_number_err(n);
}

/**
 * print_error - prints error message to stderr
 *
 * @cmd: Command name string
 * @msg: Error message
 * @code: Error code to be printed
 *
 * Description: Prints customised error message
 * Return: has no return value
 */

void print_error(char *cmd, char *msg, int *code)
{
	if (!msg)
	{
		msg = " not found";
	}
	_puts_err(get_shell_name());
	_puts_err(": ");
	print_number_err(get_line_no());
	_puts_err(": ");
	_puts_err(cmd);
	_puts_err(": ");
	_puts_err(msg);
	if (code)
	{
		_puts_err(": ");
		print_number_err(*code);
	}
	_putchar_err('\n');
}
