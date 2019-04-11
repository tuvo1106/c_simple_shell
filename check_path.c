#include "holberton.h"

/**
 * checkPath - searches $PATH for directory of command
 * @build->args[0]: build->args[0] command
 * @path: build->args[0] $PATH
 * Return: string of full pathname if found, NULL if not
 */
void checkPath(config *build)
{
	register int len;
	static char buffer[BUFSIZE];
	char *tok, *copy, *delim = ":";
	struct stat st;

	copy = _strdup(build->path);
	tok = _strtok(copy, delim);
	if (!copy)
	{
		build->fullPath = build->args[0];
		return;
	}
	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{

		free(copy);
		build->fullPath = build->args[0];
		return;
	}
	while (tok)
	{
		len = _strlen(tok) + _strlen(build->args[0]) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, build->args[0]);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			build->fullPath = buffer;
			return;
		}
		insertNullByte(buffer, 0);
		tok = _strtok(NULL, delim);
	}
	build->fullPath = build->args[0];
	free(copy);
}
