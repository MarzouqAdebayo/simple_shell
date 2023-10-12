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

/**
 * _strtok - Split a string into tokens using specified delimiters.
 * @str: The string to be tokenized. It should be a null-terminated string.
 * @delim: A null-terminated string containing delimiter characters.
 *
 * Description:
 * This function splits the input string into a sequence of tokens using the specified delimiters.
 *
 * Return:
 * - On the first call, it returns a pointer to the first token found in 'str'.
 * - On subsequent calls with 'NULL' as the first argument, it continues tokenization.
 * - If no more tokens are found, it returns 'NULL'.
 *
 * Notes:
 * - The function modifies the original 'str' by replacing delimiters with null characters.
 * - The internal state is maintained between calls using a static variable and is not thread-safe.
 */

char *_strtok(char *str, const char *delim)
{
	static char *copy = NULL;
	char *token = NULL;
	static int i = 0, flag = 1;
	int j, k, delim_len = strlen(delim);

	if (str)
		copy = str;

	while (1)
	{
		if (!copy[i])
			return (token);
		if (_strncmp(copy + i, delim, delim_len) == 0)
		{
			k = i + delim_len;
			for (j = i; j < k; j++, i++)
				copy[j] = '\0';
			flag = 1;
			if (token)
				return (token);
			continue;
		}
		else
		{
			if (flag)
				token = copy + i;
			flag = 0;
		}
		i++;
	}
	return (NULL);
}

/**
 * _atoi - Body of the function
 * @s: The character to be parsed
 *
 * Description: converts strings into int
 * Return: has no return value
 */

int _atoi(char *s)
{
	int i = 0, result = 0, sign = 1;

	while (*(s + i) < '0' || *(s + i) > '9')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}

	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		result = (result * 10) + (s[i] - 48);
		i++;
	}

	return (result * sign);
}

/**
 * _strcmp - Compares two strings
 * @s1: Pointer to string one
 * @s2: Pointer to string two
 *
 * Return: return 0 if same and 1 otherwise
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (*s1 || i < n)
	{
		if (*s1 != *s2)
		{
			return *(const unsigned char *)s1 - *(const unsigned char *)s2;
		}
		s1++;
		s2++;
	}
	return (0);
}