#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
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
 * _printf - Prints an output according to format
 * @format: format string
 * Return: num of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
			continue;
		}

		format++;
		if (*format == '\0')
			break;

		if (*format == 'c')
			count += _putchar((char)va_arg(args, int));
		else if (*format == 's')
		{
			char *str = va_arg(args, char *);

			if (str == NULL)
				str = "(null)";
			while (*str != '\0')
				count += _putchar(*str++);
		}
		else
		{
			count += _putchar(*format);
		}
	}

	va_end(args);
	return (count);
}
