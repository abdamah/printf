#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * printSpecifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the indentifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int printSpecifiers(char next, va_list arg)
{
	int index;

	specifiers utils[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsignedInt},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{"p", print_ptr},
		{"r", rev_string},
		{"R", rot13},
		{NULL, NULL}
	};

	for (index = 0; utils[index].specifier != NULL; index++)
	{
		if (utils[index].specifier[0] == next)
			return (utils[index].print(arg));
	}
	return (0);
}

/**
 * _printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters that were printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int printSpecifier = 0, printChar = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printChar++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			printChar++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		printSpecifier = printSpecifiers(format[i + 1], arg);
		if (printSpecifier == -1 || printSpecifier != 0)
			i++;
		if (printSpecifier > 0)
			printChar += printSpecifier;

		if (printSpecifier == 0)
		{
			_putchar('%');
			printChar++;
		}
	}
	va_end(arg);
	return (printChar);
}
