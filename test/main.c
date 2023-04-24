#include "../main.h"
#include <stdio.h>

int main(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[% %%s]\n", "I am a string !", NULL);
	printf("String:[% %%s]\n", "I am a string !", NULL);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");

	printf("%d %d\n", len, len2);
	return (0);
}
