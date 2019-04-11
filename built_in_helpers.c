#include "holberton.h"

/**
* countArgs - count the number of arguments
* @args: input array of strings
* Return: number of strings
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
* @s: input string
* Return: type integer
*/
int _atoi(char *s)
{
	register int i;
	unsigned int num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num *= 10 + s[i] - '0';
		else
			return (-1);
		i++;
	}
	if (num > 2147483647)
		return (-1);
	return (num);
}
