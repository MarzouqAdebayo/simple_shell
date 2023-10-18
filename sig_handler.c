#include "shell.h"

/**
 * sig_handler - prints prompt on signal
 * @sigval: the signal number
 */

void sig_handler(__attribute__((unused)) int sigval)
{
	if (signum == SIGTSTP)
	{
		return;
	}
	else if (signum == SIGINT)
		_puts("\n($) ");
}