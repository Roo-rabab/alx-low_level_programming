#include "function_pointers.h"
#include <stdio.h>

void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	(*f)(name);
}
