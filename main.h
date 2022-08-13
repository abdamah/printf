#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdarg.h>
#include <stdlib.h>


int print_strlen(char *s);
void print_puts(char *str);
int print_ptr(va_list arg);

int _putchar(char c);
int print_int(va_list arg);
int print_unsignedInt(va_list arg);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(void);
void print_binary(unsigned int n, unsigned int *printed);
int print_unsignedToBinary(va_list arg);
int print_oct(va_list arg);
int print_unsignedIntToHex(unsigned int num, char _case);
int print_hex_base(va_list arg, char _case);
int print_hex(va_list arg);
int print_HEX(va_list arg);
int print_STR(va_list arg);
int  rev_string(va_list arg);
int rot13(va_list arg);

/**
 * struct specifiers - defingin specifier struct type for print
 * * @specifier: type
 * @print: function to print
 */
typedef struct specifiers
{
char *specifier;
int (*print)(va_list);
} specifiers;

#endif

