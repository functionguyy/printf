#include "main.h"
/**
 * convert_to_hex - converts a positive integer to its hexadecimal
 * representation in uppercase alphabetic letter
 * @number: positive integer
 *
 * Return: returns the ascii value for the uppercase letter of the hex notation
 */
int convert_to_hex(unsigned int number)
{
	/* declare variables */
	c_t conversion_table[] = {
		{10, "A"},
		{11, "B"},
		{12, "C"},
		{13, "D"},
		{14, "E"},
		{15, "F"}
	};
	int i, asciiVal;
	char *s, uppercaseChar;

	/* iniitialize variables */
	i = 0;

	/* seek the hexadecimal notation */
	while (conversion_table[i].numConst != number)
		i++;

	s = conversion_table[i].numStr;
	uppercaseChar = *s;

	/* convert to ascii */
	asciiVal = (int)uppercaseChar;

	return (asciiVal);
}
/**
 * print_base_16 - prints a positive integer in base 16 notation
 * @num: a positive integer
 *
 * Return: returns the number of characters printed to standard output
 */
int print_base_16(unsigned int num)
{
	/* declare variables */
	int r_value, uppercaseAscii;

	/* initialize variables */
	r_value = 0;
	uppercaseAscii = 0;

	/* print base 16 notation */
	uppercaseAscii = convert_to_hex(num);
	r_value += _putchar(uppercaseAscii);

	return (r_value);
}
/**
 * print_number - function that prints a positive integer in a base notation
 * @digit: a positive integer
 * @base: the base notation in which digit should be printed
 *
 * Return: returns the number of characters printed to standard output
 */
int print_number(unsigned int digit, unsigned int base)
{
	/* declare variables */
	unsigned int exponent, count, num, number;
	int r_value;

	/* initialize variables */
	count = 0;
	exponent = 1;
	r_value = 0;
	num = digit;

	/* get the count of base in digit */
	while (digit > 0)
	{
		digit = digit / base;
		count++;
	}

	/* calculate its exponent */
	while (count > 1)
	{
		exponent = exponent * base;
		count--;
	}

	/* print the integer */
	while (exponent > 0)
	{
		number = num / exponent;
		if ((number >= 10 && number < 16) && base > 10)
			r_value += print_base_16(number);
		else
			r_value += _putchar(number + '0');

		num = num - (number * exponent);
		exponent /= base;
	}

	return (r_value);
}
