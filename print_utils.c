#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * print_char -prints the character c to stdout
 * @arg: argument
 *
 * Return: On success 1, otherwise error
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_int - prints an integer.
 * @arg: argument
 * Return: 0
 */

int print_int(va_list arg)
{

unsigned int divisor = 1, i, result, printChar = 0;
int n = va_arg(arg, int);

if (n < 0)
{
	_putchar('-');
	printChar++;
	n *= -1;
}

for (i = 0; n / divisor > 9; i++, divisor *= 10)
;

for (; divisor >= 1; n %= divisor, divisor /= 10, printChar++)
{
	result = n / divisor;
	_putchar('0' + result);
}
return (printChar);
}



/**
 * print_STR - prints a string with a `S` specificer with upper case.
 * @arg: argument
 * Return: number of character printed
 */

int print_STR(va_list arg)
{
int i;
char *str = va_arg(arg, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
{
	if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
	{
		_putchar('\\');
		_putchar('x');
		if (i < 16)
			_putchar('0');

		print_unsignedIntToHex(str[i], 'A');
	}
	else
		_putchar(str[i]);
}

return (i);
}

/**
 * print_str - prints a string with a `s` specifier with lower case.
 * @arg: argument
 * Return: number of character printed
 */

int print_str(va_list arg)
{
int i;
char *str = va_arg(arg, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
	_putchar(str[i]);

return (i);
}

/**
 * print_unsignedInt - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */

int print_unsignedInt(va_list arg)
{
int divisor = 1, i, result;
unsigned int n = va_arg(arg, unsigned int);

for (i = 0; n / divisor > 9; i++, divisor *= 10)
;

for (; divisor >= 1; n %= divisor, divisor /= 10)
{
	result = n / divisor;
	_putchar('0' + result);
}
return (i + 1);
}
