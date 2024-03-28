#include "binary_trees.h"
#include "0-binary_tree_node.c"
#include "9-binary_tree_height.c"

/**
* heap_insert - Inserts a value in Max Binary Heap
* @root: A double pointer to the root node of the Heap
* @value: The value to store in the node to be inserted
*
* Return: A pointer to the created node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node, *parent;

if (root == NULL)
	return (NULL);

new_node = binary_tree_node(NULL, value);
if (new_node == NULL)
	return (NULL);

if (*root == NULL)
{
	*root = new_node;
	return (new_node);
}

parent = find_parent(*root);

if (parent->left == NULL)
	parent->left = new_node;
else
	parent->right = new_node;

new_node->parent = parent;

heapify(new_node);
return (new_node);
}

/**
* find_parent - Finds the parent to insert a new node
* @root: A pointer to the root node of the tree
*
* Return: A pointer to the parent node
*/
heap_t *find_parent(heap_t *root)
{
heap_t *parent;
int bit;

for (bit = (1 << (binary_tree_height(root) + 1)) - 1; bit > 1; bit >>= 1)
{
	parent = find_parent_helper(root, bit);
	if (parent != NULL)
	return (parent);
}

return (root);
}

/**
* find_parent_helper - Finds the parent recursively
* @root: A pointer to the root node of the tree
* @bit: Bit mask to check
*
* Return: A pointer to the parent node
*/
heap_t *find_parent_helper(heap_t *root, int bit)
{
if (root == NULL)
	return (NULL);

if (bit == 1)
	return (root);

if (bit & 1)
	return (find_parent_helper(root->left, bit >> 1));
else
	return (find_parent_helper(root->right, bit >> 1));
}

/**
* heapify - Corrects Max Heap ordering after insertion
* @node: A pointer to the newly inserted node
*/
void heapify(heap_t *node)
{
int temp;

while (node->parent != NULL && node->n > node->parent->n)
{
	temp = node->n;
	node->n = node->parent->n;
	node->parent->n = temp;
	node = node->parent;
}
}
