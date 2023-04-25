#include "main.h"

int write_char(char, char []);

/**
 * print_char - print a single character
 * @list: the optional arguments passed to printf
 * @buffer: the buffer
 * Return: 1 on success, -1 on failure
 */
int print_char(va_list list, char buffer[])
{
	char c = va_arg(list, int);

	return (write_char(c, buffer));
}

/**
 * write_char - prints a char
 * @c: the character
 * @buffer: the buffer
 * Return: number of printed chars
 */
int write_char(char c, char buffer[])
{
	int idx = 0;

	buffer[idx] = c;
	buffer[++idx] = '\0';

	return (write(1, &buffer[0], 1));
}
