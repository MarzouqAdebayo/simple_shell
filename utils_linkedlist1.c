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
		if (_strncmp(h->var, name, strlen(name)) == 0)
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
 * get_node_var - gets the environment variable from linkedlist
 * Return: string to the variable value
 */

char *get_node_var(char *name)
{
	list_t **h = get_head();
	char *value = NULL;

	while (*h)
	{
		if (_strncmp((*h)->var, name, strlen(name)) == 0)
			return (_strdup((*h)->var));
		*h = (*h)->next
	}
	return (NULL);
}
