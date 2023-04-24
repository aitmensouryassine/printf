#include "main.h"

/**
 * print_string - print a string
 * @list: the optional arguments passed to printf
 * Return: the length of the printed string without '/0', or -1
 * on failure
 */
int print_string(va_list list)
{
	int len = 0;
	char *str = va_arg(list, char *);

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	return (write(1, str, len));
}
