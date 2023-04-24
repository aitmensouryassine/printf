#include "main.h"

/**
 * print_percent - print % character
 * Return: 1 on success, -1 on failure
 */

int print_percent(void)
{
	return (write(1, "%%", 1));
}
