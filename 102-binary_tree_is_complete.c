#include "binary_trees.h"
#include <stdlib.h>
#include <stdbool.h>  // for bool, true, false

/**
 * struct queue_node_s - Node structure for queue
 * @node: Binary tree node
 * @next: Pointer to next node in the queue
 */
typedef struct queue_node_s
{
    binary_tree_t *node;
    struct queue_node_s *next;
} queue_node_t;

/**
 * struct queue_s - Queue structure
 * @head: First node in the queue
 * @tail: Last node in the queue
 */
typedef struct queue_s
{
    queue_node_t *head;
    queue_node_t *tail;
} queue_t;

/**
 * create_queue - Creates a new queue
 * Return: Pointer to the newly created queue
 */
queue_t *create_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return NULL;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

/**
 * enqueue - Adds a node to the queue
 * @queue: Pointer to the queue
 * @node: Binary tree node to add to the queue
 */
void enqueue(queue_t *queue, binary_tree_t *node)
{
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return;
    new_node->node = node;
    new_node->next = NULL;

    if (!queue->tail)
        queue->head = new_node;
    else
        queue->tail->next = new_node;

    queue->tail = new_node;
}

/**
 * dequeue - Removes a node from the queue
 * @queue: Pointer to the queue
 * Return: The binary tree node that was dequeued
 */
binary_tree_t *dequeue(queue_t *queue)
{
    if (!queue->head)
        return NULL;

    queue_node_t *temp = queue->head;
    binary_tree_t *node = temp->node;
    queue->head = queue->head->next;
    if (!queue->head)
        queue->tail = NULL;

    free(temp);
    return node;
}

/**
 * is_queue_empty - Checks if the queue is empty
 * @queue: Pointer to the queue
 * Return: 1 if the queue is empty, 0 otherwise
 */
int is_queue_empty(queue_t *queue)
{
    return (queue->head == NULL);
}

/**
 * free_queue - Frees the queue
 * @queue: Pointer to the queue
 */
void free_queue(queue_t *queue)
{
    while (queue->head)
    {
        queue_node_t *temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
    }
    free(queue);
}
