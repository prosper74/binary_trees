#include "binary_trees.h"

/**
* binary_tree_preorder - Goes through a binary tree using pre-order traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node
*
* Explanation:
* - This function performs a pre-order traversal of a binary tree,
* starting from the root node.
* - It takes two parameters: tree, which is a pointer to the root node
* of the tree to traverse, and func, which is a pointer to a function
* to call for each node.
* - If either tree or func is NULL, the function does nothing and returns.
* Otherwise, it calls the func function to process the value of
* the current node.
* - Then, it recursively calls binary_tree_preorder on the left subtree
* and then on the right subtree to traverse the entire tree in pre-order.
*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
	return;

func(tree->n);
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
