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

int *_setenv(char *var, char *value)
{
	int i = 0, j, len, exists = -1, env_len;
	char *temp, **env_copy;

	if (!name || !value)
		return (-1);
	for (env_len = 0; environ[env_len]; env_len++)
		;
	len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			exists = i;
			break;
		}
	}
	env_copy = dup_2D_array(environ);
	if (exists != -1)
	{
		temp = join_env_var(name, "=", value);
		free(env_copy[exists]);
		env_copy[exists] = temp;
		free2DArray(environ);
		environ = env_copy;
		return (0);
	}
	else
	{
		env_copy = _realloc(env_copy, sizeof(char *) * (env_len + 1), sizeof(char *) * (env_len + 2));
		if (!env_copy)
			return (-1);
		temp = join_env_var(name, "=", value);
		env_copy[env_len] = temp;
		env_copy[env_len + 1] = NULL;
		environ = env_copy;
		return (0);
	}

	return (-1);
}

/**
 *
 */

int *_unsetenv(char *name)
{
	int exists = -1, env_len, name_len, var_len, i = 0, j = 0, k = 0;
	char **env_copy;

	if (!name)
		return (-1);

	name_len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			exists = i;
			break;
		}
	}
	if (exists != -1)
	{
		for (env_len = 0; environ[env_len]; env_len++)
			;
		env_copy = malloc(sizeof(char *) * env_len);
		if (!env_copy)
			return (-1);
		i = 0;
		j = 0;
		while (environ[i])
		{
			if (i == exists)
			{
				i++;
				continue;
			}
			var_len = _strlen(environ[i]);
			env_copy[j] = malloc(sizeof(char) * (var_len + 1));
			if (!(env_copy[j]))
			{
				for (; j >= 0; j--)
					free(env_copy[j]);
				free(env_copy);
				return (-1);
			}
			for (k = 0; environ[i][k]; k++)
				env_copy[j][k] = environ[i][k];
			env_copy[j][k] = '\0';
			i++;
			j++;
		}
		env_copy[env_len - 1] = NULL;
		free(environ);
		environ = env_copy;
	}
	else
		return (-1);
	return (0);
}