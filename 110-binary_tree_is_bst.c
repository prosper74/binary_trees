#include "binary_trees.h"

/**
* binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
* @tree: A pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid BST, 0 otherwise
*
* Explanation:
* - The binary_tree_is_bst function recursively checks if the given
* binary tree is a valid BST.
* - It maintains a static pointer prev to keep track of the previous
* node visited during the in-order traversal.
* - It recursively checks the left subtree first.
* - Then, it checks the current node by comparing its value with
* the value of the previous node.
* - If the current node's value is not greater than the previous
* node's value, the function returns 0, indicating that the tree
* is not a valid BST.
* - If all nodes in the left subtree and the current node pass the
* BST conditions, it recursively checks the right subtree.
* Finally, it returns 1 if all nodes in the tree satisfy the BST properties,
* indicating that the tree is a valid BST.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
static const binary_tree_t *prev;

if (tree == NULL)
	return (0);

if (!binary_tree_is_bst(tree->left))
	return (0);

if (prev != NULL && tree->n <= prev->n)
	return (0);

prev = tree;
return (binary_tree_is_bst(tree->right));
}
