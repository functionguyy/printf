#ifndef MAIN_H
#define MAIN_H

/* C standard library header files */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define BUF_CAPACITY 1024
#define BUF_CLEARING -1

#define EMPTY_STRING "(null)"

/* function prototypes */
int _putchar(int c);
int (*find_format_handlers(const char *format))(va_list arg);
int print_spec_c_match(va_list arg);
int print_spec_d_match(va_list arg);
int print_spec_s_match(va_list arg);
int print_percent(va_list arg);

/* libraries 1*/
int execute_func(char *s, va_list arg);
int produce_range(char *start, char *stop);
int _printf(const char *format, ...);



/**
 * struct format_handler - Struct token
 * @format_char: the format token
 * @handler_func: The function associated
 */
typedef struct format_handler
{
	char *format_char;
	int (*handler_func)(va_list);

} format_handler;

#endif /* MAIN_H */
