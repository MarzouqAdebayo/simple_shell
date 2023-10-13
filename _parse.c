#include "shell.h"

/**
 * _parse - Parses a string into an array of command arguments.
 * @str: The string to be parsed.
 *
 * Description: This function takes a string as input, removes duplicate
 * whitespace, and splits it into an array of command arguments. The resulting
 * array of strings is returned.
 *
 * Return: An array of strings representing the command arguments.
 *         NULL if the parsing fails, and the function exits with failure.
 */

char **_parse(char *str)
{
	char *cmd_str = NULL, **cmd_args = NULL;

	/** Remove duplicate whitespace */
	cmd_str = collapse_whitespace(str);
	free(str);
	if (cmd_str)
	{
		cmd_args = split_str(cmd_str, ' ');
		/** Free cmd_str */
		free(cmd_str);
	}
	else
	{
		/** Handle error */
		perror("Could not parse string");
		exit(EXIT_FAILURE);
	}
	return (cmd_args);
}
