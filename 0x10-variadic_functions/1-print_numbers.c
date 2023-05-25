#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Prints numbers followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: A variable number of integers to print.
 *
 * Description: This function prints a variable number of integers,
 * separated by the specified separator string. If the separator is NULL,
 * it is not printed. The function then prints a new line character.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator != NULL && i < n - 1)
		printf("%s", separator);
	}

	va_end(ap);

	printf("\n");
}
