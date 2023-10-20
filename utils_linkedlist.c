#include "shell.h"

static list_t *env_node;

/**
 * initialize - creates a liked list of environment variables
 * Return: void
 */

void initialize_env(void)
{
	int len;

	for (len = 0; environ[len]; len++)
		add_node(&env_node, environ[len]);
}

/**
 * get_head - gets the head node from the linked list
 * Return: the head node
*/

list_t **get_head(void)
{
	return (&env_node);
}

/**
 * free_list - frees a listint_t list
 * Return: void
 */

void free_list(void)
{
	list_t *temp;

	while (env_node)
	{
		temp = env_node->next;
		free(env_node->var);
		free(env_node);
		env_node = temp;
	}
}

/**
 * print_list - prints all the elements of a linked list.
 * @h: The linked list
 *
 * Return: The number of nodes in the list
 */

int print_list(void)
{
	int size = 0;
	const list_t *h = env_node;

	while (h)
	{
		if (!(h->var))
			;
		else
			_puts(h->var);
		_putchar('\n');
		h = h->next;
		size++;
	}

	return (size);
}

/**
 * list_len - returns the size of the linked list
 * Return: returns the length of the linked list
 */

int list_len(void)
{
	int len = 0;
	list_t *h = env_node;

	while (h)
	{
		h = h->next;
		len++;
	}

	return (len);
}
