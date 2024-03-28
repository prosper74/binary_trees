#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a node in a binary tree
* @node: A pointer to the node to find the sibling
*
* Return: A pointer to the sibling node, or NULL if node is NULL,
* the parent is NULL, or node has no sibling
*
* Explanation:
* - This function finds the sibling of a node in a binary tree.
* - It takes a pointer to the node to find the sibling (node) as input.
* - If node is NULL or the parent is NULL, it returns NULL,
* indicating that there is no sibling.
* - If node is the left child of its parent, it returns a pointer to the
* right child (sibling) of the parent.
* If node is the right child of its parent, it returns a pointer to the
* left child (sibling) of the parent.
* If node is neither the left nor the right child of its parent,
* it returns NULL, indicating that there is no sibling.
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
	return (NULL);

if (node->parent->left == node)
	return (node->parent->right);

if (node->parent->right == node)
	return (node->parent->left);

return (NULL);
}
