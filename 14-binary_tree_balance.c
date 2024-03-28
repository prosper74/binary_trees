#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: A pointer to the root node of the tree to measure the height
*
* Return: The height of the binary tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree)
{
	size_t l = 0, r = 0;

	l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((l > r) ? l : r);
}
return (0);
}

/**
* binary_tree_balance - Measures the balance factor of a binary tree
* @tree: A pointer to the root node of the tree to measure the balance factor
*
* Return: The balance factor of the binary tree, or 0 if tree is NULL
*
* Explanation:
* - The binary_tree_height function is reused from the previous
* implementation.
* - The binary_tree_balance function calculates the balance
* factor of a binary tree.
* - If the tree is NULL, the balance factor is considered 0.
* - Otherwise, it calculates the height of the left and right
* subtrees and subtracts the right height from the left height
* to get the balance factor.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
if (tree)
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

return (0);
}
