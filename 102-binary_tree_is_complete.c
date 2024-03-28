#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
* helper_function - Checks if a binary tree is complete recursively
* @tree: A pointer to the root node of the tree
* @index: The index of the current node
* @nodes: The total number of nodes in the tree
*
* Return: 1 if the binary tree is complete, otherwise 0
*/
int helper_function(const binary_tree_t *tree, size_t index, size_t nodes)
{
if (tree == NULL)
	return (1);

if (index >= nodes)
	return (0);

return (helper_function(tree->left, 2 * index + 1, nodes) &&
helper_function(tree->right, 2 * index + 2, nodes));
}

/**
* binary_tree_is_complete - Checks if a binary tree is complete
* @tree: A pointer to the root node of the tree to check
*
* Return: 1 if the binary tree is complete, otherwise 0
*
* Explanation:
* - The binary_tree_is_complete function serves as a wrapper function
* to initiate the check for completeness.
* - It checks if the input tree is NULL and returns 0 if so,
* as an empty tree cannot be considered complete.
* - The binary_tree_is_complete_util function is a recursive utility
* function that traverses the tree in a depth-first manner while
* keeping track of the index of each node.
* - At each node, it checks if the index of the node is less than the
* total number of nodes in the tree.
* - If the index exceeds the total number of nodes, it indicates that
* there is a gap in the tree, and thus the tree is not complete.
* - The function returns 1 if the tree is complete, meaning it has
* no gaps and all levels except possibly the last level are filled,
* and 0 otherwise.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

return (helper_function(tree, 0, binary_tree_size(tree)));
}
