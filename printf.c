#include "main.h"

int handle_print(const char *format, int *idx, va_list list);

/**
 * _printf - produces output according to a format.
 * @format: a character sting
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int idx = 0, chars_count = 0, is_printed = 0;
	va_list list;

	va_start(list, format);

	if (!format)
		return (-1);

	while (format[idx])
	{
		if (format[idx] != '%')
		{
			chars_count += write(1, &format[idx], 1);
		}
		else
		{
			idx++;
			is_printed = handle_print(format, &idx, list);

			if (is_printed == -1)
				return (-1);
			chars_count += is_printed;
		}
		idx++;
	}

	va_end(list);
	return (chars_count);
}

/**
 * handle_print - handle print of args (%c, %s, %%, ...)
 * @format: Formatted string passed to _printf.
 * @idx: the index of a char in format.
 * @list: List of arguments to be printed.
 * Return: 1, 2 or -1;
 */
int handle_print(const char *format, int *idx, va_list list)
{
	int i, len = 0;

	specifier_t sp[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}};

	i = 0;
	while (sp[i].sym)
	{
		if (sp[i].sym == format[*idx])
			return (sp[i].f(list));
		i++;
	}

	if (!sp[i].sym)
	{
		if (format[*idx] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (format[*idx - 1] == ' ')
			len += write(1, " ", 1);
		len += write(1, &format[*idx], 1);
		return (len);
	}

	return (-1);
}
