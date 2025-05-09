#include "binary_trees.h"
/**
 * binary_tree_is_leaf - function that checks if a node is a leaf.
 * @node: pointer to the node check.
 * Description: A leaf is a node with no children.
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
int n = 0;
if (node != NULL)
{
n = ((node->left == NULL) && (node->right == NULL) ? 1 : 0);
}
return (n);
}
