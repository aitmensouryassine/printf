#include "main.h"

/**
 * print_rot13 - encodes a string using ROT13 and prints it
 * @list: list of args passed to _printf
 * @buffer: the buffer
 * Return: the number of printed chars
 */
int print_rot13(va_list list)
{
	int len, i, j;
	char *str = va_arg(list, char *);
	char rot[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ebg[53] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char tmp;

	if(!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; rot[j]; j++)
			if (str[i] == rot[j])
			{
				tmp = ebg[j];
				write(1, &tmp, 1);
				len++;
				break;
			}
		if (!rot[j])
		{
			tmp = str[i];
			write(1, &tmp, 1);
			len++;
		}
	}

	return (len);
}
