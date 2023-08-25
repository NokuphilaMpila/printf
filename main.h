#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int integer_printf(const char *format, ...);
int get_num_length(int num);
void reverse_string(char *str, int length);
void int_to_string(int num, char *str);
void handle_decimal(va_list args, int *count);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_unknown(const char *format, int *count);
int print_number(long num, int *count);

#endif
