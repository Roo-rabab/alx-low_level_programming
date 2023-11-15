#include "search_algos.h"

/**
 * binary_search - Function that searches for a value in an integer array
 * using a binary search algorithm, not guaranteed to return lowest index
 * if `value` appears twice in `array`
 *
 * @array: Pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: index of `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	int L, Mid, H, i;

	if (array == NULL)
		return (-1);

	L = 0;
	H = size - 1;
	while (L <= H)
	{
		Mid = (L + H) / 2;

		printf("Searching in array: ");
		for (i = L; i <= H; i++)
			printf("%i%s", array[i], i == H ? "\n" : ", ");

		if (array[Mid] < value)
			L = Mid + 1;
		else if (array[Mid] > value)
			H = Mid - 1;
		else
			return (Mid);
	}
	return (-1);
}
