#include "search_algos.h"
#include <math.h>

/*Remember compiling "math.h" with gcc requires `-lm` */

size_t min(size_t a, size_t b);

/**
 * min - returns the minimum of two size_t values
 * @a: first value
 * @b: second value
 *
 * Return: `a` if lower or equal to `b`, `b` otherwise
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * jump_search - Function that searches for a value in a sorted array of
 * integers using a jump search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @size:  the number of elements in array
 * @value:  the value to search for
 *
 * Return: The first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, Index_prev;

	if (array == NULL || size == 0)
		return (-1);

	/* Handle invalid input */
	jump = sqrt(size);
	for (i = Index_prev = 0; Index_prev < size && array[Index_prev] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", Index_prev, array[Index_prev]);
		i = Index_prev;
		Index_prev += jump;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, Index_prev);

	Index_prev = Index_prev < size - 1 ? Index_prev : size - 1;
	for (; i < Index_prev && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
