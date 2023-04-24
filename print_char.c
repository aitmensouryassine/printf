#include "main.h"

/**
 * print_char - print a single character
 * @list: the optional arguments passed to printf
 * Return: 1 on success, -1 on failure
 */
int print_char(va_list list)
{
	char c = va_arg(list, int);

	return (write(1, &c, 1));
}
