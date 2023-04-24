#include "main.h"

/**
 * print_binary - convets int to binary and prints it
 * @list: optional args passed to _printf
 * Return: the number of chars printed
 */

int print_binary(va_list list)
{
	unsigned int n, m, i, s;
	unsigned int b[32];
	int l;
	char c;

	n = va_arg(list, unsigned int);
	m = 2147483648;
	b[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		b[i] = (n / m) % 2;
	}
	for (i = 0, s = 0, l = 0; i < 32; i++)
	{
		s += b[i];
		if (s || i == 31)
		{
			c = '0' + b[i];
			write(1, &c, 1);
			l++;
		}
	}
	return (l);
}
