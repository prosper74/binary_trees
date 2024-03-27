#include "binary_trees.h"

/**
* binary_tree_delete - Deletes an entire binary tree
* @tree: A pointer to the root node of the tree to delete
*
* Explanation:
* - This function recursively deletes the entire binary tree
* starting from the root node.
* - It follows a post-order traversal approach, where it first
* deletes the left subtree, then the right subtree, and
* finally the current node.
* - The function checks if the tree pointer is NULL, and if so,
* it does nothing (base case).
* - If tree is not NULL, it recursively calls binary_tree_delete
* on the left and right subtrees.
* - After deleting the subtrees, it frees the memory allocated
* for the current node using the free function.
*/
void binary_tree_delete(binary_tree_t *tree)
{
if (tree == NULL)
	return;

binary_tree_delete(tree->left);
binary_tree_delete(tree->right);
free(tree);
}
