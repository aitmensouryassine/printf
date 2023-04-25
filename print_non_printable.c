#include "main.h"

/**
 * print_non_printable - prints non printable chars in "\x" followed by
 * the chars ascii code in hexadeciaml upper cased and always in 2 chars long
 * @list: lsit of optional args passed to _printf
 * @buffer: the buffer
 * Return: number of printed chars
 */
int print_non_printable(va_list list, char buffer[])
{
	int i, j, hex_len = 2, offset = 0;
	char map[] = "0123456789ABCDEF";
	char *str = va_arg(list, char *);
	char tmp;

	if (!str)
		return (write(1, "(null)", 6));

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			buffer[i + offset] = str[i];
		}
		else
		{
			tmp = str[i];
			if (tmp < 0)
				tmp = (-1) * tmp;

			j = i + offset;
			buffer[j++] = '\\';
			buffer[j++] = 'x';
			buffer[j++] = map[tmp / 16];
			buffer[j] = map[tmp % 16];

			offset += hex_len + 1;
		}
	}
	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
