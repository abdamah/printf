#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_int(va_list arg);
int print_unsigned(va_list arg);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(void);

/**
 * struct specifiers - defining struct type of print specifiers.
 * @specifier: type
 * @printer: function to print
 */
typedef struct specifiers
{
char *specifier;
int (print)(va_list);
} specifiers;

#endif
