#include "main.h"
/**
 * _memset - function that fill memory with  constant byte
 *
 * @s: input pointer to the char type represents the pointer
 *  block of memory to fill.
 *
 *  @b: input variable of char represents the character to fill
 *
 *  @n: unsigned int variable the number of bytes
 *
 *  Return: A pointer to the filled memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	/**
	 * declare an unsigned int because we're storing a
	 * value that always be non-negative (0 or positive)
	 */
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
