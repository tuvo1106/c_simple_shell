#include "holberton.h"

char *_getenv(char *input, char **environ)
{
	char *tok;
	char *right;
	int i = 0;

	while (environ[i])
	{
		tok = strtok(environ[i], "=");
		if (_strcmp(tok, input) == 0)
		{
			right = strtok(NULL,"=");
			return (right);
		}
		i++;
	}
	return (NULL);
}
