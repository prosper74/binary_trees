#include "binary_trees.h"
#include "121-avl_insert.c"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t count1, count2;

	if (array == NULL)
		return (NULL);

	for (count1 = 0; count1 < size; count1++)
	{
		for (count2 = 0; count2 < count1; count2++)
		{
			if (array[count2] == array[count1])
				break;
		}
		if (count2 == count1)
		{
			if (avl_insert(&tree, array[count1]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
