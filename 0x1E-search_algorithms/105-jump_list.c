#include "search_algos.h"

/**
 * jump_list - Function that Searches for a value in a sorted list using Jump
 * search.
 * @list: Pointer to the head of the list to search in.
 * @size: The number of nodes in list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t Stp, Stp_size;
	listint_t *jump, *node;

	if (list == NULL || size == 0)
		return (NULL);

	Stp = 0;
	Stp_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (Stp += Stp_size; jump->index < Stp; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
		   node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	return (node->n == value ? node : NULL);
}
