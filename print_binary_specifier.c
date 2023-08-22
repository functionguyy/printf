#include "main.h"
/**
 * print_spec_b_match - function prints the variadic argument specified for the
 * format specifier b
 * @arg: variadic argument
 *
 * Return: returns the number of characters printed to standard output
 */
int print_spec_b_match(va_list arg)
{
	/* declare variables */
	unsigned int n, base;
	int r_value;


	/* initialize variables */
	n = va_arg(arg, unsigned int);
	r_value = 0;
	base = 2;

	if (n == 0)
	{
		r_value += _putchar('0');
		return (r_value);
	}
	if (n < 1)
		return (r_value);


	/* print the integer */
	r_value += print_number(n, base);


	return (r_value);
}
