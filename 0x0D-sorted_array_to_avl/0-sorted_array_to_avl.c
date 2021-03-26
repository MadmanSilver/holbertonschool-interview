#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - converts array to avl
 * @array: Array to convert
 * @size: size of array
 *
 * Return: root node, NULL on fail
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl = malloc(sizeof(avl));

	if (avl == NULL)
		return (NULL);

	if (array == NULL)
	{
		free(avl);
		return (NULL);
	}

	return (avl);
}
