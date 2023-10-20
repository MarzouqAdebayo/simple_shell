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
	char *temp;

	if (name == NULL)
		return (NULL);
	temp = get_node_var(name);
	return (temp);
}
