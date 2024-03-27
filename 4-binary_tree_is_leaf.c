#include "binary_trees.h"

/**
* binary_tree_is_leaf - Checks if a node is a leaf
* @node: A pointer to the node to check
*
* Return: 1 if node is a leaf, otherwise 0
*         If node is NULL, return 0
*
* Explanation:
* - This function checks if a given node is a leaf in the binary tree.
* - If the node is NULL, it returns 0, as a NULL node cannot be a leaf.
* - It then checks if the node has no left or right child. If
* both child pointers are NULL, the node is considered a leaf,
* and the function returns 1.
* - If the node has at least one child, it is not a leaf, and
* the function returns 0.
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL || node->left != NULL || node->right != NULL)
	return (0);

return (1);
}
