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
		return (NULL);

	len = _strlen(name);
	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/** compare env variable to name */
			/** remember to free temp to prevent memory leaks */
			temp = _strdup(environ[i] + len + 1);
			return (temp);
		}
	}
	return (NULL);
}
