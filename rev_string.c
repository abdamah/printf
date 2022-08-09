#include "main.h"

/**
* rev_string - reverse string
* @arg: string to reverse
* Return: count of characers printed
*/
int  rev_string(va_list arg)
{
	int i, j = 0;

	char *s = va_arg(arg, char*);

	while (s[j])
		j++;

	for (i = j - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	return (j);
}

