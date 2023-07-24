#include "main.h"
/**
 * *_memcpy - function that copies memory area.
 * @dest: This is a pointer to the destination
 * @src: This is a pointer to the source
 * @n: number of bytes to be copied //zakaria elaroussi
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i = 0;
while (i < n)
{
dest[i] = src[i];
i++;
}
return (dest);
}
