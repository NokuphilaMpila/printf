#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int integer_printf(const char *format, ...);
int get_num_length(int num);
void reverse_string(char *str, int length);
int int_to_string(int num, char *str);


#endif
