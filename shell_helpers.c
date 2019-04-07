#include "holberton.h"

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void freeArgs(char **args)
{
	register uint index = 0;

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

/**
 * displayPrompt - displays shell prompt
 */
void displayPrompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * displayNewLine - displays new line
 */
void displayNewLine(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * sigintHandler - catches SIGINT signal and reset signal
 * @sigint: signal from stdout
 */
void sigintHandler(int sigint)
{
	(void)sigint;
	signal(SIGINT, sigintHandler);
	displayNewLine();
	displayPrompt();
	fflush(stdout);
}
