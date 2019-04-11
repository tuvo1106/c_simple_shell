#include "holberton.h"

/**
 * checkPath - searches $PATH for directory of command
 * @input: input command
 * @path: input $PATH
 * Return: string of full pathname if found, NULL if not
 */
char *checkPath(char *input, char *path)
{
	register int len;
	static char buffer[BUFSIZE];
	char *tok, *copy, *delim = ":";
	struct stat st;

	copy = _strdup(path);
	tok = _strtok(copy, delim);
	if (copy && *copy == ':')
		if (stat(input, &st) == 0)
		{
			free(copy);
			return (input);
		}
	while (tok)
	{
		len = _strlen(tok) + _strlen(input) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, input);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			return (buffer);
		}
		insertNullByte(buffer, 0);
		tok = _strtok(NULL, delim);
	}
	if (copy && *copy != ':')
		if (stat(input, &st) == 0)
		{
			free(copy);
			return (input);
		}
	free(copy);
	return (NULL);
}
