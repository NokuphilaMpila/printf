#include "main.h"
#include <stdarg.h>
/**
 * print_integer - Prints an int
 * @args: va_list of arguments
 * Return: prints integers
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	int num_digits = 0;
	int temp_num = num;
	char buffer[12];
	int index = 0;
	int i;

	if (num < 0)
	{
	_putchar('-');
	count++;
	num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		return (count + 1);
	}
	while (temp_num != 0)
	{
		buffer[index++] = temp_num % 10 + '0';
		temp_num /= 10;
		num_digits++;
	}
	for (i = num_digits - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
		count++;
	}
	return (count);
}

