#include "shell.h"

/**
 * _strdup - Duplicate a string.
 *
 * @s: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL if memory
 * allocation fails.
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

/**
 * _strcat - concatenates the string pointed to by src to
 * the end of the string pointed to by dest
 * @dest: Destination string
 * @src: Source string
 *
 * Return: returns poiner to dest
 */
char *_strcat(char *dest, char *src)
{

	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;

	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];

	return (dest);
}
