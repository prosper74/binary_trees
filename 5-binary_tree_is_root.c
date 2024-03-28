#include "binary_trees.h"

/**
* binary_tree_is_root - Checks if a given node is a root
* @node: A pointer to the node to check
*
* Return: 1 if node is a root, otherwise 0
* If node is NULL, return 0
*
* Explanation:
* - This function checks if a given node is a root in the binary tree.
* - If the node is NULL, it returns 0, as a NULL node cannot be a root.
* - It then checks if the node has no parent. If the parent pointer is NULL,
* the node is considered a root, and the function returns 1.
* If the node has a parent, it is not a root, and the function returns 0.
*/

int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL || node->parent != NULL)
	return (0);

return (1);
}
