#include "holberton.h"

/**
* countArgs - count the number of arguments
* @args: arguments
*
* Return: number of arguments
*/
int countArgs(char **args)
{
	register int index = 0;

	while (args[index])
		index++;
	return (index);
}

/**
* _atoi - change string to an integer
* @s: string.
*
* Return: an integer.
*/

int _atoi(char *s)
{
	register int i, sign;
	unsigned int num;

	i = 0;
	num = 0;
	sign = 1;
	while ((*(s + i) < '0' || *(s + i) > '9') && *(s + i))
	{
		if (*(s + i) == '-')
		{
			sign = -sign;
		}
		i++;
	}
	if (*(s + i))
	{
		while (*(s + i) >= '0' && *(s + i) <= '9')
		{
			num = num * 10 + (*(s + i) - '0');
			i++;
		}
	}
	num = sign * num;
	return (num);
}
