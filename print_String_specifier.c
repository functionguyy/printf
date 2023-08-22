#include "main.h"

/**
 * convert - a given decimal number to a string rep in the specified base.
 *
 * Description - This function takes a decimal number and a base, and converts
 *	the number into a string representation using the provided base.
 *	The result is stored in a buffer and returned as a pointer to the
 *	beginning of the string.
 *
 * @num: The decimal number to be converted.
 * @base: The base for conversion (e.g., 2 for binary, 16 for hexadecimal).
 * Return: A pointer to the string representation of the converted number.
 */
char *convert_to(long int num, int base)
{
	char *arr;
	char buf[20];
	char *ptr;
	unsigned long n = num;

	arr = "0123456789ABCDEF";

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';

	for (; n != 0; n /= base)
		*(--ptr) = arr[n % base];

	return (ptr);
}

/**
 * _puts - a string of characters and returns the number of characters printed
 *
 * This function takes a ptr to a null-terminated string and outputs each
 * char to the standard output using the _putchar function. It then returns
 * the total number of characters printed.
 *
 * @str: Pointer to the null-terminated string to be printed.
 * Return: The number of characters successfully printed.
 */
int _puts(char *str)
{
	char *start;

	start = str;

	while (*str)
		_putchar(*str++);

	return (str - start);
}

/**
 * print_spec_S_match -  a string, with non-printable characters represented as
 *			escape sequences.
 *
 * This function takes a var argument list (va_list) and retrieves a pointer
 * to a null-terminated string from it. It then iterates through each character
 * of the str and prints it to the std output using the _putchar function.
 * Non-printable chars (ASCII < 32 and >= 127) are rep as escape sequences
 * in the format "\xHH", where HH is the hexadecimal value of the character.
 *
 * @arg: The variable argument list containing a pointer to the string.
 * Return: The total number of characters printed.
 */
int print_spec_S_match(va_list arg)
{
	char *str, *hex_format;
	int r_value;

	str = va_arg(arg, char *);
	r_value = 0;

	if ((int)(!str))
		return (_puts(EMPTY_STRING));
	for (; *str; str++)
	{
		if (*str >= 127 || (*str > 0 && *str < 32))
		{
			r_value += _putchar('\\');
			r_value += _putchar('x');
			hex_format = convert_to(*str, 16);
			if (!hex_format[1])
				r_value += _putchar('0');
			r_value += _puts(hex_format);
		}
		else
		{
			r_value += _putchar(*str);
		}
	}
	return (r_value);
}
