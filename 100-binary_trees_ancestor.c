#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
const binary_tree_t *a, *b;

if (!first || !second)
return (NULL);

a = first;
while (a)
{
b = second;
while (b)
{
if (a == b)
return ((binary_tree_t *)a);
b = b->parent;
}
a = a->parent;
}
return (NULL);
}
