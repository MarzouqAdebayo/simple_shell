#include "shell.h"

/**
 * build_path - Build a full path by combining a directory path and a filename.
 * @new_str: Pointer to a char pointer where the resulting path will be stored.
 * @path: The directory path.
 * @name: The filename.
 *
 * Return: 0 on success, or -1 on failure.
 *
 * This function combines a directory path and a filename to create a full
 * path.
 * The resulting path is stored in the location pointed to by 'new_str'.
 * Memory is dynamically allocated for the new path, so it should be freed
 * when no longer needed.
 * If memory allocation fails or any of the input parameters is NULL, the
 * function returns -1. Otherwise, it returns 0 to indicate success.
 */

int build_path(char **new_str, char *path, char *name)
{
	int len = strlen(path) + strlen(name) + 2, i, j = 0;

	if (!new_str || !path || !name)
		return (-1);

	/** Allocated memory to arguments array */
	*new_str = malloc(sizeof(*new_str) * len);
	if (!(*new_str))
	{
		free(*new_str);
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		while (path[i])
		{
			(*new_str)[j] = path[i];
			i++;
			j++;
			continue;
		}
		(*new_str)[j] = '/';
		j++;
		i = 0;
		while (name[i])
		{
			(*new_str)[j] = name[i];
			i++;
			j++;
			continue;
		}
	}
	(*new_str)[j] = '\0';
	return (0);
}
