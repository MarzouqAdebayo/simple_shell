#include "shell.h"

/**
 *
 */

char **_parse(char *str)
{
	char *cmd_str = NULL, **cmd_args = NULL;

	/** Remove duplicate whitespace */
	cmd_str = collapse_whitespace(str, cmd_str);
	free(str);
	if (cmd_str)
	{
		printf("--> %s\n", cmd_str);
		cmd_args = split_str(cmd_str, ' ');
	}
	else
	{
		/** Handle error appropriately here */
		perror("Could not parse string");
		exit(EXIT_FAILURE);
	}
	return (cmd_args);
}