#include "main.h"
/**
 *print_strlen - print length of the string
 *@s: pointer char
 *Return: int length
 */
int print_strlen(char *s)
{
	int len = 0;

	while (*s++)
	{
		len++;
	}
	return (len);
}
/**
 *print_puts - print string
 *Description: print some string
 *@str: pointer char
 *Return: Nothing
 */
void print_puts(char *str)
{
	int i;

	for (i = 0; i < print_strlen(str); i++)
	{
		_putchar(str[i]);
	}
}


