#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
return (NULL);
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;
return (new_node);
}

size_t heap_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (1 + heap_size(tree->left) + heap_size(tree->right));
}

heap_t *heap_get_parent(heap_t *root, size_t index)
{
size_t path[32], depth = 0;
size_t i;
heap_t *current = root;

while (index > 1)
{
path[depth++] = index % 2;
index /= 2;
}

for (i = depth; i > 1; i--)
{
if (path[i - 1] == 0)
current = current->left;
else
current = current->right;
}

return (current);
}

heap_t *heapify_up(heap_t *node)
{
int tmp;

while (node->parent && node->n > node->parent->n)
{
tmp = node->n;
node->n = node->parent->n;
node->parent->n = tmp;
node = node->parent;
}
return (node);
}

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *parent, *new_node;
size_t index;

if (!root)
return (NULL);

if (!*root)
{
*root = binary_tree_node(NULL, value);
return (*root);
}

index = heap_size(*root) + 1;
parent = heap_get_parent(*root, index);
if (!parent)
return (NULL);

if (!(parent->left))
parent->left = binary_tree_node(parent, value), new_node = parent->left;
else
parent->right = binary_tree_node(parent, value), new_node = parent->right;

if (!new_node)
return (NULL);

return (heapify_up(new_node));
}
