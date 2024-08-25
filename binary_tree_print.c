#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480
 * Updated for improved readability and dynamic buffer sizing
 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[12];  // Increased buffer size to accommodate larger numbers
    int width, left, right, is_left, i;

    if (!tree)
        return (0);

    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);
    left = print_t(tree->left, offset, depth + 1, s);
    right = print_t(tree->right, offset + left + width, depth + 1, s);

    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }

    return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    size_t height_l = _height(tree->left);
    size_t height_r = _height(tree->right);

    return (height_l > height_r ? height_l : height_r) + 1;
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, i, j;

    if (!tree)
        return;

    height = _height(tree);
    s = malloc(sizeof(*s) * height);
    if (!s)
        return;

    for (i = 0; i < height; i++)
    {
        s[i] = malloc(2 * (1 << (height - i)) - 1);
        if (!s[i])
        {
            while (i-- > 0)
                free(s[i]);
            free(s);
            return;
        }
        memset(s[i], ' ', 2 * (1 << (height - i)) - 1);
        s[i][2 * (1 << (height - i)) - 2] = '\0';
    }

    print_t(tree, 0, 0, s);

    for (i = 0; i < height; i++)
    {
        for (j = strlen(s[i]) - 1; j > 0 && s[i][j] == ' '; j--)
            s[i][j] = '\0';
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}

