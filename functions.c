#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
/**
 * int_print - Prints integers to output
 * @args: va_list
 * @count: Counts the number of chacr printed to output
 * Return: number
 */
int print_number(long num, int *count);
int int_print(va_list args, int *count)
{
	int num = va_arg(args, int);

	print_number(num, count);
	return (0);
}

/**
 * print_number - Prints numbers to output
 * @num: Number that is to be printed to output
 * @count: number of char printed to output
 * Return: number
 */
int print_number(long num, int *count)
{
	int *numbr, counter = 0, i;
	long n;

	if (num < 0)
	{
		_putchar('-');
		(*count)++;
		if (num == INT_MIN)
		{
			write(1, "2147483648", 10);
			(*count) += 10;
			return (-1);
		}
		num = -num;
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	n = num;
	numbr = malloc(sizeof(int) * counter);
	if (!numbr)
	{
		_putchar('0');
		return (-1);
	}
	for (i = 0; i < counter; i++)
	{
		numbr[i] = n % 10;
		n /= 10;
	}
	for (i = 1; i <= counter; i++)
	{
		_putchar(numbr[counter - 1] + '0');
		(*count)++;
	}
	free(numbr);
	return (0);
}
