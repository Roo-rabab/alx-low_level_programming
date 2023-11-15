#include "search_algos.h"

/**
 * linear_skip - Function that searches for a value in a sorted skip list of
 * intergers.
 * @list: pointer to the head of the skip list to search in.
 * @value: The value to search for
 * Return: pointer on the first node where value is located, or NULL if list
 *         is NULL or value not found.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *jump, *node;

	if (list == NULL)
		return (NULL);

	for (node = jump = list; jump->next != NULL && jump->n < value;)
	{
		node = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
				   jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
		   node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	return (node->n == value ? node : NULL);
}
