#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: A pointer to the first node
* @second: A pointer to the second node
*
* Return: A pointer to the lowest common ancestor node,
* or NULL if no common ancestor was found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
const binary_tree_t *ancestor;

if (first == NULL || second == NULL)
	return (NULL);

ancestor = first;

while (ancestor != NULL)
{
	if (binary_tree_is_descendant(ancestor, second))
	return ((binary_tree_t *)ancestor);
	ancestor = ancestor->parent;
}

return (NULL);
}

/**
* binary_tree_is_descendant - Checks if a node is a descendant of another node
* @ancestor: A pointer to the potential ancestor node
* @descendant: A pointer to the potential descendant node
*
* Return: 1 if descendant is a descendant of ancestor, otherwise 0
*
* Explanation:
* - The binary_trees_ancestor function iterates through the ancestors of
* the first node.
* At each iteration, it checks if the current ancestor is a descendant of
* the second node using the binary_tree_is_descendant function.
* - If it finds an ancestor that is a descendant of the second node,
* it returns that ancestor as the lowest common ancestor.
* If no common ancestor is found, it returns NULL.
* - The binary_tree_is_descendant function recursively checks if a given
* node is a descendant of another node by traversing the tree recursively.
* - If the given ancestor node is NULL, it returns 0.
* - If the ancestor and descendant nodes are the same, it returns 1,
* indicating that the descendant is indeed a descendant of the ancestor.
* - Otherwise, it recursively checks if the descendant node is a descendant
* of either the left or right subtree of the current ancestor node.
*/
int binary_tree_is_descendant(const binary_tree_t *ancestor,
const binary_tree_t *descendant)
{
if (ancestor == NULL)
	return (0);

if (ancestor == descendant)
	return (1);

return (binary_tree_is_descendant(ancestor->left, descendant)
|| binary_tree_is_descendant(ancestor->right, descendant));
}
