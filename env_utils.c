#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the specified environment variable,
 *         or NULL if the variable is not found or if 'name' is NULL.
 *
 * This function searches for an environment variable with the specified name
 * and returns a pointer to its value. If the variable is not found or if
 * 'name' is NULL, the function returns NULL. Remember to free the memory
 * allocated for the returned value when it is no longer needed to prevent
 * memory leaks.
 */

char *_getenv(const char *name)
{
	int i;
	char *temp;
	size_t len;

	if (name == NULL)
		return NULL;

	len = strlen(name);
	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/** compare env variable to name */
			/** remember to free temp to prevent memory leaks */
			temp = strdup(environ[i] + len + 1);
			return (temp);
		}
	}
	return (NULL);
}

/**
 * _setenv - Set the value of an environment variable.
 * @name: The name of the environment variable to set.
 * @value: The new value to assign to the environment variable.
 *
 * Return: 0 on success, or -1 on failure.
 *
 * This function attempts to set the value of an environment variable with the
 * specified name to the given 'value'. If successful, it returns 0. If 'name'
 * or 'value' is NULL, or if memory allocation fails, the function returns -1
 * to indicate failure. Note that this function is a placeholder and does not
 * implement actual environment variable modification in this example.
 */

int *_setenv(void)
{
	return (0);
}

/**
 *
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

		len = strlen(path);
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
 *
 */

int use_path(char *cmd_path)
{
	int i = 0;

	if (strncmp(cmd_path, "./", 2) == 0 || strncmp(cmd_path, "/", 1) == 0)
		return (1);
	while (cmd_path[i])
	{
		if (cmd_path[i] == '/')
			return (1);
		i++;
	}

	return (0);
}