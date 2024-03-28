#include "binary_trees.h"

/**
* binary_tree_leaves - Counts the leaves in a binary tree
* @tree: A pointer to the root node of the tree to count the leaves
*
* Return: The number of leaves in the binary tree, or 0 if tree is NULL
*
* Explanation:
* - This function counts the leaves in a binary tree recursively.
* - It takes a pointer to the root node of the tree (tree) as input.
* - If tree is NULL, it returns 0, indicating that the number of
* leaves in an empty tree is 0.
* - If the current node is a leaf (i.e., it has no left or right
* child), it returns 1.
* - Otherwise, it recursively calculates the number of leaves in the
* left and right subtrees by making recursive calls to
* binary_tree_leaves on each subtree.
* - It then returns the sum of the number of leaves in the left and
* right subtrees, which represents the total number of leaves
* in the binary tree.
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t tree_leaves = 0;

	if (tree)
	{
		tree_leaves += (!tree->left && !tree->right) ? 1 : 0;
		tree_leaves += binary_tree_leaves(tree->left);
		tree_leaves += binary_tree_leaves(tree->right);
	}
	return (tree_leaves);
}
