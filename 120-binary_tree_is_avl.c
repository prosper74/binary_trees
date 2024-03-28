#include "binary_trees.h"

/**
* binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
* @tree: A pointer to the root node of the tree
*
* Return: 1 if tree is a valid AVL Tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

if (!binary_tree_is_bst(tree))
	return (0);

if (abs(binary_tree_height(tree->left) - binary_tree_height(tree->right)) > 1)
	return (0);

if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
	return (0);

return (1);
}

/**
* binary_tree_is_bst - Checks if a binary tree is a valid
* Binary Search Tree (BST)
* @tree: A pointer to the root node of the tree
*
* Return: 1 if tree is a valid BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (tree == NULL)
	return (1);

if (tree->left != NULL && tree->left->n >= tree->n)
	return (0);

if (tree->right != NULL && tree->right->n <= tree->n)
	return (0);

if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
	return (0);

return (1);
}

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: A pointer to the root node of the tree
*
* Return: The height of the tree
*/
int binary_tree_height(const binary_tree_t *tree)
{
int left_height, right_height;

if (tree == NULL)
	return (-1);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return ((left_height > right_height ? left_height : right_height) +1);
}
