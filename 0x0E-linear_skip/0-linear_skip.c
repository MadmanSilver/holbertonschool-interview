#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: list to search through
 * @value: value to search for
 *
 * Return: node where value is located, NULL otherwise
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *lo = list;
	skiplist_t *hi;

	if (list == NULL)
		return (NULL);
	if (list->n > value)
		return (NULL);
	hi = lo->express;
	while (hi != NULL && hi->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", hi->index, hi->n);
		lo = hi;
		hi = hi->express;
	}

	if (hi == NULL)
	{
		hi = lo->next;
		while (hi->next != NULL)
			hi = hi->next;
	}

	if (hi->express != NULL)
		printf("Value checked at index [%lu] = [%d]\n", hi->index, hi->n);

	printf("Value found between indexes [%lu] and [%lu]\n", lo->index, hi->index);

	while (lo != NULL && lo->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", lo->index, lo->n);
		lo = lo->next;
	}

	if (lo == NULL)
		return (NULL);

	printf("Value checked at index [%lu] = [%d]\n", lo->index, lo->n);
	return (lo);
}
