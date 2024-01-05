#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node to check
 *
 * Return: 1 if node is a leaf else return 0 also if node is NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node is NULL */
	if (!node)
	{
		/* Node is NULL, not a leaf */
		return (0);
	}

	/* Check if the node has any children */
	if (node->left || node->right)
	{
		/*  Node has children, not a leaf */
		return (0);
	}

	return (1);
}
