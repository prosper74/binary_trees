#include "binary_trees.h"

/**
* binary_tree_depth - Measures the depth of a node in a binary tree
* @tree: A pointer to the node to measure the depth
*
* Return: The depth of the node in the binary tree, or 0 if tree is NULL
*
* Explanation:
* - CHeck if tree exist and the parent node exist
* - If true, return the bianry_tree_depth + 1
* - If false, return 0
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
