#include "main.h"

/**
 * print_int - print an integer
 * @list: the optional args list (was passed to _printf)
 * @buffer: the buffer
 * Return: the number of printed characters
 */
int print_int(va_list list, char buffer[])
{
	int i = BUFFER_SIZE - 1;
	int n = va_arg(list, int);
	int minus = 0;

	buffer[i] = '\0';
	i--;

	if (n == 0)
		buffer[i--] = '0';

	if (n < 0)
	{
		n = -n;
		minus = '-';
	}

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	if (minus)
		write(1, &minus, 1);

	return ((minus && 1) + write(1, &buffer[i], BUFFER_SIZE - i - 1));
}
