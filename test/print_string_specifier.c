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
	int i, r_value = 0;
    char *strn;

    strn = va_arg(arg, char*);
    if (strn == NULL)
        strn = EMPTY_STRING;

    for (i = 0; strn[i]; i++, r_value++)
    {
        _putchar(strn[i]);
    }
    return r_value;

}
