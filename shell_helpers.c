#include "holberton.h"

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void freeArgs(char **args)
{
	register int i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
}

/**
 * insertNullByte - inserts null byte at given index
 * @str: input string
 * @index: index to insert null byte
 */
void insertNullByte(char *str, unsigned int index)
{
	*(str + index) = '\0';
}


