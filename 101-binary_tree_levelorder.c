#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_SIZE 1024

/**
 * enqueue - Adds a node to the queue
 * @queue: The queue to add to
 * @rear: The current position in the queue
 * @node: The node to add
 */
void enqueue(binary_tree_t **queue, size_t *rear, binary_tree_t *node)
{
queue[*rear] = node;
(*rear)++;
}

/**
 * dequeue - Removes a node from the queue
 * @queue: The queue to remove from
 * @front: The current position in the queue
 * Return: The node at the front of the queue
 */
binary_tree_t *dequeue(binary_tree_t **queue, size_t *front)
{
binary_tree_t *node = queue[*front];
(*front)++;
return node;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
binary_tree_t *queue[QUEUE_SIZE];
size_t front = 0, rear = 0;
binary_tree_t *node;

if (!tree || !func)
return;

enqueue(queue, &rear, (binary_tree_t *)tree);

while (front < rear)
{
node = dequeue(queue, &front);

func(node->n);

if (node->left)
enqueue(queue, &rear, node->left);
if (node->right)
enqueue(queue, &rear, node->right);
}
}
