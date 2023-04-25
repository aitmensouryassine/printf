#include "main.h"

/**
 * print_pointer - Prints the value of a pointer
 * @list: List a of arguments passed to _printf
 * @buffer: the buffer
 * Return: the number of printed chars.
 */
int print_pointer(va_list list, char buffer[])
{
	int i = BUFFER_SIZE - 1;
	void *addrs = va_arg(list, void *);
	unsigned long addrs_val;
	char map[] = "0123456789abcdef";

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[i] = '\0';
	i--;

	addrs_val = (unsigned long)addrs;

	while (addrs_val > 0)
	{
		buffer[i--] = map[addrs_val % 16];
		addrs_val /= 16;
	}
	buffer[i--] = 'x';
	buffer[i--] = '0';
	i++;

	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}
