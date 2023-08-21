#include "main.h"
/**
 * print_number - function that prints a positive integer
 * @digit: a positive number
 *
 * Return: returns the number of characters printed to standard output
 */
int print_number(unsigned int digit)
{
	/* declare variables */
	unsigned int exponent, count, num, number;
	int r_value;

	/* initialize variables */
	count = 0;
	exponent = 1;
	r_value = 0;
	num = digit;

	/* get the number of tens in the number */
	while (digit > 0)
	{
		digit = digit / 10;
		count++;
	}

	/* calculate its exponent */
	while (count > 1)
	{
		exponent = exponent * 10;
		count--;
	}

	/* print the integer */
	while (exponent > 0)
	{
		number = num / exponent;
		r_value += _putchar(number + '0');
		num = num - (number * exponent);
		exponent /= 10;
	}

	return (r_value);
}
/**
 * print_spec_d_match - function prints the variadic argument specified for the
 * format specifier d
 * @arg: variadic argument
 *
 * Return: returns the number of characters printed to stardard output
 */
int print_spec_d_match(va_list arg)
{
	/* declare variable */
	int n, r_value;
	unsigned int num;

	/* initialize variables */
	n = va_arg(arg, int);
	r_value = 0;

	/* account for negative number */
	if (n < 0)
	{
		num = n * -1;
		r_value += _putchar('-');
	}
	else
		num = n;

	/* print the integer */
	r_value += print_number(num);

	return (r_value);
}
