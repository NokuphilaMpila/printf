#include "main.h"
#include <stdarg.h>
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
		}
		else if (*format == 'd' || *format == 'i')
		{
			int num = va_arg(args, int);
			count += printf("%d" , num);
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

/**
 * main - function that prints integers
 * Return: 0
 */
int main() {

		int num1 = 123;
		int num2 = -456;
		int count;

		count = integer_printf("This is a test\n");
		printf("Number of characters printed: %d\n", count);
		count = integer_printf("The numbers are: %d and %i\n", num1, num2);
		printf("Number of characters printed: %d\n", count);
		return 0;
}
