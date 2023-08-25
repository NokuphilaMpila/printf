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
