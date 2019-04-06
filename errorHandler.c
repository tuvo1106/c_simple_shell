#include "holberton.h"

void errorHandler(char *f, int n, char *cmd)
{
	static char error[100];
	int len;
	char *alpha;

	alpha = itoa(n);
	len = strlen(f) + strlen(alpha) + strlen(cmd) + 2 + 2 + 12;
	strcat(error, f);
	strcat(error, ": ");
	strcat(error, alpha);
	strcat(error, ": ");
	strcat(error, cmd);
	strcat(error, ": not found\n");
	error[len] = 0;
	write(1, error, len);
	free(alpha);
}

unsigned int countDigits(int num)
{
	int digits = 0;

	while (num > 0)
	{
		digits++;
		num /= 10;
	}

	return (digits);
}


char *itoa(unsigned int num)
{
	char *str;
	int digits = 0;

	digits += countDigits(num);
	str = malloc(sizeof(char) * (digits + 1));

	str[digits] = '\0';

	while (num > 0)
	{
		str[digits - 1] = num % 10 + '0';
		num = num / 10;
		digits--;
	}

	return (str);
}
