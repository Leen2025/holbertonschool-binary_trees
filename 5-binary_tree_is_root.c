#include "binary_trees.h"
/**
 * binary_tree_is_root - function that check if a given node is a root.
 * @node: pointer to the node to check.
 *
 * Return: 1 if node is a root, otherwise 0.If node is NUll, return 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
if (node != NULL && node->parent == NULL)
return (1);
return (0);
}
