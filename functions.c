#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_integer - Prints an int
 * @args: va_list of arguments
 * Return: prints integers
 */
int print_integer(va_list args)
{
	int i = 0
	int num = va_arg(args, int);
	int count = 0;
	int num_digits = 0;
	int temp_num = num;
	char buffer[12];
	int index = 0

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
	temp_num = num;
	do {
		temp_num /= 10;
		index--;
	} while (temp_num != 0);
	for (i = 0; i < num_digits; i++)
	{
		count += _putchar(buffer[i]);
	}
	return (count);
}
/**
 * _printf - Prints an output according to format specifiers %d and %i
 * @format: format specifier
 * Return: num of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
	return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format++);
			continue;
		}
		format++;
		if (*format == '%')
		{
			count += _putchar('%');
		}
		else if (*format == 'd' || *format == 'i')
		{
			count += print_integer(args);
		}
		else
		{
			count += _putchar('%') + _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
