#include "binary_trees.h"

/**
* bst_remove - Removes a node from a Binary Search Tree (BST)
* @root: A pointer to the root node of the tree
* @value: The value to remove from the tree
*
* Return: A pointer to the new root node of the tree after removing the value
*/
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *temp;

if (root == NULL)
	return (NULL);

if (value < root->n)
	root->left = bst_remove(root->left, value);
else if (value > root->n)
	root->right = bst_remove(root->right, value);
else
{
	if (root->left == NULL && root->right == NULL)
	{
	free(root);
	return (NULL);
	}
	else if (root->left == NULL)
	{
	temp = root->right;

	free(root);
	return (temp);
	}
	else if (root->right == NULL)
	{
	temp = root->left;
	free(root);
	return (temp);
	}
	else
	root->n = bst_remove_successor(root->right)->n;
}
return (root);
}

/**
* bst_remove_successor - Finds and removes the first in-order successor
* of a given node in a Binary Search Tree (BST)
* @node: A pointer to the node whose successor is to be removed
*
* Return: A pointer to the removed successor node
*/
bst_t *bst_remove_successor(bst_t *node)
{
bst_t *current = node;

while (current && current->left != NULL)
	current = current->left;

if (current != NULL)
	node->right = bst_remove(node->right, current->n);

return (current);
}
