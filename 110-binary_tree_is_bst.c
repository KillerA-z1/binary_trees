#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_helper_int(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - function for checking if a binary tree is a valid BST.
 * @tree: The tree to check.
 * @min: The minimum value for this subtree.
 * @max: The maximum value for this subtree.
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise.
 */
int binary_helper_int(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_helper_int(tree->left, min, tree->n) &&
	       binary_helper_int(tree->right, tree->n, max));
}
