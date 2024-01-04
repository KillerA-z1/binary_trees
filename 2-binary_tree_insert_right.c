#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * This function inserts new node as the right-child of the given parent node.
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 *         NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	/* Check if parent is NULL */
	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;

	new->left = NULL;

	new->right = NULL;

	if (parent->right)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}

	parent->right = new;

	if (new->right)
		new->right->parent = new;

	return (new);
}
