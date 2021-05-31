#include "lists.h"

/**
 * find_listint_loop - checks if there is a loop in a linked list
 * @head: list to search
 *
 * Return: node where the loop starts, NULL otherwise
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p = head, *p2;

	if (p == NULL)
		return (NULL);

	p2 = p->next;

	while (head != NULL)
	{
		p = p->next;
		p2 = p2->next;

		if (p2 == NULL)
			return (NULL);
		if (p2 == head)
			return (head);
		if (p2 == p)
		{
			head = head->next;
			p = head;
			p2 = head->next;
			continue;
		}

		p2 = p2->next;

		if (p2 == NULL)
			return (NULL);
		if (p2 == head)
			return (head);
		if (p2 == p)
		{
			head = head->next;
			p = head;
			p2 = head->next;
		}
	}

	return (NULL);
}
