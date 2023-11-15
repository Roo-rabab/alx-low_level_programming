#include "search_algos.h"


/**
 * Search_binary_recursive - Performs recursive binary search.
 * @array: pointer to the first element
 * @R: Starting index.
 * @L: Ending index.
 * @value: The value to search for.
 * Return: -1 || index where value is located
 */

int Search_binary_recursive(int *array, size_t L, size_t R, int value)
{
	size_t x;

	if (R < L)
		return (-1);

	printf("Searching in array: ");
	for (x = L; x < R; x++)
		printf("%d, ", array[x]);
	printf("%d\n", array[x]);

	x = L + (R - L) / 2;
	if (array[x] == value && (x == L || array[x - 1] != value))
		return (x);
	if (array[x] >= value)
		return (Search_binary_recursive(array, L, x, value));
	return (Search_binary_recursive(array, x + 1, R, value));
}

/**
 * advanced_binary - Function that searches a value in a sorted array
 * of intergers.
 * @array: pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: -1 || value
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (Search_binary_recursive(array, 0, size - 1, value));
}
