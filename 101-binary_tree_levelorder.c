#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_node_s - Struct for queue node
 * @node: Pointer to the tree node
 * @next: Pointer to the next queue node
 */
typedef struct queue_node_s
{
binary_tree_t *node;
struct queue_node_s *next;
} queue_node_t;

/**
 * push - Adds a node to the end of the queue
 * @tail: Double pointer to the tail of the queue
 * @node: Tree node to add
 *
 * Return: Pointer to the new tail
 */
queue_node_t *push(queue_node_t **tail, binary_tree_t *node)
{
queue_node_t *new = malloc(sizeof(queue_node_t));
if (!new)
return (NULL);
new->node = node;
new->next = NULL;
if (*tail)
(*tail)->next = new;
*tail = new;
return (new);
}

/**
 * pop - Removes a node from the front of the queue
 * @head: Double pointer to the head of the queue
 *
 * Return: Tree node removed from the queue
 */
binary_tree_t *pop(queue_node_t **head)
{
queue_node_t *temp;
binary_tree_t *node;

if (!head || !*head)
return (NULL);
temp = *head;
node = temp->node;
*head = temp->next;
free(temp);
return (node);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node
 * @func: Function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
queue_node_t *head = NULL, *tail = NULL;
binary_tree_t *current;

if (!tree || !func)
return;

push(&tail, (binary_tree_t *)tree);
head = tail;

while (head)
{
current = pop(&head);
if (!current)
continue;
func(current->n);
if (current->left)
push(&tail, current->left);
if (current->right)
push(&tail, current->right);
}
}
