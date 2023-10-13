#include "shell.h"

/**
 * _strdup - Duplicate a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL if memory allocation fails.
 */

char *_strdup(const char *s)
{
	char *dup;
	int i = 0;

	if (!s)
		return (NULL);

	dup = malloc(sizeof(char) * (_strlen(s) + 1));
	if (!dup)
		return (NULL);

	while (*(s + i))
	{
		*(dup + i) = s[i];
		i++;
	}
	*(dup + i) = '\0';

	return (dup);
}