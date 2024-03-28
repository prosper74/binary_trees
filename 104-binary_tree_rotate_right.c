#include "binary_trees.h"

/**
* binary_tree_rotate_right - Performs a right-rotation on a binary tree
* @tree: A pointer to the root node of the tree to rotate
*
* Return: A pointer to the new root node of the tree once rotated
*
* Explanation:
* - The binary_tree_rotate_right function performs a right rotation
* on the given binary tree.
* It first checks if the input tree is NULL or if it doesn't have a
* left child. In such cases, it cannot perform a right rotation,
* so it returns NULL.
* If the conditions are met, it proceeds with the rotation:
*    It assigns the left child of the original root to new_root.
*    It updates the parent pointers of the nodes involved in the rotation.
*    It rearranges the pointers to perform the right rotation.
* - Finally, it returns a pointer to the new root node of the rotated tree.
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *new_root;

if (tree == NULL || tree->left == NULL)
	return (NULL);

new_root = tree->left;
tree->left = new_root->right;
if (new_root->right != NULL)
	new_root->right->parent = tree;

new_root->parent = tree->parent;

if (tree->parent != NULL)
{
	if (tree->parent->left == tree)
	tree->parent->left = new_root;
	else
	tree->parent->right = new_root;
}

tree->parent = new_root;
new_root->right = tree;

return (new_root);
}
