#include "main.h"

/**
 * print_int - print an integer
 * @list: the optional args list (was passed to _printf)
 * Return: the number of printed characters
 */
int print_int(va_list list)
{
	char arr[ARR_LEN];
	int i = ARR_LEN - 1;
	int n = va_arg(list, int);
	int minus = 0;

	arr[i] = '\0';
	i--;

	if (n == 0)
		arr[i--] = '0';

	if (n < 0)
	{
		n = -n;
		minus = '-';
	}

	while (n > 0)
	{
		arr[i--] = (n % 10) + '0';
		n /= 10;
	}

	if (minus)
		write(1, &minus, 1);

	return ((minus && 1) + write(1, &arr[i + 1], ARR_LEN - i - 2));
}
