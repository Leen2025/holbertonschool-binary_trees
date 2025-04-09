#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

int binary_tree_is_complete(const binary_tree_t *tree)
{
if (!tree)
return (0);

queue_t *queue = create_queue();
if (!queue)
return (0);

enqueue(queue, (binary_tree_t *)tree);
bool is_leaf = false;

while (!is_queue_empty(queue))
{
binary_tree_t *node = dequeue(queue);

if (node->left)
enqueue(queue, node->left);
else
is_leaf = true;

if (node->right)
enqueue(queue, node->right);
else
is_leaf = true;

if (is_leaf && (node->left || node->right))
{
free_queue(queue);
return (0);
}
}

free_queue(queue);
return (1);
}
