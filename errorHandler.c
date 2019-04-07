#include "holberton.h"

/**
 * errorHandler - prints error message for shell()
 * @filename: filename of shell
 * @num: nth command entered into shell
 * @cmd: command that could not be executed
 */
void errorHandler(char *filename, int num, char *cmd)
{
	register int len;
	static char error[BUFSIZE];
	char *alpha;

	alpha = itoa(num);
	len = _strlen(filename) + _strlen(alpha) + _strlen(cmd) + 2 + 2 + 12;
	strcat(error, filename);
	strcat(error, ": ");
	strcat(error, alpha);
	strcat(error, ": ");
	strcat(error, cmd);
	strcat(error, ": not found\n");
	insertNullByte(error, len);
	write(STDOUT_FILENO, error, len);
	free(alpha);
}

/**
 * countDigits - count number of digits in a number
 * @num: input number
 * Return: number of digits
 */
unsigned int countDigits(int num)
{
	register int digits = 0;

	while (num > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * itoa - converts integer to string
 * @num: input integer
 * Return: string type of number
 */
char *itoa(unsigned int num)
{
	register int digits = 0;
	char *str;

	digits += countDigits(num);
	str = malloc(sizeof(char) * (digits + 1));
	insertNullByte(str, digits);
	while (num > 0)
	{
		str[digits - 1] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	return (str);
}
