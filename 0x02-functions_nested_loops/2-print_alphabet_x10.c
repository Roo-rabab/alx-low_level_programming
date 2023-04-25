#include "main.h"

/**
* print_alphabet_x10 - prints 10 times the alphabet, in lowercase,
*
*/
void print_alphabet_x10(void)
{
	int line, ch;

	for (line = 0; line <= 9; line++)
	{
		for (ch = 'a'; ch <= 'Z'; ch++)
			_putchar(ch);
		_putchar('\n');
	}
}
