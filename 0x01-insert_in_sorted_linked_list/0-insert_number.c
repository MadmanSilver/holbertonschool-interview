#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: first node in the linked list
 * @number: number to add into the list
 *
 * Return: address of the new node, NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *p = *head;
	listint_t *new = malloc(sizeof(listint_t));

	new->n = number;

	if (new == NULL)
		return (NULL);

	if (p->n > number)
	{
		new->next = p;
		*head = new;
		return (new);
	}

	while (p != NULL)
	{
		if (p->next == NULL)
		{
			new->next = p->next;
			p->next = new;
			return (new);
		}

		if (p->next->n > number)
		{
			new->next = p->next;
			p->next = new;
			return (new);
		}

		p = p->next;
	}

	free(new);
	return (NULL);
}
