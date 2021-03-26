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

	mid = (size - 1) / 2;
	tree->n = array[mid];
	tree->parent = NULL;
	tree->left = branch(array, 0, mid - 1, tree);
	tree->right = branch(array, mid + 1, size - 1, tree);

	return (avl);
}

/**
  * recurse - create tree recursively
  * @array: sorted array to convert
  * @s: starting point
  * @e: ending point
  * @tree: tree to add to
  *
  * Return: tree
  */
avl_t *recurse(int *array, int s, int e, avl_t *tree)
{
	int m;
	avl_t *node;

	if (s > e)
		return (NULL);

	node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

	m = (s + e) / 2;

	node->n = array[m];
	node->parent = tree;
	node->left = branch(array, s, m - 1, node);
	node->right = branch(array, m + 1, e, node);

	return (node);
}
