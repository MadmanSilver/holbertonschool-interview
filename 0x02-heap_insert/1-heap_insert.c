#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: root node of the heap
 * @value: value of the new node
 *
 * Return: pointer to the new node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = malloc(sizeof(heap_t));
	heap_t *p = new;

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (*root == NULL)
	{
		*root = new;
		new->parent = NULL;
		return (new);
	}

	insert(*root, new, 1);

	while (p->parent->n < p->n)
	{
		value = p->parent->n;
		p->parent->n = p->n;
		p->n = value;

		p = p->parent;

		if (p->parent == NULL)
			break;
	}

	return (p);
}

/**
 * insert - inserts the node at the end in level order
 * @current: node we are currently on
 * @new: node to be inserted
 * @level: which level we are meant to be checking (indexed at 0)
 *
 * Return: pointer to the node inserted, NULL on failure
 */
heap_t *insert(heap_t *current, heap_t *new, int level)
{
	heap_t *p = NULL;


	while (p == NULL)
	{
		if (current->right == NULL)
		{
			new->parent = current;
			if (current->left == NULL)
				current->left = new;
			else
				current->right = new;
			return (new);
		}

		if (level)
			p = insert(current->left, new, level - 1);
		else
			return (NULL);

		if (p == NULL)
			p = insert(current->right, new, level - 1);

		if (p != NULL)
			return (p);

		if (current->parent != NULL)
			return (NULL);

		level++;
	}

	return (p);
}

/**
 * swapL - swaps two nodes
 * @new: node to be swapped up
 */
void swapL(heap_t *new)
{
	heap_t *p = NULL;

	p = new->left;
	new->left = new->parent;
	new->parent->left = p;
	if (p)
		p->parent = new->left;
	p = new->right;
	new->right = new->left->right;
	if (new->left->right)
		new->left->right->parent = new;
	new->left->right = p;
	if (p)
		p->parent = new->left;
	p = new->left;
	new->parent = p->parent;
	if (p->parent)
	{
		if (p->parent->right == p)
			p->parent->right = new;
		else
			p->parent->left = new;
	}
	p->parent = new;
}

/**
 * swapR - swaps two nodes
 * @new: node to be swapped up
 */
void swapR(heap_t *new)
{
	heap_t *p = NULL;

	p = new->right;
	new->right = new->parent;
	new->parent->right = p;
	if (p)
		p->parent = new->right;
	p = new->left;
	new->left = new->right->left;
	if (new->right->left)
		new->right->left->parent = new;
	new->right->left = p;
	if (p)
		p->parent = new->right;
	p = new->right;
	new->parent = p->parent;
	if (p->parent)
	{
		if (p->parent->left == p)
			p->parent->left = new;
		else
			p->parent->right = new;
	}
	p->parent = new;
}
