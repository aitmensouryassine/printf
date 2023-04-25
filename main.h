#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define ARR_LEN 50

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
int handle_print(const char *, int *idx, va_list);
int print_string(va_list);
int print_char(va_list);
int print_percent(void);
int print_int(va_list);
int print_binary(va_list);
int print_unsigned(va_list);
int print_octal(va_list);
int print_hexadecimal(va_list);
int print_upper_hexa(va_list);

#endif
