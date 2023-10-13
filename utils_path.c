#include "shell.h"

void dummy(void);

/**
 * join_path - Build a full path by combining a directory path and a filename.
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

int join_path(char **new_str, char *path, char *name)
{
	int len = _strlen(path) + _strlen(name) + 2, i, j = 0;

	if (!new_str || !path || !name)
		return (-1);

	/** Allocated memory to arguments array */
	*new_str = malloc(sizeof(*new_str) * len);
	if (!(*new_str))
		return (-1);
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
		(*new_str)[j] = '\0';
		return (0);
	}
	return (0);
}

/**
 * path_with_current - Set current path to path
 * @path: string containing env var PATH
 *
 * Return: new edited path string
 *
 * This function edits path by adding a '.' when it finds a trailing colon,
 * leading colon or a double colon in the path string
 * It return a new string or NULL if an error occurs
 */

char *path_with_current(char *path)
{
	int i = 0, j, len = 0, flag = 1, index = -1;
	char *keep = NULL;

	if (!path)
		return (NULL);

	while (path[i])
	{
		if (path[i] == ':' && flag)
		{
			index = i;
			break;
		}
		else if (path[i] == ':')
			flag = 1;
		else
			flag = 0;
		i++;
	}
	if (flag && index == -1)
		index = i;

	if (index > -1)
	{

		len = _strlen(path);
		keep = malloc(sizeof(char) * (len + 2));
		if (!keep)
			return (NULL);
		i = 0;
		j = 0;
		while (path[i])
		{
			if (j == index)
			{
				keep[j] = '.';
				flag = 0;
				j++;
				continue;
			}
			keep[j] = path[i];
			i++;
			j++;
		}
		if (flag)
		{
			keep[j] = '.';
			keep[j + 1] = '\0';
		}
		else
			keep[j] = '\0';
	}
	else
		keep = strdup(path);
	free(path);
	return (keep);
}

/**
 * use_path - Checks if a path should use the env var PATH
 * @cmd_path: String containing the command passed to the shell
 *
 * Return: 1 if it is a rel or abs path and 0 if it is neither
 */

int use_path(char *cmd_path)
{
	int i = 0;

	if (_strncmp(cmd_path, "./", 2) == 0 || _strncmp(cmd_path, "/", 1) == 0)
		return (1);
	while (cmd_path[i])
	{
		if (cmd_path[i] == '/')
			return (1);
		i++;
	}

	return (0);
}

/**
 * dummy - To trick betty
 *
 * Return: has no return value
 */
void dummy(void)
{
}
