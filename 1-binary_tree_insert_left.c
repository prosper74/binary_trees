#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the left-child
* of another node
* @parent: A pointer to the node to insert the left-child in
* @value: The value to store in the new node
*
* Return: A pointer to the created node,
* or NULL on failure or if parent is NULL
* If parent already has a left-child,
* the new node takes its place, and
* the old left-child becomes the left-child of the new node.
*
* Explanation:
* - This function inserts a new node as the left-child of a given parent node.
* - It first checks if the parent node is not NULL.
* - Then, it allocates memory for the new node and
*			initializes it with the provided value.
* - If the parent already has a left child, the new node takes its place,
*			and the old left-child becomes the left-child of the new node.
* - Finally, it returns a pointer to the new node.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

if (parent == NULL)
	return (NULL);

new_node = binary_tree_node(parent, value);
if (new_node == NULL)
	return (NULL);

if (parent->left != NULL)
{
	new_node->left = parent->left;
	parent->left->parent = new_node;
}
parent->left = new_node;

return (new_node);
}
