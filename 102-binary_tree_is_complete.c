#include "binary_trees.h"
#include <stdbool.h>  // Include for the bool type

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
queue_t *queue;
bool is_leaf = false;

if (!tree)
return (0);

queue = create_queue();
if (!queue)
return (0);

enqueue(queue, (binary_tree_t *)tree);

while (!is_queue_empty(queue))
{
binary_tree_t *node = dequeue(queue);

if (node->left)
{
enqueue(queue, node->left);
}
else
{
is_leaf = true;
}

if (node->right)
{
if (is_leaf)
{
free_queue(queue);
return (0);
}
enqueue(queue, node->right);
}
else
{
is_leaf = true;
}
}

free_queue(queue);
return (1);
}
