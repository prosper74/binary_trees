#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: A pointer to the first node
* @second: A pointer to the second node
*
* Return: If no common ancestors return NULL, else return common ancestor.
*
* Explanation:
* - This function finds the lowest common ancestor of two nodes
* in a binary tree.
* - It recursively traverses up the tree from each node,
* checking for common ancestors until it finds one.
* - Finally, the function returns the common ancestor found by
* recursively calling itself with updated parent nodes (mother and father).
* If no common ancestor is found, it returns NULL.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *mother, *father;

if (!first || !second)
	return (NULL);

if (first == second)
	return ((binary_tree_t *)first);

mother = first->parent, father = second->parent;
if (first == father || !mother || (!mother->parent && father))
	return (binary_trees_ancestor(first, father));
else if (mother == second || !father || (!father->parent && mother))
	return (binary_trees_ancestor(mother, second));
return (binary_trees_ancestor(mother, father));
}
