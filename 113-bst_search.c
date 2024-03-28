#include "binary_trees.h"

/**
* bst_search - Searches for a value in a Binary Search Tree (BST)
* @tree: A pointer to the root node of the BST to search
* @value: The value to search in the tree
*
* Return: A pointer to the node containing a value equals to value,
* or NULL if tree is NULL or if nothing is found
 *
 * Explanation:
 * - The bst_search function searches for a value in a
 * Binary Search Tree (BST).
 * - It takes a pointer to the root node of the BST (tree)
 * and the value to search for (value).
 * If the tree is NULL, it returns NULL indicating that the value is not found.
 * If the value is found at the current node, it returns a pointer
 * to that node.
 * If the value is less than the current node's value, it recursively
 * searches the left subtree.
 * If the value is greater than the current node's value, it recursively
 * searches the right subtree.
 * If the value is not found in the tree, it returns NULL.
*/
bst_t *bst_search(const bst_t *tree, int value)
{
if (tree == NULL)
	return (NULL);

if (tree->n == value)
	return ((bst_t *)tree);

if (value < tree->n)
	return (bst_search(tree->left, value));

return (bst_search(tree->right, value));
}
