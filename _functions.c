#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_integer - Prints an integer
 * @args: Integer type
 * Return: 0
 */
int print_integer(va_list args)
{
	int i = va_arg(args, int);
	char *str = malloc(12);

	int_to_string(i, str);
	if (!str)
	return (-1);

	write(1, str, strlen(str));
	free(str);
	return (0);
}


/**
 * int_to_string - Converts int to string
 * @num: The number
 * @str: The string
 * Return: index
 */
void int_to_string(int num, char *str)
{
	int is_negative = 0;
	int index = 0;
	int start = 0;
	int digit = num % 10;
	int end = index - 1;
	char temp = str[start];

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num != 0)
	{
		str[index++] = '0' + digit;
		num /= 10;
	}
	if (is_negative)
	str[index++] = '-';
	str[index] = '\0';
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

}

/**
 * integer_printf - Prints an output according to format
 * @format: format specifier
 * Return: Number of chars printed
 */
int integer_printf(const char *format, ...)
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
			write(1, format++, 1);
			count++;
			continue;
		}
		format++;
		if (*format == '\0')
		{
			va_end(args);
			return (-1);
		}
		if (*format == '%')
		{
			write(1, "%", 1);
			count++;
		}
		else if (*format == 'd' || *format == 'i')
		{

			count += print_integer(args);
		}
		else
		{
			write(1, "%", 1);
			write(1, format, 1);
			count += 2;
		}
		format++;
	}
	va_end(args);
	return (count);
}
