#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: points to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: a pointer to the created node, or NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (!parent)
	{
		free(new_node);
		return (NULL);
	}
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	new_node->parent = parent;
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
