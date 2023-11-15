#include "search_algos.h"

/**
 * interpolation_search - Function that searches for a value in a sorted array
 * @array:  pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value:  the value to search for
 * Return: first index where value is located
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t R, L, x;

	if (array == NULL)
		return (-1);

	for (L = 0, R = size - 1; R >= L;)
	{
		x = L + (((double)(R - L) / (array[R] - array[L])) * (value - array[L]));
		if (x < size)
			printf("Value checked array[%ld] = [%d]\n", x, array[x]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", x);
			break;
		}

		if (array[x] == value)
			return (x);
		if (array[x] > value)
			R = x - 1;
		else
			L = x + 1;
	}
	return (-1);
}
