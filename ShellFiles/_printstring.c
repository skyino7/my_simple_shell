#include "main.h"

int _print(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		_putchar(*str++);
		count++;
	}

	return (count);
}
