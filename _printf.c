#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - Prints a char
 * @c: The character to be printed
 * Return: Number of chars printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints a char
 * @args: Converts int to char
 * Return: Number of chars printed
 */
int print_char(va_list args)
{
	char c = (char) va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - Prints an output string
 * @args: Converts int to char
 * Return: num of bytes printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
	{
		count += _printf("(null)");
		count += 6;
	}
	else
	{
		while (*str)
		{
			count += _putchar(*str++);
		}
	}
	return (count);
}

/**
 * _printf - Prints an output according to format
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
		else if (*format == 'c')
		{
			count += print_char(args);
		}
		else if (*format == 's')
		{
			count += print_string(args);
		}
		else
		{
			count += _putchar('%') +  _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
