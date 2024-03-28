#include "binary_trees.h"

/**
* binary_tree_rotate_left - Performs a left-rotation on a binary tree
* @tree: A pointer to the root node of the tree to rotate
*
* Return: A pointer to the new root node of the tree once rotated
*
* Explanation:
* - The binary_tree_rotate_left function performs a left rotation
* on the given binary tree.
* - It first checks if the input tree is NULL or if it doesn't have
* a right child. In such cases, it cannot perform a left rotation,
* so it returns NULL.
* - If the conditions are met, it proceeds with the rotation:
*     It assigns the right child of the original root to new_root.
*     It updates the parent pointers of the nodes involved in the rotation.
*     It rearranges the pointers to perform the left rotation.
* - Finally, it returns a pointer to the new root node of the rotated tree.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *new_root;

if (tree == NULL || tree->right == NULL)
	return (NULL);

new_root = tree->right;
tree->right = new_root->left;
if (new_root->left != NULL)
	new_root->left->parent = tree;

new_root->parent = tree->parent;
if (tree->parent != NULL)
{
	if (tree->parent->left == tree)
	tree->parent->left = new_root;
	else
	tree->parent->right = new_root;
}

tree->parent = new_root;
new_root->left = tree;

return (new_root);
}
