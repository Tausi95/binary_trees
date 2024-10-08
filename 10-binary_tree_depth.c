#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (!tree || !tree->parent)
        return (0);

    /* Recurse up the tree, adding one for each level */
    return (binary_tree_depth(tree->parent) + 1);
}
