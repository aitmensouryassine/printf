#include "../main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
	_printf("_Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("_Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("_Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	return (0);
}
