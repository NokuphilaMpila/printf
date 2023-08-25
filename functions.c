#include "main.h"
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_char(va_list args)
{
	char c = (char) va_arg(args, int);
	return (_putchar(c));
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		count += _putchar(*str++);
	}

	return (count);

}
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	int num_length = 0;
	int temp = num;
	int divisor, digit;

	if (num == 0)
	{
		count += _putchar('0');
		return (1);
	}

	if (num < 0)
	{
		count += _putchar('-');
		num *= -1;
	}

	temp = num;
	while (temp != 0)
	{
		temp /= 10;
		num_length++;
	}

	temp = num;
	{
		int i;
		for (i = 1; i < num_length; i++)
		{
			divisor = 10 * divisor;
		}
		
		while (num_length > 0)
		{
			digit = temp / divisor;
			count += _putchar(digit + '0');
			temp = temp % divisor;
			num_length--;
			divisor = divisor / 10;
		}
	}
	
	return (count);
}

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

		if (*format == '\0')
		{
			va_end(args);
			return (-1);
		}

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
		else if (*format == 'd' || *format == 'i')
		{
			count += print_int(args);
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
