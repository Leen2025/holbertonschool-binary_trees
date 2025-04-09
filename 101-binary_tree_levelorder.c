#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_node_s - Queue node structure
 * @node: Binary tree node
 * @next: Next node in queue
 */
typedef struct queue_node_s
{
binary_tree_t *node;
struct queue_node_s *next;
} queue_node_t;

/**
 * push - Adds a node to the queue
 * @head: Pointer to the pointer to the head of the queue
 * @tail: Pointer to the pointer to the tail of the queue
 * @node: Binary tree node to add
 */
void push(queue_node_t **head, queue_node_t **tail, binary_tree_t *node)
{
queue_node_t *new = malloc(sizeof(queue_node_t));
if (!new)
return;
new->node = node;
new->next = NULL;
if (!*head)
*head = new;
else
(*tail)->next = new;
*tail = new;
}

/**
 * pop - Removes the node at the front of the queue
 * @head: Pointer to the pointer to the head of the queue
 *
 * Return: The tree node at the front of the queue
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
 * binary_tree_levelorder - Goes through binary tree using level-order
 * @tree: Pointer to the root node
 * @func: Function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
queue_node_t *head = NULL, *tail = NULL;
binary_tree_t *current;

if (!tree || !func)
return;

push(&head, &tail, (binary_tree_t *)tree);

while (head)
{
current = pop(&head);
func(current->n);
if (current->left)
push(&head, &tail, current->left);
if (current->right)
push(&head, &tail, current->right);
}
}
