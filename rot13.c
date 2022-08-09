#include "main.h"
/**
 * rot13 - encode srting into rot13
 * @arg: string to encode
 * Return: (point)
 */
int rot13(va_list arg)
{	int i = 0, j, count = 0, flag = 0;
	char *point = va_arg(arg, char *);
	char lett[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
'H', 'I', 'J', 'K', 'L', 'M', 'N',
'O', 'P', 'Q', 'R', 'S', 'T', 'U',
'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
'c', 'd', 'e', 'f', 'g', 'h', 'i',
'j', 'k', 'l', 'm', 'n', 'o', 'p',
'q', 'r', 's', 't', 'u', 'v', 'w',
'x', 'y', 'z'};
	char rot[] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z', 'A',
'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'n', 'o', 'p',
'q', 'r', 's', 't', 'u', 'v', 'w',
'x', 'y', 'z', 'a', 'b', 'c', 'd',
'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm'};
	if (!point)
	{
		point = "(null)";
	}
	while (point[i])
	{
		for (j = 0; j < 52; j++)
		{
			if (point[i] == lett[j])
			{
				_putchar(rot[j]);
				count++;
				flag = 1;
				break;
			}
		}
		if (!flag)
			_putchar(point[i]);
		flag = 0;
		i++;
	}
	return (count);
}
