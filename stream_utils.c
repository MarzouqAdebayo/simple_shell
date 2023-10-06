#include "shell.h"

/**
 * prompt - Prints a prompt character to stdout
 * @sym: Prompt symbol
 *
 * Return: has no return value
 */

void prompt(char *sym)
{
	char *prompt;

	if (!sym)
		prompt = "($) ";
	else
		prompt = sym;
	printf("%s", prompt);
	fflush(stdout);
}
