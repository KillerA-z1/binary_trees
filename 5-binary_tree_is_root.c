#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root.
 * @node: node to check
 *
 * Return: Return: 1 if node is a root else return 0 also if node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
