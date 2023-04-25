#include "main.h"

int handle_print(const char *, int *idx, va_list, char []);

/**
 * write_buffer - writes the buffer to std output
 * @buffer: the buffer
 * @buffer_length: the buffer length
 */
void write_buffer(char buffer[], int *buffer_length)
{
	if (*buffer_length >= 1)
		write(1, &buffer[0], *buffer_length);
	*buffer_length = 0;
}


/**
 * _printf - produces output according to a format.
 * @format: a character sting
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int idx = 0, chars_count = 0, is_printed = 0;
	va_list list;
	char local_buffer[BUFFER_SIZE];
	int buffer_idx = 0;

	va_start(list, format);

	if (!format)
		return (-1);

	while (format && format[idx])
	{
		if (format[idx] != '%')
		{
			local_buffer[buffer_idx] = format[idx];
			buffer_idx++;

			if (buffer_idx == BUFFER_SIZE)
				write_buffer(local_buffer, &buffer_idx);

			chars_count += 1;
		}
		else
		{
			write_buffer(local_buffer, &buffer_idx);
			idx++;
			is_printed = handle_print(format, &idx, list, local_buffer);

			if (is_printed == -1)
				return (-1);
			chars_count += is_printed;
		}
		idx++;
	}
	write_buffer(local_buffer, &buffer_idx);
	va_end(list);
	return (chars_count);
}

/**
 * handle_print - handle print of args (%c, %s, %%, ...)
 * @format: Formatted string passed to _printf.
 * @idx: the index of a char in format.
 * @list: List of arguments to be printed.
 * @buffer: the buffer (array of chars)
 * Return: 1, 2 or -1;
 */
int handle_print(const char *format, int *idx, va_list list, char buffer[])
{
	int i, len = 0;

	specifier_t sp[] = {
		{'c', print_char}, {'s', print_string},	{'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'X', print_upper_hexa},
		{'x', print_hexadecimal}, {'o', print_octal},
		{'S', print_non_printable}, {'p', print_pointer}, {'\0', NULL}};

	i = 0;
	while (sp[i].sym)
	{
		if (sp[i].sym == format[*idx])
			return (sp[i].f(list, buffer));
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
