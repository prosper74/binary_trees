#include "binary_trees.h"

/**
* create_avl_node - Creates a new AVL node
* @value: The value to store in the new node
*
* Return: A pointer to the newly created AVL node,
* or NULL on failure
*/
avl_t *create_avl_node(int value)
{
avl_t *new_node = malloc(sizeof(avl_t));

if (new_node == NULL)
	return (NULL);

new_node->n = value;
new_node->left = NULL;
new_node->right = NULL;

return (new_node);
}

/**
* sorted_array_to_avl - Builds an AVL tree from a sorted array
* @array: A pointer to the first element of the sorted array
* @size: The number of elements in the array
*
* Return: A pointer to the root node of the created AVL tree,
* or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (array == NULL || size == 0)
	return (NULL);

return (sorted_array_to_avl_helper(array, 0, size - 1));
}

/**
* sorted_array_to_avl_helper - Recursively builds an AVL tree from
* a sorted array
* @array: A pointer to the first element of the sorted array
* @start: The starting index of the current subtree in the array
* @end: The ending index of the current subtree in the array
*
* Return: A pointer to the root node of the created AVL tree,
* or NULL on failure
*/
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
if (start > end)
	return (NULL);

int mid = (start + end) / 2;

avl_t *root = create_avl_node(array[mid]);

if (root == NULL)
	return (NULL);

root->left = sorted_array_to_avl_helper(array, start, mid - 1);
root->right = sorted_array_to_avl_helper(array, mid + 1, end);

return (root);
}
