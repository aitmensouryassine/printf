#include "../main.h"
#include <stdio.h>

int main(void)
{
	int len = -4587, l1, l2;

	l1 = printf("%d %i\n", len, len);
	l2 = _printf("%d %i\n", len, len);

	printf("%d %i\n", l1, l1);
	_printf("%d %i\n", l2, l2);
	return (0);
}
