#include "binary_trees.h"

/**
* level_order_queue_enqueue - Enqueues a node into the level-order
* traversal queue
* @queue: The current level-order traversal queue
* @node: The node to enqueue
*
* Return: A pointer to the updated level-order traversal queue
*/
level_order_queue_t *level_order_queue_enqueue(level_order_queue_t *queue,
											binary_tree_t *node)
{
level_order_queue_t *new_node, *temp;

new_node = malloc(sizeof(level_order_queue_t));
if (new_node == NULL)
	return (NULL);

new_node->node = node;
new_node->next = NULL;

if (queue == NULL)
	return (new_node);

temp = queue;
while (temp->next != NULL)
	temp = temp->next;

temp->next = new_node;
return (queue);
}

/**
* level_order_queue_dequeue - Dequeues a node from the level-order
* traversal queue
* @queue: The current level-order traversal queue
*
* Return: A pointer to the updated level-order traversal queue
*/
level_order_queue_t *level_order_queue_dequeue(level_order_queue_t *queue)
{
level_order_queue_t *temp;

if (queue == NULL)
	return (NULL);

temp = queue;
queue = queue->next;
free(temp);

return (queue);
}

/**
* binary_tree_levelorder - Goes through a binary tree using level-order
*                          traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node
*
* Explanation:
* This function traverses the binary tree in level-order, also
* known as breadth-first traversal. It starts at the root node
* and visits all nodes at each level from left to right.
* For each visited node, the given function 'func' is called,
* passing the value of the node as a parameter.
* If 'tree' or 'func' is NULL, this function does nothing.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
level_order_queue_t *queue = NULL;
const binary_tree_t *current;

if (tree == NULL || func == NULL)
	return;

queue = level_order_queue_enqueue(queue, (binary_tree_t *)tree);

while (queue != NULL)
{
	current = queue->node;
	func(current->n);

	if (current->left != NULL)
	queue = level_order_queue_enqueue(queue, current->left);
	if (current->right != NULL)
	queue = level_order_queue_enqueue(queue, current->right);

	queue = level_order_queue_dequeue(queue);
}
}
