#include "main.h"

/**
 * print_str_rev - reverse and print a string
 * @list: list of args passed to _printf
 * Return: number of printed chars
 */
int print_str_rev(va_list list, char buffer[])
{
	int i = BUFFER_SIZE - 1;
	char *str = va_arg(list, char *);

	if(!str)
		str = "(null)";

	buffer[i--] = '\0';
	while(*str)
	{
		buffer[i--] = *str;
		str++;
	}
	i++;

	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}
