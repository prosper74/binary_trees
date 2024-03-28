#include "binary_trees.h"

/**
* binary_tree_is_full - Checks if a binary tree is full
* @tree: A pointer to the root node of the tree to check
*
* Return: 1 if the binary tree is full, 0 otherwise
*
* Explanation:
* - The function binary_tree_is_full checks if a binary tree is full.
* - If the tree is NULL, it returns 0, indicating that an empty tree
* is not full.
* - If the current node is a leaf (both children are NULL),
* it returns 1, indicating that the tree rooted at this node is full.
* - If the current node has both children, it recursively checks
* the left and right subtrees to determine if they are full.
* - If the current node has only one child, it returns 0, indicating
* that the tree rooted at this node is not full.
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

if (tree->left == NULL && tree->right == NULL)
	return (1);

if (tree->left != NULL && tree->right != NULL)
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

return (0);
}
