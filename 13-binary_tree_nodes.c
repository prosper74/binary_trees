#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: A pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least 1 child in the binary tree,
 * or 0 if tree is NULL
 *
 * Explanation:
 * - This function counts the nodes with at least one child in a
 * binary tree recursively.
 * - It takes a pointer to the root node of the tree (tree) as input.
 * - If tree is NULL, it returns 0, indicating that the number of nodes
 * with at least one child in an empty tree is 0.
 * - If the current node has at least one child (i.e., it has a left or
 * right child), it returns 1 plus the number of nodes with at least one
 * child in its left and right subtrees. This accounts for counting
 * each node exactly once.
 * - Otherwise, it recursively calculates the number of nodes with
 * at least one child in the left and right subtrees by making recursive
 * calls to binary_tree_nodes.
 * - It then returns the sum of the counts from the left and right
 * subtrees, which represents the total number of nodes with at least
 * one child in the binary tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t tree_nodes = 0;

	if (tree)
	{
		tree_nodes += (tree->left || tree->right) ? 1 : 0;
		tree_nodes += binary_tree_nodes(tree->left);
		tree_nodes += binary_tree_nodes(tree->right);
	}
	return (tree_nodes);
}
