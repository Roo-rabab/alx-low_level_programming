#include "search_algos.h"

/**
 * _binary_search_Helper - Function that searches for the value to be sorted
 * @array: array of integers (pointer to first element of array to search)
 * @left: left of element (starting index)
 * @right: right of element (ending index)
 * @value: value to search for
 * Return: -1 if not found || index of value
 */

int _binary_search_Helper(int *array, size_t left, size_t right, int value)
{
	size_t x;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (x = left; x < right; x++)
			printf("%d, ", array[x]);
		printf("%d\n", array[x]);

		x = left + (right - left) / 2;
		if (array[x] == value)
			return (x);
		if (array[x] > value)
			right = x - 1;
		else
			left = x + 1;
	}

	return (-1);
}


/**
 * exponential_search - Function that searches for a value in a sorted array
 * @array: Pointer to the first element of the array
 * @size: the number of elements in an array
 * @value: the value to search for
 * Return: index of the value || -1 if not found
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t x = 0;
	size_t  R;

	if (array == NULL || size == 0)
		return (-1);
	if (array[0] != value)
	{
		for (x = 1; x < size && array[x] <= value; x *= 2)
			printf("Value checked array[%ld] = [%d]\n", x, array[x]);
	}

	R = x < size ? x : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", x / 2, R);
	return (_binary_search_Helper(array, x / 2, R, value));
}
