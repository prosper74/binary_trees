#include "binary_trees.h"

/**
* swap_nodes - Swaps two nodes in a binary tree
* @node1: Pointer to the first node
* @node2: Pointer to the second node
*/
void swap_nodes(heap_t *node1, heap_t *node2)
{
int temp;

temp = node1->n;
node1->n = node2->n;
node2->n = temp;
}

/**
* heapify_down - Moves down the heap to restore the Max Heap property
* @root: Pointer to the root node of the heap
*/
void heapify_down(heap_t *root)
{
heap_t *largest = root;
heap_t *left = root->left;
heap_t *right = root->right;

if (left && left->n > largest->n)
	largest = left;

if (right && right->n > largest->n)
	largest = right;

if (largest != root)
{
	swap_nodes(root, largest);
	heapify_down(largest);
}
}

/**
* get_last_node - Finds the last level-order node of the heap
* @root: Pointer to the root node of the heap
* Return: Pointer to the last level-order node
*/
heap_t *get_last_node(heap_t *root)
{
if (!root)
	return (NULL);

if (!root->left && !root->right)
	return (root);

if (heap_depth(root->left) > heap_depth(root->right))
	return (get_last_node(root->left));
else
	return (get_last_node(root->right));
}

/**
* heap_extract - Extracts the root node of a Max Binary Heap
* @root: Double pointer to the root node of the heap
* Return: The value stored in the root node, or 0 if extraction fails
*/
int heap_extract(heap_t **root)
{
int value;

heap_t *last_node, *temp;

if (root == NULL || *root == NULL)
	return (0);

value = (*root)->n;
last_node = get_last_node(*root);

if (*root == last_node)
{
	free(*root);
	*root = NULL;
	return (value);
}

swap_nodes(*root, last_node);

if (last_node->parent->right)
	last_node->parent->right = NULL;
else
	last_node->parent->left = NULL;

heapify_down(*root);
free(last_node);

return (value);
}

/**
* heap_depth - Measures the depth of a node in a heap
* @node: Pointer to the node to measure the depth
* Return: Depth of the node
*/
size_t heap_depth(const heap_t *node)
{
size_t depth = 0;

while (node && node->parent)
{
	depth++;
	node = node->parent;
}

return (depth);
}
