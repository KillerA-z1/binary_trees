#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal.
 * @tree: The tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		binary_helper(tree, func, level);
}

/**
 * binary_helper - Helper function for level-order traversal.
 * @tree: The tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: The level of the tree to call func upon.
 */
void binary_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else
	{
		binary_helper(tree->left, func, level - 1);
		binary_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: The tree to measure the height of.
 *
 * Return: Height of the tree.
 *         0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
