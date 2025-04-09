#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
binary_tree_t **queue;
size_t front = 0, rear = 0, size = 0, capacity = 1024;
binary_tree_t *node;

if (!tree || !func)
return;

queue = malloc(capacity * sizeof(binary_tree_t *));
if (!queue)
return;

queue[rear++] = (binary_tree_t *)tree;
size++;

while (size > 0)
{
node = queue[front++];
size--;

func(node->n);

if (node->left)
{
if (size == capacity)
{
capacity *= 2;
queue = realloc(queue, capacity * sizeof(binary_tree_t *));
if (!queue)
return;
}
queue[rear++] = node->left;
size++;
}

if (node->right)
{
if (size == capacity)
{
capacity *= 2;
queue = realloc(queue, capacity * sizeof(binary_tree_t *));
if (!queue)
return;
}
queue[rear++] = node->right;
size++;
}

if (front == capacity)
front = 0;
}

free(queue);
}
