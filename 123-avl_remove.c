#include "binary_trees.h"

/* Function prototypes */
int avl_remove_helper(avl_t **root, int value);
avl_t *avl_remove_successor(avl_t *node);

/**
* avl_remove - Removes a node from an AVL tree
* @root: A pointer to the root node of the tree
* @value: The value to remove
*
* Return: A pointer to the new root node of the tree after
* removal and rebalancing
*/
avl_t *avl_remove(avl_t *root, int value)
{
if (root == NULL)
	return (NULL);

if (!avl_remove_helper(&root, value))
	return (root);

return (root);
}

/**
* avl_remove_helper - Removes a node from an AVL tree (helper function)
* @root: A double pointer to the root node of the tree
* @value: The value to remove
*
* Return: 1 if the value was removed, 0 otherwise
*/
int avl_remove_helper(avl_t **root, int value)
{
if (*root == NULL)
	return (0);

if ((*root)->n == value)
{
	if ((*root)->left == NULL || (*root)->right == NULL)
	{
	avl_t *temp = *root;
	*root = ((*root)->left != NULL) ? (*root)->left : (*root)->right;
	free(temp);
	}
	else
	{
	avl_t *temp = avl_remove_successor(*root);
	(*root)->n = temp->n;
	free(temp);
	}
	return (1);
}

if (value < (*root)->n)
	return (avl_remove_helper(&(*root)->left, value));
else
	return (avl_remove_helper(&(*root)->right, value));
}

/**
* avl_remove_successor - Finds and removes the first in-order
* successor of a node
* @node: A pointer to the node to remove the successor from
*
* Return: A pointer to the removed successor node
*/
avl_t *avl_remove_successor(avl_t *node)
{
avl_t *successor = node->right;

while (successor->left != NULL)
	successor = successor->left;

avl_remove_helper(&node->right, successor->n);
return (successor);
}
