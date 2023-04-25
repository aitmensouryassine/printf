#include "main.h"

int print_hexa(char *, unsigned long int, char *);

/**
 * print_unsigned - prints an unsigned number
 * @list: list of optional args passed to _printf
 * Return: number of printed chars
 */
int print_unsigned(va_list list)
{
	char arr[ARR_LEN];
	int i = ARR_LEN - 1;
	unsigned long int n = va_arg(list, unsigned long int);

	arr[i--] = '\0';

	if (n == 0)
		arr[i--] = '0';

	while (n > 0)
	{
		arr[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;

	return (write(1, &arr[i], ARR_LEN - i - 1));
}

/**
 * print_octal - prtins an unsigned number in octal
 * @list: list of optional args passed to _printf
 * Return: number of printed chars
 */
int print_octal(va_list list)
{
	char arr[ARR_LEN];
	int i = ARR_LEN - 1;
	unsigned long int n = va_arg(list, unsigned long int);

	arr[i--] = '\0';

	if (n == 0)
		arr[i--] = '0';

	while (n > 0)
	{
		arr[i--] = (n % 8) + '0';
		n /= 8;
	}
	i++;

	return (write(1, &arr[i], ARR_LEN - i - 1));
}

/**
 * print_hexadecimal - prints an unsigned number in hexadecimal
 * @list: list of optional args passed to _printf
 * Return: number of printed chars
 */
int print_hexadecimal(va_list list)
{
	char arr[ARR_LEN];
	unsigned long int number = va_arg(list, unsigned long int);

	return (print_hexa("0123456789abcdef", number, arr));
}

/**
 * print_upper_hexa - prints an unsigned number in upper hexadecimal
 * @list: list of optional args passed to _printf
 * Return: number of printed chars
 */
int print_upper_hexa(va_list list)
{
	char arr[ARR_LEN];
	unsigned long int number = va_arg(list, unsigned long int);

	return (print_hexa("0123456789ABCDEF", number, arr));
}

/* HELPER FUNTIONS */
/**
 * print_hexa - prints an unsigned number in hexadecimal
 * lower or upper (x or X)
 *
 * @map: array to which to map the @number
 * @number: the unsigned number to print
 * @arr: an array of chars
 * Return: number of printed chars
 */
int print_hexa(char *map, unsigned long int number, char arr[])
{
	int i = ARR_LEN - 1;

	if (number == 0)
		arr[i--] = '0';

	while (number > 0)
	{
		arr[i--] = map[number % 16];
		number /= 16;
	}
	i++;

	return (write(1, &arr[i], ARR_LEN - i));
}
