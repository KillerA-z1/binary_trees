#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: pointer to the node to find the sibling
 *
 * Return: Return pointer to the sibling node else
 *	NULL if node,parent and node has no siblings.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the input node is NULL */
	if (node == NULL || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
