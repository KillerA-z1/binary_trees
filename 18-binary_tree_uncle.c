#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Return Pointer to the uncle node else NULL if node is NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the input node is NULL or its parent is NULL */
	if (node == NULL || !node->parent)
		return (NULL);

	/* Return the sibling of the parent of the input node */
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: Pointer to the node to find the sibling.
 *
 * Return: Pointer to the sibling node.
 *         NULL if the input node is NULL.
 *         NULL if the parent of the input node is NULL.
 *         NULL if the node has no siblings.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the input node is NULL or its parent is NULL */
	if (node == NULL || !node->parent)
		return (NULL);

	/* Determine and return the sibling of the input node */
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
