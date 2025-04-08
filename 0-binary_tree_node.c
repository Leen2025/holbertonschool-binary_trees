#include "binary_trees.h"
/**
 * binary_tree_node - function that creates a binary tree.
 *
 * @parent: pointer to the parent node of the node to create.
 * @value : value to put in the new node. 
 *
 * when created, a node does not have any child.
 *
 * Return: pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node_created = NULL;
node_created = malloc(sizeof(binary_tree_t));
if (node_created != NULL)
{
node_created->left  = NULL;
node_created->right = NULL;
node_created->parent = parent;
node_created->n  = value;
}
return (new_node);
}
