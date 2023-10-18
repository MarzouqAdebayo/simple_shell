#include "shell.h"

static int exit_status;

/**
 * get_status - gets the last exit_status
 * 
 * Return: last exit status
*/

int get_status(void)
{
	return (exit_status);
}

/**
 * set_status - sets the current exit_status
 * @status: status
*/

void set_status(int status)
{
	exit_status = status;
}