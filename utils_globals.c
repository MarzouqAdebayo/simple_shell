#include "shell.h"

static char shell_name[30];
static int line_no = 0;

char *get_shell_name(void)
{
	return (shell_name);
}

void set_shell_name(char *name)
{
	_strncpy(shell_name, name, _strlen(name));
}

int get_line_no(void)
{
	return (line_no);
}

void set_line_no(void)
{
	line++;
}