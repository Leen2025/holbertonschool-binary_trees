#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full. 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
int left, right;
if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (1);
if ((tree->left) && (tree->right))
{
left = binary_tree_is_full(tree->left);
right = binary_tree_is_full(tree->right);
return (left && right);
}
return (0);
}
