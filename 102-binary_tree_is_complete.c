#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Adds a node to the queue
 * @rear: Pointer to the tail of the queue
 * @node: Binary tree node to enqueue
 * Return: New rear of the queue
 */
queue_node_t *enqueue(queue_node_t **rear, const binary_tree_t *node)
{
queue_node_t *new_node = malloc(sizeof(queue_node_t));
if (!new_node)
return (NULL);
new_node->node = node;
new_node->next = NULL;

if (*rear)
(*rear)->next = new_node;
*rear = new_node;

return new_node;
}

/**
 * dequeue - Removes the front node from the queue
 * @front: Pointer to the head of the queue
 * Return: Node at the front
 */
const binary_tree_t *dequeue(queue_node_t **front)
{
const binary_tree_t *node;
queue_node_t *tmp;

if (!*front)
return (NULL);
tmp = *front;
node = tmp->node;
*front = tmp->next;
free(tmp);
return (node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
queue_node_t *front = NULL, *rear = NULL;
const binary_tree_t *current;
int found_null = 0;

if (!tree)
return (0);

front = enqueue(&rear, tree);

while (front)
{
current = dequeue(&front);

if (current == NULL)
{
found_null = 1;
}
else
{
if (found_null)
return (0);
enqueue(&rear, current->left);
enqueue(&rear, current->right);
}
}
while (front)
dequeue(&front);
return (1);
}
