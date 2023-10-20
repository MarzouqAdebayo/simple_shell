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
	list_t *node;

	if (name == NULL)
		return (NULL);
	node = get_node(name);
	temp = node->var;
	return (temp);
}

/**
 * setenv - Set or update an environment variable.
 * @name: The name of the environment variable to set.
 * @value: The value to assign to the environment variable.
 *
 * Description:
 * This function is used to set or update an environment variable specified by
 * the @name parameter. If the variable already exists its value will be
 * updated. If the variable doesn't exist, a new environment variable will be
 * created.
 *
 * Return:
 *  - 0 on success.
 *  - -1 on failure, with errno set to indicate the error.
 */

int _setenv(char *name, char *value)
{
	list_t **env_head = get_head();
	char *temp;
	int len = _strlen(name) + _strlen(value);
	list_t *new;

	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (-1);
	temp = _strcat(temp, name);
	temp = _strcat(temp, value);
	temp[len] = '\0';
	new = get_node(name);
	if (new)
	{
		free(new->var);
		new->var = temp;
		return (0);
	}
	else
	{
		new = add_node_end(env_head, temp);
		free(temp);
		if (new)
			return (0);
	}
	return (-1);
}
