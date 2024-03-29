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
	format_handler find_func[] = {
		{"c", print_spec_c_match},
		{"d", print_spec_d_match},
		{"i", print_spec_d_match},
		{"s", print_spec_s_match},
		{"%", print_percent},
		{"S", print_spec_S_match},
		{"b", print_spec_b_match},
		{"X", print_spec_X_match},
		{"o", print_spec_o_match},
		{"u", print_spec_u_match},
		{"x", print_spec_x_match},
		{NULL, NULL}
	};

	unsigned int i;

	i = 0;

	while (find_func[i].format_char)
	{
		if (format[0] == find_func[i].format_char[0])
		return (find_func[i].handler_func);
		i++;
	}

	return (NULL);
}
