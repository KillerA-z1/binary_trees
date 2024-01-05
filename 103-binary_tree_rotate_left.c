#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL upon failure or if a left rotation is not possible
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *parent;

	/* Check if the tree is NULL or has no right child */
	if (!tree || !tree->right)
		return (NULL);

	/* Store current node (tree) and its parent */
	tmp = tree;
	parent = tree->parent;

	/* Update tree to point to its right child */
	tree = tree->right;
	tree->parent = NULL;

	/* Adjust pointers if the right child has a left child */
	if (tree->left)
	{
		tmp->right = tree->left;
		tree->left->parent = tmp;
	}
	else
		tmp->right = NULL;

	/* Set the parent of the original tree to be the new tree */
	tmp->parent = tree;

	/* Set the left child of the new tree to be the original tree */
	tree->left = tmp;

	/* If the original tree had a parent, update its right child */
	if (parent)
		parent->right = tree;

	/* Set the parent of the new tree to be the original tree's parent */
	tree->parent = parent;

	/* Return the new root node of the tree after the left rotation */
	return (tree);
}
