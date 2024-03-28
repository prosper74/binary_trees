#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: A pointer to the root node of the tree to measure the height
*
* Return: The height of the binary tree, or 0 if tree is NULL
*
* Explanation:
* - This function measures the height of a binary tree recursively.
* - It takes a pointer to the root node of the tree (tree) as input.
* - If tree is NULL, it returns 0, indicating that the height
* of an empty tree is 0.
* - Otherwise, it recursively calculates the height of the left
* and right subtrees.
* - The height of the current tree is the maximum height between
* the left and right subtrees, plus 1 for the current node.
* - It returns this calculated height.
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree)
{
	left_height = 0;
	right_height = 0;

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return ((left_height > right_height) ? left_height : right_height);
}

return (0);
}
