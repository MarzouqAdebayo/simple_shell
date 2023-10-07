#include "shell.h"

/**
 * prompt - Display a command prompt to the user.
 * @sym: The custom symbol or prompt to display (optional).
 *
 * Description:
 * - This function displays a command prompt to the user in the standard output
 * - If a custom symbol (sym) is provided, it will be displayed as the prompt.
 *   Otherwise, a default prompt of "($)" is used.
 *
 * @sym: A string representing the custom symbol or prompt to display.
 *       If NULL, a default prompt "($)" is used.
 *
 * Note:
 * - This function is typically used in a Unix-like shell to display a prompt
 *   where users can enter commands.
 */

void prompt(char *sym)
{
	char *prompt;

	if (!sym)
		prompt = "($) ";
	else
		prompt = sym;
	_puts(prompt);
	fflush(stdout);
}
