#include "main.h"
/**
 * print_spec_c_match - function prints the variadic character specified for
 * the fornat specifier c
 * @arg: variadic argument
 *
 * Return: returns the number of character print to standard output
 */
int print_spec_c_match(va_list arg)
{
	/* declare variables */
	char c;
	unsigned int writeCount;

	/* initialize variables */
	c = va_arg(arg, int);
	writeCount = 0;

	/* print the character specified for the specifier */
	writeCount = _putchar(c)

	return (writeCount);
}
