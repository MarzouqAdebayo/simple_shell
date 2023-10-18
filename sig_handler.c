#include "shell.h"

/**
 * sig_handler - prints prompt on signal
 * @sigval: the signal number
 */

void sig_handler(__attribute__((unused)) int sigval)
{
	_puts("\n($) ");
}