#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds lowest common ancestor of two nodes in
 *			   binary tree.
 * @first: A pointer to the first node to find the ancestor.
 * @second: A pointer to the second node to find the ancestor.
 *
 * Return: Return Pointer to the ancestor node else NULL if either input node
 *         or if there is no ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	/* Check if either input node is NULL */
	if (!first || !second)
		return (NULL);

	/* Calculate the depth of each input node */
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/* Move up the tree to the same depth for both nodes */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Move up the tree together until the common ancestor is found */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	/* Return the common ancestor (or NULL if no common ancestor) */
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Node to calculate the depth of.
 *
 * Return: Depth of the node.
 *         0 if the input node is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	/* Check if the input node is NULL */
	if (!tree)
		return (0);

	/* Move up the tree and count the levels until the root */
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	/* Return the calculated depth */
	return (depth);
}
