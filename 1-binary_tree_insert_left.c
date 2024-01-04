#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * This function inserts new node as the left-child of the given parent node.
 * It creates new node specified value and links it to the parent node.
 * If the parent node already has a left-child,new node becomes the left-child
 * and the existing left-child becomes the left-child of the new node.
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 *         NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->right = NULL;
	if (parent->left)
	{
		new->left = parent->left;
		new->left->parent = new;
	}
	else
	{
		new->left = NULL;
	}
	parent->left = new;

	return (new);
}
