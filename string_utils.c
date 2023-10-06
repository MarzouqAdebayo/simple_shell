#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * _strncpy - Copy at most n characters from src to dest.
 * @dest: The destination buffer where characters are copied.
 * @src: The source string to copy from.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination buffer (dest).
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
