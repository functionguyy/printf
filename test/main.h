#ifndef MAIN_H
#define MAIN_H

/* C standard library header files */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define EMPTY_STRING "(null)"

/* function prototypes */
int _putchar(char c);
int _printf(const char * const format, ...);
int (*find_format_handlers(const char *format))(va_list arg);
int print_spec_c_match(va_list arg);
int print_spec_d_match(va_list arg);
int print_spec_s_match(va_list arg);


typedef struct {
    const char *format_char;
    int (*handler_func)(va_list);

} format_handler;

#endif /* MAIN_H */
