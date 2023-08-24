#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * get_num_length - Prints the length
 * @num: The number
 * Return: length
 */
int get_num_length(int num)
{
	int length = 0;

	if (num == 0)
	return (1);


	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}
/**
 * reverse_string - Reverses a string and prints it
 * @str: The string
 * @length: The length of the string
 */
void reverse_string(char *str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * int_to_string - Converts int to string
 * @num: The number
 * @str: The string
 * Return: index
 */
int int_to_string(int num, char *str)
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
		return (1);
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
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (index);
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

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format++);
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
			count += _putchar('%');
		} else if
		(*format == 'd' || *format == 'i')
		{
			int num = va_arg(args, int);
			char str[12];
			int index = 0;

			int_to_string(num, str);
			while (str[index] != '\0')
			{
				count += _putchar(str[index++]);
			}
		} else
		{
			count += _putchar('%') + _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
