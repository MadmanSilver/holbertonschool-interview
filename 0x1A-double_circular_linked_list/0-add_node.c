#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a list
 * @list: list to modify
 * @str: data for the new node
 *
 * Return: address of new node, NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *p;
	List *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = new;
	new->prev = new;

	if (*list == NULL)
	{
		*list = new;
		return (new);
	}

	for (p = *list; p->next != *list; p = p->next)
		;

	new->prev = p;
	new->next = p->next;
	p->next = new;
	new->next->prev = new;

	return (new);
}

/**
 * add_node_begin - Adds a new node to the beginning of a list
 * @list: list to modify
 * @str: data for the new node
 *
 * Return: address of new node, NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = new;
	new->prev = new;

	if (*list == NULL)
	{
		*list = new;
		return (new);
	}

	new->prev = (*list)->prev;
	new->next = *list;
	(*list)->prev->next = new;
	(*list)->prev = new;
	*list = new;

	return (new);
}
