#include "holberton.h"

/**
 * check_path - searches $PATH for directory of command
 * @input: input command
 * @path: input $PATH
 * Return: string of full pathname if found, NULL if not
 */
char *check_path(char *input, char *path)
{
	register int len;
	static char buffer[BUFSIZE];
	char *tok, *copy = _strdup(path), *delim = ":";
	struct stat st;

	if (!stat(input, &st))
		return (input);
	tok = strtok(copy, delim);
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
		tok = strtok(NULL, delim);
	}
	free(copy);
	return (NULL);
}
