#include "main.h"
#include <stdarg.h>
/**
 * handle_char - handle %c specifier
 * @args: va_list of arguments
 * @count: pointer to character count
 * Return: void
 */
void handle_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	_putchar(c);
	(*count)++;
}

/**
 * handle_string - handle %s specifier
 * @args: va_list of arguments
 * @count: pointer to character count
 * Return: void
 */
void handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
	str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		(*count)++;
		i++;
	}
}

/**
 * handle_percent - handle %% specifier
 * @count: pointer to character count
 * Return: void
 */
void handle_percent(int *count)
{
	_putchar('%');
	(*count)++;
}

/**
 * handle_unknown - handle unknown specifiers
 * @format: format specifier
 * @count: pointer to character count
 * Return: void
 */
void handle_unknown(const char *format, int *count)
{
	_putchar('%');
	(*count)++;
	_putchar(*format);
	(*count)++;
}

/**
 * handle_decimal - handle %d and %i specifiers
 * @args: va_list of arguments
 * @count: pointer to character
 * Return: print decimals
 */
void handle_decimal(va_list args, int *count)
{
	int num = va_arg(args, int);
	int num_digits = 0, index, i;
	int temp_num;
	char digits[12];

	if (num == 0)
	{
		_putchar('0');
		(*count)++;
		return;
	}
	if (num < 0)
	{
		_putchar('-');
		temp_num = -num;
	}
	while (temp_num != 0)
	{
		temp_num /= 10;
		num_digits++;
	}
	index = num_digits - 1;
	temp_num = num < 0 ? -num : num;
	do {
	digits[index] = temp_num % 10 + '0';
	temp_num /= 10;
	index--;
	} while (temp_num != 0);
	for (i = 0; i < num_digits; i++)
	{
	_putchar(digits[i]);
	(*count)++;
	}
}

/**
 * _printf - handle %d and %i specifiers
 * @format: va_list of arguments
 * Return: print decimals
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
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			break;
			if (*format == ' ')
			return (-1);

			if (*format == 'c')
			handle_char(args, &count);
			else if (*format == 's')
			handle_string(args, &count);
			else if (*format == '%')
			handle_percent(&count);
			else if (*format == 'd' || *format == 'i')
			handle_decimal(args, &count);
			else
			handle_unknown(format, &count);
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
