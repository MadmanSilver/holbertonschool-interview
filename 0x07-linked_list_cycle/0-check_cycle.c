#include "lists.h"

/**
 * check_cycle - finds a loop in a listint_t list
 * @list: list to be checked
 *
 * Return: 1 if there is a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	size_t i, j;
	listint_t *p = list, *p2 = list;

	if (list == NULL)
		return (0);

	for (i = 0; p != NULL; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (p2 == p)
				break;

			p2 = p2->next;
		}

		if (j != i)
			return (1);

		p = p->next;
		p2 = list;
	}

	return (0);
}
