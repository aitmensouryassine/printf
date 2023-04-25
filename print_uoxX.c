#include "main.h"

int print_hexa(char *, unsigned long int, char *);

/**
 * print_unsigned - prints an unsigned number
 * @list: list of optional args passed to _printf
 * @buffer: the buffer
 * Return: number of printed chars
 */
int print_unsigned(va_list list, char buffer[])
{
	int i = BUFFER_SIZE - 1;
	unsigned long int n = va_arg(list, unsigned long int);

	buffer[i--] = '\0';

	if (n == 0)
		buffer[i--] = '0';

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;

	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}

/**
 * print_octal - prtins an unsigned number in octal
 * @list: list of optional args passed to _printf
 * @buffer: the buffer
 * Return: number of printed chars
 */
int print_octal(va_list list, char buffer[])
{
	int i = BUFFER_SIZE - 1;
	unsigned long int n = va_arg(list, unsigned long int);

	buffer[i--] = '\0';

	if (n == 0)
		buffer[i--] = '0';

	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	i++;

	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}

/**
 * print_hexadecimal - prints an unsigned number in hexadecimal
 * @list: list of optional args passed to _printf
 * @buffer: the buffer
 * Return: number of printed chars
 */
int print_hexadecimal(va_list list, char buffer[])
{
	unsigned long int number = va_arg(list, unsigned long int);

	return (print_hexa("0123456789abcdef", number, buffer));
}

/**
 * print_upper_hexa - prints an unsigned number in upper hexadecimal
 * @list: list of optional args passed to _printf
 * @buffer: the buffer
 * Return: number of printed chars
 */
int print_upper_hexa(va_list list, char buffer[])
{
	unsigned long int number = va_arg(list, unsigned long int);

	return (print_hexa("0123456789ABCDEF", number, buffer));
}

/* HELPER FUNTIONS */
/**
 * print_hexa - prints an unsigned number in hexadecimal
 * lower or upper (x or X)
 *
 * @map: array to which to map the @number
 * @number: the unsigned number to print
 * @buffer: the buffer (an array of chars)
 * Return: number of printed chars
 */
int print_hexa(char *map, unsigned long int number, char buffer[])
{
	int i = BUFFER_SIZE - 1;

	if (number == 0)
		buffer[i--] = '0';

	while (number > 0)
	{
		buffer[i--] = map[number % 16];
		number /= 16;
	}
	i++;

	return (write(1, &buffer[i], BUFFER_SIZE - i));
}
