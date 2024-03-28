#include "binary_trees.h"

/**
* binary_tree_inorder - Goes through a binary tree using in-order traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node
*
* Explanation:
* - In-order traversal visits the left subtree,
* then the current node, and finally the right subtree.
* - The value in each visited node is passed as a parameter to func.
* - If tree or func is NULL, do nothing.
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
