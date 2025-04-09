#include "binary_trees.h"
#include <stdlib.h>

queue_t *create_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return (NULL);
    queue->front = queue->rear = NULL;
    return (queue);
}

void enqueue(queue_t *queue, binary_tree_t *node)
{
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return;

    new_node->node = node;
    new_node->next = NULL;
    
    if (queue->rear)
        queue->rear->next = new_node;
    else
        queue->front = new_node;
    
    queue->rear = new_node;
}

binary_tree_t *dequeue(queue_t *queue)
{
    if (!queue || !queue->front)
        return (NULL);

    queue_node_t *temp = queue->front;
    binary_tree_t *node = temp->node;

    queue->front = queue->front->next;
    if (!queue->front)
        queue->rear = NULL;

    free(temp);
    return (node);
}

int is_queue_empty(queue_t *queue)
{
    return (queue->front == NULL);
}

void free_queue(queue_t *queue)
{
    while (queue && !is_queue_empty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}
