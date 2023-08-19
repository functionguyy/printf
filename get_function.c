#include "main.h"

/**
 * find_format_handlers- function is responsible for identifying formats
 *                        intended for use with _printf.
 *          It then calls the appropriate corresponding function based on
 *          the identified format.
 * @format: The format specifier (char, string, int, decimal, etc)
 * Return: Either NULL or the associated function pointer.
 */
int (*find_format_handlers(const char *format))(va_list arg)
{
	unsigned int i;

	i = 0;

	format_handler find_func[] = {
		{"c", print_char}
	};

	while (find_func[i].format_char)
	{
		if (format[i] == find_func[i].format_char[0])
		return (find_func[i].handler_func);
		i++;
	}

	return (NULL);
}
