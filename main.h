#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define UNUSED_VARIABLE(X) (void)(X)

/**
 * struct specifier - a struct for conversion specifiers
 * @sym: first member (i.e. %c, %s, %d)
 * @f: second member (a pointer function to handle print)
 */

typedef struct specifier
{
	char sym;
	int (*f)();
} specifier_t;

int _printf(const char *format, ...);
int print_string(va_list);
int print_char(va_list, char[]);
int print_percent(void);
int print_int(va_list, char[]);
int print_binary(va_list);
int print_unsigned(va_list, char[]);
int print_octal(va_list, char[]);
int print_hexadecimal(va_list, char[]);
int print_upper_hexa(va_list, char[]);
int print_non_printable(va_list, char[]);
int print_pointer(va_list, char[]);
int print_str_rev(va_list, char[]);

#endif
