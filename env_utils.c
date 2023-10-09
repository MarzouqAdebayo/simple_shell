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

int path_with_current(char *path)
{
	int i = 0, flag = 1;

	if (!path)
		return (-1);

	while (path[i])
	{
		if (path[i] == ':' && flag)
			return (1);
		if (path[i] == '.')
			return (1);
		else if (path[i] == ':')
			flag = 1;
		else
			flag = 0;
		i++;
	}
	if (flag)
		return (1);

	return (0);
}