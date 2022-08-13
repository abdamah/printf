#include "main.h"
/**
 * print_unsignedToBinary - prints an integer.
 * @arg: argument
 * Return: 0
 */
int print_unsignedToBinary(va_list arg)
{

unsigned int n = va_arg(arg, unsigned int);
unsigned int printed;

print_binary(n, &printed);

return (printed);
}


/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of octals printed
 */

int print_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j = 0, charPrinted = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}

/**
 * print_unsignedIntToHex - prints unsigned int to hexadecimal.
 * @num: number to print
 * @_case: letter `a` on the case to print it (upper or lower)
 * Return: number or char printed
 */
int print_unsignedIntToHex(unsigned int num, char _case)
{
	unsigned int num2;
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + _case;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}

/**
 * print_ptr - print_base16_upper_lower
 * @arg: va_list parameter
 * Description: This function print address pointer
 * in representation parameter for print hexadecimalimal format
 * Return: address pointer
 */

int print_ptr(va_list arg)
{
	unsigned long int decimal, buffer;
	char character[100];
	int count, n, i;

	decimal = (unsigned long int)va_arg(arg, void*);
	buffer = decimal;
	count = 1;
	i = 0;

	if (!decimal)
	{
		print_puts("(nil)");
		return (5);
	}
	while (buffer)
	{
		buffer /= 16;
		count++;
	}
	character[count + 1] = '\0';
	while (decimal > 0)
	{
		n = (decimal % 16);
		if (n >= 0 && n <= 9)
			character[count] = ((char)(n + '0'));
		else
			character[count] = ((char)(n + 'W'));
		count--;
		decimal /= 16;
	}
	character[0] = '0';
	character[1] = 'x';

	while (character[i] != '\0')
	{
		_putchar(character[i]);
		i++;
	}
	return (i);
}
