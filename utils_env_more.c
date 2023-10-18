#include "shell.h"

/**
 * dup_2d_array - Creates a duplicate of a 2D array.
 *
 * @src: The source 2D array to duplicate.
 *
 * Return: A newly allocated copy of the source 2D array.
 * The caller is responsible for freeing this memory when done.
 */

char **dup_2d_array(char **src)
{
	char **copy = NULL;
	int prev_size = 0, i, j, len = 0;

	for (prev_size = 0; src[prev_size]; prev_size++)
		;
	copy = malloc(sizeof(char *) * (prev_size + 1));
	if (!copy)
		return (0);
	i = 0;
	while (src[i])
	{
		len = _strlen(src[i]);
		copy[i] = malloc(sizeof(char) * (len + 1));
		if (!(copy[i]))
		{
			for (; i >= 0; i--)
				free(copy[i]);
			free(copy);
			return (0);
		}
		for (j = 0; src[i][j]; j++)
		{
			copy[i][j] = src[i][j];
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[prev_size] = NULL;

	return (copy);
}

/**
 * join_env_var - Concatenates new env variable.
 *
 * @str2: The second string to concatenate.
 * @str1: The first string to concatenate.
 * @str3: The third string to concatenate.
 *
 * Return: A newly allocated string containing the concatenated result.
 *         The caller is responsible for freeing this memory when done.
 */

char *join_env_var(char *str1, char *str2, char *str3)
{
	char *temp;
	int i, j;

	temp = malloc(sizeof(char) * (_strlen(str1) + _strlen(str2) + _strlen(str3) +
	1));
	if (!temp)
		return (NULL);

	for (i = 0; str1[i]; i++)
		temp[i] = str1[i];
	for (j = 0; str2[j]; j++, i++)
		temp[i] = str2[j];
	for (j = 0; str3[j]; j++, i++)
		temp[i] = str3[j];
	temp[i] = '\0';

	return (temp);
}
