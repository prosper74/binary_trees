#include "binary_trees.h"

/**
* binary_tree_postorder - Goes through a binary tree
* using post-order traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node
*
* Explanation:
* - Post-order traversal visits the left subtree,
* then the right subtree, and finally the current node.
* - The value in each visited node is passed as a parameter to func.
* If tree or func is NULL, do nothing.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
	return;

binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
