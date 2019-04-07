#include "holberton.h"

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void freeArgs(char **args)
{
	register unsigned int index = 0;

	while (args[index])
		free(args[index++]);
	free(args);
}

/**
 * insertNullByte - inserts null byte at given index
 * @str: input string
 * @index: index to insert null byte
 */
void insertNullByte(char *str, unsigned int index)
{
	str[index] = '\0';
}

void displayPrompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
