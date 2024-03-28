#include "binary_trees.h"

/**
* binary_tree_size - Measures the size of a binary tree
* @tree: A pointer to the root node of the tree to measure the size
*
* Return: The size of the binary tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t tree_size = 0;

if (tree == NULL)
	return (0);

tree_size += 1;
tree_size += binary_tree_size(tree->left);
tree_size += binary_tree_size(tree->right);

return (tree_size);
}
