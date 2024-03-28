#include "binary_trees.h"
#include "17-binary_tree_sibling.c"

/**
* binary_tree_uncle - Finds the uncle of a node in a binary tree
* @node: A pointer to the node to find the uncle
*
* Return: A pointer to the uncle node, or NULL if node is NULL
* or the parent is NULL or the node has no uncle
*
* Explanation:
* - The binary_tree_sibling function is reused from the previous
* implementation.
* - The binary_tree_uncle function finds the uncle of a given node.
* - If the node is NULL or the parent is NULL, it returns NULL,
* indicating that there is no uncle.
* - Otherwise, it calls the binary_tree_sibling function with the
* parent of the node to find the uncle.
* - If the parent has no sibling, it returns NULL,
* indicating that there is no uncle.
* - Otherwise, it returns a pointer to the sibling node, which
* represents the uncle.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
	return (NULL);

return (binary_tree_sibling(node->parent));
}
