#include "shell.h"

/**
 * add_node - adds a new node at the beginning of listint_t list
 * @head: pointer to head node
 * @var: environment variable string
 *
 * Return: address of new element
 */

list_t *add_node(list_t **head, const char *var)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->var = _strdup(var);
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * add_node_end - adds a new node at the end of the list_t list
 * @head: pointer to head node
 * @var: environment variable string
 *
 * Return: address of new element
 */

list_t *add_node_end(list_t **head, const char *var)
{
	list_t *new, *h = *head;

	while (h->next)
		h = h->next;
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->var = _strdup(var);
	new->next = NULL;
	h->next = new;
	return (new);
}

/**
 *
 */

int delete_node(list_t **head, char *name)
{
	list_t *h = *head, *temp, *prev = NULL;

	while (h)
	{
		if (_strncmp(h->var, name, _strlen(name)) == 0)
		{
			if (!prev)
			{
				temp = h;
				*head = h->next;
				free(temp->var);
				free(temp);
			}
			else
			{
				prev->next = h->next;
				free(h->var);
				free(h);
			}
			break;
		}
		prev = h;
		h = h->next;
	}

	return (1);
}

/**
 * get_node - gets the node with variable name from linkedlist
 * Return: pointer to the env node
 */

list_t *get_node(const char *name)
{
	list_t *h = *get_head();

	while (h)
	{
		if (_strncmp(h->var, name, _strlen(name)) == 0)
			return (h);
		h = h->next;
	}
	return (h);
}

/**
 * copy_to_2d_array - converts a linked list to array of strings
 * Return: pointer to the array of strings
*/

char **build_env_array()
{
	list_t *h = *get_head();
	char **new;
	int len = 0, i = 0;

	len = list_len();
	new = malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (NULL);

	while (h)
	{
		new[i] = _strdup(h->var);
		if (!new[i])
		{
			i--;
			for (; i >= 0; i--)
				free(new[i]);
			free(new);
			return (NULL);
		}
		h = h->next;
		i++;
	}
	new[i] = NULL;

	return (new);
}
